/****************************************************************************
*                                                                           *
* Project64-audio - A Nintendo 64 audio plugin.                             *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2017 Project64. All rights reserved.                        *
* Copyright (C) 2015 Gilles Siberlin                                        *
* Copyright (C) 2007-2009 Richard Goedeken                                  *
* Copyright (C) 2007-2008 Ebenblues                                         *
* Copyright (C) 2003 JttL                                                   *
* Copyright (C) 2002 Hacktarux                                              *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#include <Common/Util.h>
#ifdef _WIN32
#include <Project64-audio/Driver/DirectSound.h>
#else
#include <Project64-audio/Driver/OpenSLES.h>
#endif
#include "audio_1.1.h"
//#include "Version.h"
#include <stdio.h>
#include <string.h>
#include "AudioSettings.h"
#include "trace.h"
#include "AudioMain.h"
#include "ConfigUI.h"
#include "SettingsID.h"

/* Read header for type definition */
AUDIO_INFO g_AudioInfo;

bool g_PluginInit = false;
bool g_romopen = false;
uint32_t g_Dacrate = 0;

#ifdef _WIN32
DirectSoundDriver * g_SoundDriver = NULL;
#else
OpenSLESDriver * g_SoundDriver = NULL;
#endif

void PluginInit(void)
{
    if (g_PluginInit)
    {
        return;
    }
    SetupTrace();
    SetupAudioSettings();
    StartTrace();
    g_PluginInit = true;
}

EXPORT void CALL PluginLoaded(void)
{
    PluginInit();
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
}

EXPORT void CALL AiDacrateChanged(int SystemType)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start (SystemType: %d)", SystemType);
    if (!g_PluginInit)
    {
        WriteTrace(TraceAudioInterface, TraceNotice, "Plugin has not been initilized");
        WriteTrace(TraceAudioInterface, TraceDebug, "Done");
        return;
    }

    if (g_SoundDriver && g_Dacrate != *g_AudioInfo.AI_DACRATE_REG)
    {
        g_Dacrate = *g_AudioInfo.AI_DACRATE_REG & 0x00003FFF;
        if (g_Dacrate != *g_AudioInfo.AI_DACRATE_REG)
        {
            WriteTrace(TraceAudioInterface, TraceNotice, "Unknown/reserved bits in AI_DACRATE_REG set. 0x%08X", *g_AudioInfo.AI_DACRATE_REG);
        }

        uint32_t video_clock = 0;
        switch (SystemType)
        {
        case SYSTEM_NTSC: video_clock = 48681812; break;
        case SYSTEM_PAL: video_clock = 49656530; break;
        case SYSTEM_MPAL: video_clock = 48628316; break;
        }
        uint32_t Frequency = video_clock / (g_Dacrate + 1);

        if (Frequency < 4000)
        {
            WriteTrace(TraceAudioDriver, TraceDebug, "Not Audio Data!");
            return;
        }
        else
        {
            int32_t BufferSize = 0; double audio_clock = 0; double framerate = 0;

            if (g_settings->FPSBuffer() == true)
            {
                framerate = 59.94004;
                if (SystemType == SYSTEM_PAL) { framerate = 50; }
            }
            else
            {
                framerate = 64;
                if (SystemType == SYSTEM_PAL) { framerate = 53.33333; }
            }
            if (g_settings->TinyBuffer() == true)
            {
                audio_clock = ((video_clock / framerate) * 2);
            }
            else
            {
                audio_clock = ((video_clock / framerate) * 4);
            }

            BufferSize = (int32_t)audio_clock / (g_Dacrate) + 1 & ~0x1;
            g_SoundDriver->AI_SetFrequency(Frequency, BufferSize);
        }
    }
    WriteTrace(TraceAudioInterface, TraceDebug, "Done");
}

EXPORT void CALL AiLenChanged(void)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start (DRAM_ADDR = 0x%X Len = 0x%X)", *g_AudioInfo.AI_DRAM_ADDR_REG, *g_AudioInfo.AI_LEN_REG);
    if (g_SoundDriver && g_settings->AudioEnabled())
    {
        uint32_t Len = *g_AudioInfo.AI_LEN_REG & 0x3FFF8;
        uint8_t * Buffer = (g_AudioInfo.RDRAM + (*g_AudioInfo.AI_DRAM_ADDR_REG & 0x00FFFFF8));

        g_SoundDriver->AI_LenChanged(Buffer, Len);
    }
    WriteTrace(TraceAudioInterface, TraceDebug, "Done");
}

EXPORT uint32_t CALL AiReadLength(void)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start");
    uint32_t len = 0;
    if (g_SoundDriver != NULL)
    {
        *g_AudioInfo.AI_LEN_REG = g_SoundDriver->AI_ReadLength();
        len = *g_AudioInfo.AI_LEN_REG;
    }
    WriteTrace(TraceAudioInterface, TraceDebug, "Done (len: 0x%X)", len);
    return len;
}

EXPORT void CALL AiUpdate(int32_t Wait)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start (Wait: %s)", Wait ? "true" : "false");
    if (g_SoundDriver)
    {
        g_SoundDriver->AI_Update(Wait != 0);
    }
    else
    {
        pjutil::Sleep(1); // TODO:  Fixme -- Ai Update appears to be problematic
    }
    WriteTrace(TraceAudioInterface, TraceDebug, "Done");
}

EXPORT void CALL CloseDLL(void)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
    CleanupAudioSettings();
}

EXPORT void CALL DllAbout(void * /*hParent*/)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
}

EXPORT void CALL DllConfig(void * hParent)
{
#ifdef _WIN32
    ConfigAudio(hParent);
    if (g_SoundDriver)
    {
        g_SoundDriver->SetVolume(g_settings->GetVolume());
    }
#endif
}

EXPORT void CALL DllTest(void * /*hParent*/)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
}

EXPORT void CALL GetDllInfo(PLUGIN_INFO * PluginInfo)
{
    PluginInfo->Version = 0x0101;
    PluginInfo->Type = PLUGIN_TYPE_AUDIO;
#ifdef _DEBUG
    sprintf(PluginInfo->Name, "Project64 Audio Plugin (Debug): %s", "test");
#else
    sprintf(PluginInfo->Name, "Project64 Audio Plugin: %s", "test");
#endif
    PluginInfo->MemoryBswaped = true;
    PluginInfo->NormalMemory = false;
}

EXPORT int32_t CALL InitiateAudio(AUDIO_INFO Audio_Info)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start");
    if (g_SoundDriver != NULL)
    {
        g_SoundDriver->AI_Shutdown();
        delete g_SoundDriver;
    }
    g_AudioInfo = Audio_Info;
#ifdef _WIN32
    g_SoundDriver = new DirectSoundDriver;
#else
    g_SoundDriver = new OpenSLESDriver;
#endif
    WriteTrace(TraceAudioInterface, TraceDebug, "Done (res: true)");
    return true;
}

EXPORT void CALL RomOpen()
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start");
    g_romopen = true;
    g_settings->ReadSettings();
    if (g_SoundDriver)
    {
        g_SoundDriver->AI_Startup();
    }
    WriteTrace(TraceAudioInterface, TraceDebug, "Done");
}

EXPORT void CALL RomClosed(void)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Start");
    g_Dacrate = 0;
    if (g_SoundDriver)
    {
        g_SoundDriver->AI_Shutdown();
    }
    g_romopen = false;
    WriteTrace(TraceAudioInterface, TraceDebug, "Done");
}

EXPORT void CALL ProcessAList(void)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
}

extern "C" void UseUnregisteredSetting(int /*SettingID*/)
{
    WriteTrace(TraceAudioInterface, TraceDebug, "Called");
#ifdef _WIN32
    DebugBreak();
#endif
}
