/* Copyright 2019 dsanchezseco
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// place overrides here

// The left half is the one that connects to the computer§
#define MASTER_LEFT
//#define MASTER_RIGHT
// Both halves can be connected to the computer
// but both must be flashed using dfu-split-left or df-split-right
//#define EE_HANDS

#define TAPPING_FORCE_HOLD
// Time to consider a "tap" a "hold" instead
#define TAPPING_TERM 200
