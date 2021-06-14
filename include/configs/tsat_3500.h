/*
 * (C) Copyright 2013 Xilinx, Inc.
 * (C) Copyright 2015 Antmicro Ltd
 * (C) Copyright 2020 TSAT AS
 *
 * Configuration for Enclustra Mars ZX3 SOM on TSAT3500 Digital Board
 *
 * See zynq-common.h for Zynq common configs
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_TSAT_3500_H
#define __CONFIG_TSAT_3500_H

#define ENCLUSTRA_MARS_ZX
#define CONFIG_CPU_FREQ_HZ		666666666

#include <configs/zynq-common.h>
#include <configs/enclustra_zx_common.h>

#ifdef CONFIG_XILINX_OF_BOARD_DTB_ADDR
#undef CONFIG_XILINX_OF_BOARD_DTB_ADDR
#endif
#define CONFIG_XILINX_OF_BOARD_DTB_ADDR 0x2000000

#ifdef CONFIG_BOOTCOMMAND
#undef CONFIG_BOOTCOMMAND
#endif
#define CONFIG_BOOTCOMMAND        "zx_set_storage QSPI && sf probe && run qspiboot"

#ifdef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_EXTRA_ENV_SETTINGS
#endif
#define CONFIG_EXTRA_ENV_SETTINGS               \
    "bootdelay=3\0"                             \
    "fdtcontroladdr=0x2000000\0"                \
                                                \
    "fdt_high=0x20000000\0"                     \
    "initrd_high=0x20000000\0"                  \
    "env_size=" ENVIRONMENT_SIZE "\0"           \
                                                \
    "build_type=DEV\0"                          \
                                                \
    "boot_script_loadaddr=0x4000000\0"          \
    "boot_script_offset=0x0500000\0"            \
    "boot_script_size=0x40000\0"                \
    "qspiboot=sf read ${boot_script_loadaddr} ${boot_script_offset} ${boot_script_size} && source ${boot_script_loadaddr}:script-1\0"

#endif /* __CONFIG_TSAT_3500_H */
