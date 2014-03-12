/*
 * drivers/input/touchscreen/pocket_detect.c
 *
 *
 * Copyright (c) 2014, Ryan Wallace <wallace.ryan10@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/init.h>
#include <linux/err.h>
#include <linux/input/doubletap2wake.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/input.h>
#include <linux/pl_sensor.h>
#ifndef CONFIG_HAS_EARLYSUSPEND
#include <linux/lcd_notify.h>
#else
#include <linux/earlysuspend.h>
#endif
#include <linux/hrtimer.h>
#include <asm-generic/cputime.h>

#define POCKET_DETECT_DEFAULT 1

int pocket_detect = POCKET_DETECT_DEFAULT;
int pocket_mode = 0;

/* Read cmdline for pocket_detect */
static int __init get_pocket_detect(char *pd)
{
	if (strcmp(pd, "1") == 0) {
		pocket_detect = 1;
	} else if (strcmp(pd, "0") == 0) {
		pocket_detect = 0;
	} else {
		pocket_detect = 1;
	}
	return 1;
}

__setup("pd=", get_pocket_detect);

int check_pocket(void) {
        if (pocket_detect == 1) {
                pocket_mode = pocket_detection_check();
                return pocket_mode;
        }
    return pocket_mode;
}