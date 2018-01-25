/****************************************************************************
*                                                                           *
* Project64 - A Nintendo 64 emulator.                                      *
* http://www.pj64-emu.com/                                                  *
* Copyright (C) 2012 Project64. All rights reserved.                        *
*                                                                           *
* License:                                                                  *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                        *
*                                                                           *
****************************************************************************/
#pragma once
#include <Project64-core/Debugger.h>
#include <Common/SyncEvent.h>
#include <Project64-core/Settings/DebugSettings.h>

class CDumpMemory;
class CDebugMemoryView;
class CDebugMemorySearch;
class CDebugTlb;
class CDebugCommandsView;
class CDebugScripts;
class CDebugSymbols;
class CDebugDMALogView;
class CDebugStackView;
class CDebugStackTrace;

class CDMALog;
class CBreakpoints;
class CScriptSystem;

class CDebuggerUI :
    public CDebugger,
    public CDebugSettings
{
public:
    CDebuggerUI();
    ~CDebuggerUI();

public:
    void Debug_Reset(void);
    void OpenMemoryDump(void);
    void OpenMemoryWindow(void);
    void Debug_ShowMemoryLocation(uint32_t Address, bool VAddr);
    void OpenMemorySearch(void);
    void OpenTLBWindow(void);
    void Debug_RefreshTLBWindow(void);
    void OpenCommandWindow(void);
    void Debug_ShowCommandsLocation(uint32_t address, bool top);
    void OpenScriptsWindow(void);
    void Debug_LogScriptsWindow(const char* text);
    void Debug_ClearScriptsWindow(void);
    void Debug_RefreshScriptsWindow(void);
    void Debug_RefreshSymbolsWindow(void);
    void OpenSymbolsWindow(void);
    void OpenStackTraceWindow(void);
    void OpenStackViewWindow(void);
    void Debug_RefreshStackWindow(void);
    void Debug_RefreshStackTraceWindow(void);
    void OpenDMALogWindow(void);

    bool ExecutionBP(uint32_t address);
    void WaitForStep(void);

    CBreakpoints* Breakpoints();
    CDebugSymbols* Symbols();
    CScriptSystem* ScriptSystem();
    CDebugScripts* ScriptConsole();
    CDMALog* DMALog();

    static void GameReset(CDebuggerUI * _this);
    static void SteppingOpsChanged(CDebuggerUI * _this);

protected:
    void TLBChanged(void);
    void CPUStepStarted(void);
    void CPUStep(void);
    void FrameDrawn(void);

private:
    CDebuggerUI(const CDebuggerUI&);				// Disable copy constructor
    CDebuggerUI& operator=(const CDebuggerUI&);		// Disable assignment

    CDumpMemory         * m_MemoryDump;
    CDebugMemoryView    * m_MemoryView;
    CDebugMemorySearch  * m_MemorySearch;
    CDebugTlb           * m_DebugTLB;
    CDebugCommandsView  * m_CommandsView;
    CDebugScripts       * m_Scripts;
    CDebugSymbols       * m_Symbols;
    CDebugDMALogView    * m_DMALogView;
    CDebugStackTrace    * m_StackTrace;
    CDebugStackView     * m_StackView;

    CBreakpoints        * m_Breakpoints;
    CScriptSystem       * m_ScriptSystem;
    CDMALog             * m_DMALog;

    SyncEvent m_StepEvent;

};
