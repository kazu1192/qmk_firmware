/* Copyright 2015-2021 Jack Humbert
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

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(STARTUP_SOUND)
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// RGB lighting
#define RGBLIGHT_SLEEP
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_LAYERS
#define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_STATIC_LIGHT
#define RGBLIGHT_DEFAULT_HUE 0
#define RGBLIGHT_DEFAULT_SAT 0
#define RGBLIGHT_DEFAULT_VAL 128

// MOUSEKEY
#define MOUSEKEY_DELAY 10
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 5
#define MOUSEKEY_TIME_TO_MAX 12
#define MOUSEKEY_WHEEL_DELAY 300
#define MOUSEKEY_WHEEL_INTERVAL 100
#define MOUSEKEY_WHEEL_MAX_SPEED 8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
