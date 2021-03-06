/* See the end of this file for copyright, license, and warranty information. */

#pragma once

/**
 * Perform a syscall.
 *
 * This is the first and only method called by the irq handler for system calls.
 * It is responsible for finishing the context switch, obtaining the syscall
 * number and arguments, and invoking the respective system call.
 *
 * @param sp: The current stack pointer.
 */
void arch_enter(void *sp);

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
