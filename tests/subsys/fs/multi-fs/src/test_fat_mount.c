/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ff.h>
#include "test_common.h"
#include "test_fs_shell.h"
#include "test_fat.h"
#include "test_fat_priv.h"

/* for mount using FS api */
#if !defined(CONFIG_FILE_SYSTEM_SHELL)
/* FatFs work area */
static FATFS fat_fs;

/* mounting info */
static struct fs_mount_t fatfs_mnt = {
	.type = FS_FATFS,
	.mnt_point = FATFS_MNTP,
	.fs_data = &fat_fs,
};

static int test_mount(void)
{
	int res;

	res = fs_mount(&fatfs_mnt);
	if (res < 0) {
		TC_PRINT("Error mounting fs [%d]\n", res);
		return TC_FAIL;
	}

	return TC_PASS;
}

int fat_mount_setup(void)
{
	int res;

	res = fs_mount(&fatfs_mnt);
	return res;
}

int fat_unmount_teardown(void)
{
	int res;

	res = fs_unmount(&fatfs_mnt);
	return res;
}
#endif

ZTEST(multifs_fs, test_fat_mount)
{
#ifdef CONFIG_FILE_SYSTEM_SHELL
	test_fs_fat_mount();
#else
	zassert_true(test_mount() == TC_PASS, NULL);
#endif
}
