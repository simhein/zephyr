/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/fs/fs.h>
#include "test_common.h"
#include "test_fat_priv.h"

ZTEST(multifs_fs_dir_file, test_fat_mkdir)
{
	zassert_true(test_mkdir(TEST_DIR_PATH, TEST_FILE) == TC_PASS, NULL);
}

ZTEST(multifs_fs_dir_file, test_fat_readdir)
{
	zassert_true(test_lsdir(TEST_DIR_PATH) == TC_PASS, NULL);
}

ZTEST(multifs_fs_dir_file, test_fat_rmdir)
{
	zassert_true(test_rmdir(TEST_DIR_PATH) == TC_PASS, NULL);
}
