#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>
#include <stdint.h>

/* terminal_initialize()
 * =====================
 * Initializes the terminal that uses the VGA text mode buffer as the output
 * device.
 */
void terminal_initialize( void );

/* terminal_putchar()
 * ==================
 * Puts a character on the terminal buffer.
 */
void terminal_putchar( char c );

/* terminal_write()
 * ================
 * Writes a character buffer to the terminal buffer.
 */
void terminal_write( const char* data, size_t size );

/* terminal_writestring()
 * ======================
 * Writes a string literal to the terminal buffer.
 */
void terminal_writestring( const char* data );

/* terminal_setcolor()
 * ===================
 * Sets the foreground color of the terminal.
 * See vga.h for a full list of color constants.
 */
void terminal_setcolor( uint8_t color );

#endif
