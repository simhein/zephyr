/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/fs/fs.h>
#include "test_common.h"
#include "test_littlefs_priv.h"

static struct fs_file_t test_file;
static const char *test_str = "Hello world LITTLEFS";

ZTEST(multifs_fs_dir_file, test_littlefs_open)
{
	fs_file_t_init(&test_file);
	zassert_true(test_file_open(&test_file, TEST_FILE_PATH) == TC_PASS,
		NULL);
}

ZTEST(multifs_fs_dir_file, test_littlefs_write_read)
{
	TC_PRINT("Write to file %s and read from it\n", TEST_FILE_PATH);
	zassert_true(test_file_write_read(&test_file, test_str) == TC_PASS,
		NULL);
}

ZTEST(multifs_fs_dir_file, test_littlefs_close)
{
	zassert_true(test_file_close(&test_file) == TC_PASS, NULL);
}
ZTEST(multifs_fs_dir_file, test_littlefs_unlink)
{
	zassert_true(test_file_delete(TEST_FILE_PATH) == TC_PASS, NULL);
}
