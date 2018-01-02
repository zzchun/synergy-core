/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012-2016 Symless Ltd.
 * Copyright (C) 2004 Chris Schoeneman
 *
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 *
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "core/IPrimaryScreen.h"
#include "base/EventQueue.h"

#include <cstdlib>

//
// IPrimaryScreen::ButtonInfo
//

IPrimaryScreen::ButtonInfo*
IPrimaryScreen::ButtonInfo::alloc (ButtonID id, KeyModifierMask mask) {
    auto* info     = static_cast<ButtonInfo*> (malloc (sizeof (ButtonInfo)));
    info->m_button = id;
    info->m_mask   = mask;
    return info;
}

IPrimaryScreen::ButtonInfo*
IPrimaryScreen::ButtonInfo::alloc (const ButtonInfo& x) {
    auto* info     = static_cast<ButtonInfo*> (malloc (sizeof (ButtonInfo)));
    info->m_button = x.m_button;
    info->m_mask   = x.m_mask;
    return info;
}

bool
IPrimaryScreen::ButtonInfo::equal (const ButtonInfo* a, const ButtonInfo* b) {
    return (a->m_button == b->m_button && a->m_mask == b->m_mask);
}


//
// IPrimaryScreen::MotionInfo
//

IPrimaryScreen::MotionInfo*
IPrimaryScreen::MotionInfo::alloc (SInt32 x, SInt32 y) {
    auto* info = static_cast<MotionInfo*> (malloc (sizeof (MotionInfo)));
    info->m_x  = x;
    info->m_y  = y;
    return info;
}


//
// IPrimaryScreen::WheelInfo
//

IPrimaryScreen::WheelInfo*
IPrimaryScreen::WheelInfo::alloc (SInt32 xDelta, SInt32 yDelta) {
    auto* info     = static_cast<WheelInfo*> (malloc (sizeof (WheelInfo)));
    info->m_xDelta = xDelta;
    info->m_yDelta = yDelta;
    return info;
}


//
// IPrimaryScreen::HotKeyInfo
//

IPrimaryScreen::HotKeyInfo*
IPrimaryScreen::HotKeyInfo::alloc (UInt32 id) {
    auto* info = static_cast<HotKeyInfo*> (malloc (sizeof (HotKeyInfo)));
    info->m_id = id;
    return info;
}
