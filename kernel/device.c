/* See the end of this file for copyright, license, and warranty information. */

#include <ardix/device.h>
#include <ardix/kent.h>
#include <ardix/list.h>
#include <ardix/malloc.h>
#include <ardix/types.h>

#include <errno.h>
#include <stddef.h>

struct kent *devices_kent = NULL;

static void devices_destroy(struct kent *kent)
{
	/* should never be executed because the root devices kent is immortal */
	free(kent);
}

struct kent_ops devices_kent_ops = {
	.destroy = &devices_destroy,
};

/** Initialize the devices subsystem. */
int devices_init(void)
{
	if (devices_kent != NULL)
		return -EEXIST;

	devices_kent = malloc(sizeof(*devices_kent));
	if (devices_kent == NULL)
		return -ENOMEM;

	devices_kent->parent = kent_root;
	devices_kent->operations = &devices_kent_ops;

	return kent_init(devices_kent);
}

static void device_destroy(struct kent *kent)
{
	struct device *dev = kent_to_device(kent);
	free(dev);
}

struct kent_ops device_kent_ops = {
	.destroy = &device_destroy,
};

int device_init(struct device *dev)
{
	if (devices_kent == NULL)
		return -ENOENT;

	if (dev->kent.operations == NULL)
		dev->kent.operations = &device_kent_ops;
	if (dev->kent.parent == NULL)
		dev->kent.parent = devices_kent;

	return kent_init(&dev->kent);
}

/*
 * This file is part of Ardix.
 * Copyright (c) 2020, 2021 Felix Kopp <owo@fef.moe>.
 *
 * Ardix is non-violent software: you may only use, redistribute,
 * and/or modify it under the terms of the CNPLv6+ as found in
 * the LICENSE file in the source code root directory or at
 * <https://git.pixie.town/thufie/CNPL>.
 *
 * Ardix comes with ABSOLUTELY NO WARRANTY, to the extent
 * permitted by applicable law.  See the CNPLv6+ for details.
 */
