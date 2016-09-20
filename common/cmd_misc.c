/*
 * (C) Copyright 2001
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * Misc functions
 */
#include <common.h>
#include <command.h>

#if (CONFIG_COMMANDS & CFG_CMD_MISC)
#ifdef RT2880_U_BOOT_CMD_OPEN

int do_sleep (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	ulong delay;

	if (argc != 2) {
		printf ("Usage:\n%s\n", cmdtp->usage);
		return 1;
	}

	delay = simple_strtoul(argv[1], NULL, 10);

	while (delay) {
		int i;
		for (i=0; i<1000; ++i) {
			if (ctrlc ()) {
				return (-1);
			}
			udelay (1000);
		}
		--delay;
	}
	return 0;
}
#endif
/* Implemented in $(CPU)/interrupts.c */
#if (CONFIG_COMMANDS & CFG_CMD_IRQ)
int do_irqinfo (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]);

U_BOOT_CMD(
	irqinfo,    1,    1,     do_irqinfo,
	"irqinfo - print information about IRQs\n",
	NULL
);
#endif  /* CONFIG_COMMANDS & CFG_CMD_IRQ */
#ifdef RT2880_U_BOOT_CMD_OPEN

U_BOOT_CMD(
	sleep ,    2,    2,     do_sleep,
	"sleep   - delay execution for some time\n",
	"N\n"
	"    - delay execution for N seconds (N is _decimal_ !!!)\n"
);
#endif
#endif	/* CFG_CMD_MISC */
