/* ***********************************************************
*                                                            *
*   Copyright (C) Microsoft Corporation. All rights reserved.*
*                                                            *
************************************************************ */

#include <common.h>
#include <command.h>

int do_wdt2_disable(cmd_tbl_t *cmdtp, int flag, int argc, char *const argv[])
{
    if (argc != 2)
        return CMD_RET_USAGE;
    if (argv[1][0] == '0')
        *((volatile ulong *)0x1e78502c) = 0;
    else
         return CMD_RET_USAGE;

	return 0;
}

/**************************************************/
U_BOOT_CMD(wdt2, 2, 0, do_wdt2_disable,
	   "Disable WDT2", "0");
