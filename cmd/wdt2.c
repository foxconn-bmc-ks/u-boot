/* ***********************************************************
*                                                            *
*   Copyright (C) Microsoft Corporation. All rights reserved.*
*                                                            *
************************************************************ */

#include <common.h>
#include <command.h>
#include <asm/io.h>

void wdt2_disable()
{
    u32 reg;
    reg = readl(AST_WDT_BASE + 0x2c);
    reg &= 0xFFFFFFFE;
    writel(reg, AST_WDT_BASE + 0x2c);
}

int do_wdt2_disable(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
    if (argc != 2)
        return CMD_RET_USAGE;
    if (argv[1][0] == '0')
        wdt2_disable();
    else
         return CMD_RET_USAGE;

	return 0;
}

/**************************************************/
U_BOOT_CMD(wdt2, 2, 0, do_wdt2_disable,
	   "Disable WDT2", "0");
