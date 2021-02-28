/* SPDX-License-Identifier: GPL-3.0-or-later */
/* See the end of this file for copyright, license, and warranty information. */

#pragma once

#include <toolchain.h>

/**
 * Return whether `c` is an alphabetic character.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is an alphabetic character, zero if not.
 */
int isalpha(int c);

/**
 * Return whether `c` is a control character.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a control character, zero if not.
 */
int iscntrl(int c);

/**
 * Return whether `c` is a digit.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a digit, zero if not.
 */
int isdigit(int c);

/**
 * Return whether `c` is a printable character except space.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a printable character and not space,
 *	zero if not.
 */
int isgraph(int c);

/**
 * Return whether `c` is a lowercase letter.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is lowercase, zero if not.
 */
int islower(int c);

/**
 * Return whether `c` is a printable character including space.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a printable character, zero if not.
 */
int isprint(int c);

/**
 * Return whether `c` is a printable character
 * but neither alphanumeric nor space.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a punctuation character, zero if not.
 */
int ispunct(int c);

/**
 * Return whether `c` is a white-space character.
 * These are: space, line-feed (`\n`), vertical tab (`\v`), form-feed (`\f`),
 * and carriage return (`\r`).
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a white-space character, zero if not.
 */
int isspace(int c);

/**
 * Return whether `c` is an uppercase letter.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is uppercase, zero if not.
 */
int isupper(int c);

/**
 * Return whether `c` is a hexadecimal digit.
 * This includes: 0-9, A-F and a-f.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a blaank character, zero if not.
 */
int isxdigit(int c);

/**
 * Return whether `c` is a 7-bit unsigned char.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is an ASCII character, zero if not.
 */
int isascii(int c);

/**
 * Return whether `c` is a space or a tab character.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if `c` is a blank character, zero if not.
 */
int isblank(int c);

/**
 * Check whether `c` is an alphanumeric character.
 * Equivalent to `(isalpha(c) || isdigit(c))`.
 *
 * @param c: The character, cast to an `int`.
 * @returns A nonzero value if the character is alphanumeric, zero if not.
 */
__always_inline int isalnum(int c)
{
	return isalpha(c) || isdigit(c);
}

/*
 * This file is part of Ardix.
 * Copyright (c) 2020, 2021 Felix Kopp <owo@fef.moe>.
 *
 * Ardix is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ardix is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
