#pragma once

#include <lammy/types.hpp>
#include <lammy/thread.hpp>

/* DISPLAY WARNING: Type casts are NOT being printed */

void G_Kernel_Init(void)

{
    uint uVar1;
    undefined2* puVar2;

    SetConf(0x10, 0xc, 0x801b62f8);
    //This basically zerios all of the dat with a size of 0x58?
    puVar2 = &DAT_801c0330;
    uVar1 = 0;
    do {
        *puVar2 = 0;
        uVar1 = uVar1 + 1;
        puVar2 = puVar2 + 1;
    } while (uVar1 < 0x58);
    THREAD_ID_TABLE_ADDRESS_DAT_801c0300 = (int*)0xff000000;
    DAT_801c0330 = 1;
    THREAD_ADDRESS_TABLE_DAT_801c0334 = (int*)1;
    DAT_801b52f8 = 0x6c28382a;
    return;
}

