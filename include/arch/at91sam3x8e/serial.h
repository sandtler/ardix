/* SPDX-License-Identifier: BSD-3-Clause */
/* See the end of this file for copyright, licensing, and warranty information. */

#pragma once

#include <ardix/serial.h>
#include <ardix/types.h>
#include <ardix/util.h>

#include <stdbool.h>

#ifndef CONFIG_ARCH_SERIAL_BUFSZ
#define CONFIG_ARCH_SERIAL_BUFSZ 32
#endif /* CONFIG_ARCH_SERIAL_BUFSZ */

struct arch_serial_buffer {
	uint16_t len;
	uint8_t data[];
};

/** Architecture-specific extension of `struct serial_interface` */
struct arch_serial_interface {
	/** should always match REG_UART_PDC_TPR */
	struct arch_serial_buffer *tx_current;
	/** should always match REG_UART_PDC_TNPR */
	struct arch_serial_buffer *tx_next;

	struct serial_interface interface;
};

/**
 * Cast a `struct serial_interface` out to a `struct arch_serial_interface`.
 *
 * @param ptr: The `struct serial_interface *` to cast out from.
 * @returns The containing `struct arch_serial_interface *`.
 */
#define to_arch_serial_interface(ptr) container_of(ptr, struct arch_serial_interface, interface)

/*
 * Copyright (c) 2020 Felix Kopp <sandtler@sandtler.club>
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted
 * provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 *    conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY
 * WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
