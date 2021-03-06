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

#pragma once
#include <stdint.h>
#include <stdio.h>

#define CMD_NONE (-1U)
#define CMD_DONE (0)

typedef void (*callback_t)(void);

typedef struct {
    uint32_t cmd_code;
    callback_t func;
} Connection_t;

class ControlCallbacks {
public:
    ControlCallbacks() = default;
    ControlCallbacks(Connection_t *conns, uint32_t con_num);
    void Init(Connection_t *conns, uint32_t con_num);
    void Poll(void);
    int Exec(uint32_t cmd);

private:
    Connection_t *connections;
    uint32_t Connections_n;
};
