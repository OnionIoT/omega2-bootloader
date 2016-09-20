/*
 * (C) Copyright 2000
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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include "../autoconf.h"

/*
 * Operating System Codes
 */
#define IH_OS_INVALID		0	/* Invalid OS	*/
#define IH_OS_OPENBSD		1	/* OpenBSD	*/
#define IH_OS_NETBSD		2	/* NetBSD	*/
#define IH_OS_FREEBSD		3	/* FreeBSD	*/
#define IH_OS_4_4BSD		4	/* 4.4BSD	*/
#define IH_OS_LINUX		5	/* Linux	*/
#define IH_OS_SVR4		6	/* SVR4		*/
#define IH_OS_ESIX		7	/* Esix		*/
#define IH_OS_SOLARIS		8	/* Solaris	*/
#define IH_OS_IRIX		9	/* Irix		*/
#define IH_OS_SCO		10	/* SCO		*/
#define IH_OS_DELL		11	/* Dell		*/
#define IH_OS_NCR		12	/* NCR		*/
#define IH_OS_LYNXOS		13	/* LynxOS	*/
#define IH_OS_VXWORKS		14	/* VxWorks	*/
#define IH_OS_PSOS		15	/* pSOS		*/
#define IH_OS_QNX		16	/* QNX		*/
#define IH_OS_U_BOOT		17	/* Firmware	*/
#define IH_OS_RTEMS		18	/* RTEMS	*/
#define IH_OS_ARTOS		19	/* ARTOS	*/
#define IH_OS_UNITY		20	/* Unity OS	*/

/*
 * CPU Architecture Codes (supported by Linux)
 */
#define IH_CPU_INVALID		0	/* Invalid CPU	*/
#define IH_CPU_ALPHA		1	/* Alpha	*/
#define IH_CPU_ARM		2	/* ARM		*/
#define IH_CPU_I386		3	/* Intel x86	*/
#define IH_CPU_IA64		4	/* IA64		*/
#define IH_CPU_MIPS		5	/* MIPS		*/
#define IH_CPU_MIPS64		6	/* MIPS	 64 Bit */
#define IH_CPU_PPC		7	/* PowerPC	*/
#define IH_CPU_S390		8	/* IBM S390	*/
#define IH_CPU_SH		9	/* SuperH	*/
#define IH_CPU_SPARC		10	/* Sparc	*/
#define IH_CPU_SPARC64		11	/* Sparc 64 Bit */
#define IH_CPU_M68K		12	/* M68K		*/
#define IH_CPU_NIOS		13	/* Nios-32	*/
#define IH_CPU_MICROBLAZE	14	/* MicroBlaze   */
#define IH_CPU_NIOS2		15	/* Nios-II	*/

/*
 * Image Types
 *
 * "Standalone Programs" are directly runnable in the environment
 *	provided by U-Boot; it is expected that (if they behave
 *	well) you can continue to work in U-Boot after return from
 *	the Standalone Program.
 * "OS Kernel Images" are usually images of some Embedded OS which
 *	will take over control completely. Usually these programs
 *	will install their own set of exception handlers, device
 *	drivers, set up the MMU, etc. - this means, that you cannot
 *	expect to re-enter U-Boot except by resetting the CPU.
 * "RAMDisk Images" are more or less just data blocks, and their
 *	parameters (address, size) are passed to an OS kernel that is
 *	being started.
 * "Multi-File Images" contain several images, typically an OS
 *	(Linux) kernel image and one or more data images like
 *	RAMDisks. This construct is useful for instance when you want
 *	to boot over the network using BOOTP etc., where the boot
 *	server provides just a single image file, but you want to get
 *	for instance an OS kernel and a RAMDisk image.
 *
 *	"Multi-File Images" start with a list of image sizes, each
 *	image size (in bytes) specified by an "uint32_t" in network
 *	byte order. This list is terminated by an "(uint32_t)0".
 *	Immediately after the terminating 0 follow the images, one by
 *	one, all aligned on "uint32_t" boundaries (size rounded up to
 *	a multiple of 4 bytes - except for the last file).
 *
 * "Firmware Images" are binary images containing firmware (like
 *	U-Boot or FPGA images) which usually will be programmed to
 *	flash memory.
 *
 * "Script files" are command sequences that will be executed by
 *	U-Boot's command interpreter; this feature is especially
 *	useful when you configure U-Boot to use a real shell (hush)
 *	as command interpreter (=> Shell Scripts).
 */

#define IH_TYPE_INVALID		0	/* Invalid Image		*/
#define IH_TYPE_STANDALONE	1	/* Standalone Program		*/
#define IH_TYPE_KERNEL		2	/* OS Kernel Image		*/
#define IH_TYPE_RAMDISK		3	/* RAMDisk Image		*/
#define IH_TYPE_MULTI		4	/* Multi-File Image		*/
#define IH_TYPE_FIRMWARE	5	/* Firmware Image		*/
#define IH_TYPE_SCRIPT		6	/* Script file			*/
#define IH_TYPE_FILESYSTEM	7	/* Filesystem Image (any type)	*/

/*
 * Compression Types
 */
#define IH_COMP_NONE		0	/*  No	 Compression Used	*/
#define IH_COMP_GZIP		1	/* gzip	 Compression Used	*/
#define IH_COMP_BZIP2		2	/* bzip2 Compression Used	*/
#define IH_COMP_LZMA		3	/* lzma  Compression Used	*/
#define IH_COMP_XZ		5	/* xz    Compression Used	*/

#define IH_MAGIC	0x27051956	/* Image Magic Number		*/

#if defined (MT7621_ASIC_BOARD) || defined (MT7621_FPGA_BOARD)
#if defined (ON_BOARD_NAND_FLASH_COMPONENT)
#define IH_NMLEN		(16-4)
#else
#define IH_NMLEN        (16)
#endif
#elif defined (MT7620_ASIC_BOARD) || defined (MT7620_FPGA_BOARD) || defined (MT7628_ASIC_BOARD) || defined (MT7628_FPGA_BOARD)
#define IH_NMLEN		(16-4*2)	/* Image Name Length		*/
#elif defined (RT6855A_ASIC_BOARD) || defined (RT6855A_FPGA_BOARD)
#define IH_NMLEN		(16-4*4)
#else
#define IH_NMLEN		16	/* Image Name Length		*/
#endif
/*
 * all data in network byte order (aka natural aka bigendian)
 */


typedef struct dram_header {
#if defined(MT7620_ASIC_BOARD) || defined(MT7620_FPGA_BOARD) || defined(MT7628_ASIC_BOARD) || defined(MT7628_FPGA_BOARD)
	uint16_t	ddr_self_refresh;
	uint16_t	ddr_cfg11;
	uint32_t	ddr_cfg10;
#endif
#if defined (RT6855A_ASIC_BOARD) || defined (RT6855A_FPGA_BOARD)
	uint32_t	dram_pad_setting;
	uint32_t	ddr_cfg2;
	uint32_t	ddr_cfg3;
	uint32_t	ddr_cfg4;
#endif
	uint8_t		dram_parm;	/* DRAM setting */
	union{
	uint8_t		dram_magic;	/* Magic number of DRAM setting (0x5a) */
	struct {
		uint8_t	cpu_pll_magic_l:4;	
		uint8_t	dram_magic_h:4;
		}u;
	};
	uint16_t	cpu_pll_cfg;
#if defined(RT3052_ASIC_BOARD) || defined(RT3052_FPGA_BOARD) ||\
	defined(RT3352_ASIC_BOARD) || defined(RT3352_FPGA_BOARD) ||\
	defined(RT5350_ASIC_BOARD) || defined(RT5350_FPGA_BOARD) ||\
	defined(RT3883_ASIC_BOARD) || defined(RT3883_FPGA_BOARD)
	uint16_t	magic_lh;       /* low half word of magic number 0x5244 */
	uint16_t	magic_hh;       /* high half word of magic number 0x4D41 */
	union {
	    struct {
		uint8_t syscfg1;
		uint8_t ddr_cfg3;
		uint16_t resv1;
		uint32_t resv2;
	    }ddr;
	    
	    struct {
		uint32_t sdram_cfg0;
		uint32_t sdram_cfg1;
	    }sdr;
	};
#else
	uint8_t		magic;       /* magic number 0x68 */
#if defined (RT6855A_ASIC_BOARD) || defined (RT6855A_FPGA_BOARD)
	uint8_t		rsvd0[3];
#else
	uint8_t		reservd;
	uint16_t	syscfg1_ddrcfg3_odt;
#endif	
	union {
		struct {
		uint32_t ddr_cfg0;
		uint32_t ddr_cfg1;
		}ddr;		
		struct {
		uint32_t sdram_cfg0;
		uint32_t sdram_cfg1;
		}sdr;
	};
#endif
} dram_header_t __attribute__ ((packed));

typedef struct  nand_badblock_info1_type {
	uint32_t	ecc_bits	:	3;
	uint32_t	rsvd		:	5;
	uint32_t	ecc_offset	:	8;
	uint32_t	bad_block_offser	:	8;
	uint32_t	checksum	:	8;
} nand_badblock_info1_t __attribute__ ((packed));

typedef struct  nand_info_1_type {	
	uint32_t	pagesize 	: 2;
	uint32_t	rsvd0		: 2;	
	uint32_t	addr_cycle 	: 2;
	uint32_t	rsvd1		: 2;	
	uint32_t	spare_size	: 2;
	uint32_t	rsvd2		: 2;	
	uint32_t	total_size	: 3;
	uint32_t	rsvd3		: 1;
	uint32_t	block_size	: 2;
	uint32_t	rsvd4		: 2;	
	uint32_t	magic_id	: 12;	
} nand_info_1_t __attribute__ ((packed));

	
typedef struct nand_header {
	uint32_t			nand_ac_timing;
	uint32_t				ih_stage_offset;			/* stage1 offset */
	uint32_t				ih_bootloader_offset;		/* bootloader offset */
	union 
	{
	nand_info_1_t			nand_info_1;
		uint32_t				nand_info_1_data;
	};
	//nand_badblock_info1_t	nand_badblock_info1;
	uint32_t				crc;
} nand_header_t __attribute__ ((packed));

typedef struct image_header {
	uint32_t	ih_magic;	/* Image Header Magic Number	*/
	uint32_t	ih_hcrc;	/* Image Header CRC Checksum	*/
	uint32_t	ih_time;	/* Image Creation Timestamp	*/
	uint32_t	ih_size;	/* Image Data Size		*/
	uint32_t	ih_load;	/* Data	 Load  Address		*/
	uint32_t	ih_ep;		/* Entry Point Address		*/
	uint32_t	ih_dcrc;	/* Image Data CRC Checksum	*/
	uint8_t		ih_os;		/* Operating System		*/
	uint8_t		ih_arch;	/* CPU architecture		*/
	uint8_t		ih_type;	/* Image Type			*/
	uint8_t		ih_comp;	/* Compression Type		*/
	uint8_t		ih_name[IH_NMLEN];	/* Image Name		*/
#if defined (MT7621_ASIC_BOARD) || defined (MT7621_FPGA_BOARD)
	nand_header_t	ih_nand;
#else
	dram_header_t   ih_dram;
#endif	
} image_header_t __attribute__((packed));


#endif	/* __IMAGE_H__ */
