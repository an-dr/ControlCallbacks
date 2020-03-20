// *************************************************************************
//
// Copyright (c) 2020 Andrei Gramakov. All rights reserved.
//
// This file is licensed under the terms of the MIT license.
// For a copy, see: https://opensource.org/licenses/MIT
//
// site:    https://agramakov.me
// e-mail:  mail@agramakov.me
//
// *************************************************************************

#include "ControlCallbacks.h"

ControlCallbacks::ControlCallbacks(Connection_t *conns, uint32_t con_num)
    : connections(conns), Connections_n(con_num) {}

int ControlCallbacks::Exec(uint32_t cmd) {
    printf("[ControlCallbacks] got %d\n", cmd);
    for (int i = 0; i < Connections_n; ++i) {
        if (cmd == connections[i].cmd_code) {
            connections[i].func();
            return 0;
        }
    }
    return -1;
}
