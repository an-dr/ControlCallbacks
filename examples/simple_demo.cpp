#include <iostream>
#include <cstdint>
#include "ControlCallbacks.h"

void EchoA(void) {
    printf("%s\n", __func__);
}

void EchoB(void) {
    printf("%s\n", __func__);
}

void EchoC(void) {
    printf("%s\n", __func__);
}

int main() {
    Connection_t connection[] = {
            {.cmd_code=1, .func=EchoA},
            {.cmd_code=2, .func=EchoB},
            {.cmd_code=0xfe000001, .func=EchoC},
    };
    ControlCallbacks Cc(connection, sizeof(connection) / sizeof(connection[0]));

    uint32_t cmds[] = {1,2,0xfe000001,0};
    uint32_t ret;
    for (int i = 0; i < sizeof(cmds)/ sizeof(cmds[0]); ++i) {
        ret = Cc.Exec(cmds[i]);
        if (!ret){
            printf("[ DONE ]\n");
        } else {
            printf("[ ERROR ] : %d\n", ret);
        }
    }
    return 0;
}
