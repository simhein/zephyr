/*
 * Copyright (c) 2018 Codecoup
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <ztest.h>
#include "test_common.h"
#include "test_fs_shell.h"
#include "test_fat.h"
#include "test_littlefs.h"

void *fs_mount_setup(void)
{
	int err;
	err = fat_mount_setup();
	zassert_true(err == 0, "fat_fs_mount setup call failure: %d", err);

	err = littlefs_mount_setup();
	zassert_true(err == 0, "littlefs_fs_mount setup call failure: %d", err);
	return NULL;
}

void fs_unmount_teardown(void *data)
{
	ARG_UNUSED(data);
	int err;

	err = fat_unmount_teardown();
	zassert_true(err == 0, "fat_fs_unmount teardown call failure: %d", err);

	err = littlefs_unmount_teardown();
	zassert_true(err == 0, "littlefs_fs_unmount teardown call failure: %d", err);
}

ZTEST_SUITE(multifs_fs_dir_file, NULL, fs_mount_setup, NULL, NULL, fs_unmount_teardown);
ZTEST_SUITE(multifs_fs, NULL, NULL, NULL, NULL, fs_unmount_teardown);
