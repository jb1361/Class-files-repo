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

#include <Project64-core/N64System/N64Types.h>

class CDebugSettings
{
public:
    CDebugSettings();
    virtual ~CDebugSettings();

    static inline bool HaveDebugger(void) { return m_HaveDebugger; }
    static inline bool isDebugging(void) { return m_Debugging; }
    static inline bool isStepping(void) { return m_Stepping; }
    static inline bool SkipOp(void) { return m_SkipOp; }
    static inline bool WaitingForStep(void) { return m_WaitingForStep; }
    static inline bool bRecordRecompilerAsm(void) { return m_bRecordRecompilerAsm; }
    static inline bool bShowTLBMisses(void) { return m_bShowTLBMisses; }
    static inline bool bShowDivByZero(void) { return m_bShowDivByZero; }
    static inline bool bRecordExecutionTimes(void) { return m_RecordExecutionTimes; }
    static inline bool HaveExecutionBP(void) { return m_HaveExecutionBP; }

private:
    static void StaticRefreshSettings(CDebugSettings * _this)
    {
        _this->RefreshSettings();
    }

    void RefreshSettings(void);

    static bool m_HaveDebugger;
    static bool m_Debugging;
    static bool m_Stepping;
    static bool m_SkipOp;
    static bool m_WaitingForStep;
    static bool m_bRecordRecompilerAsm;
    static bool m_bShowTLBMisses;
    static bool m_bShowDivByZero;
    static bool m_RecordExecutionTimes;
    static bool m_HaveExecutionBP;

    static int32_t m_RefCount;
    static bool m_Registered;
};
