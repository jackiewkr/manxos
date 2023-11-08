#include <stdio.h>

#include <kernel/tty.h>

#define VERSION_MAJOR ( 0 )
#define VERSION_MINOR ( 0 )
#define VERSION_PATCH ( 1 )

static char _digit_to_char( unsigned int digit, unsigned int base )
{
        const char digits[] = "0123456789abcdef";
        return digits[ digit % base ];
}

static void kernel_introMessage( void )
{
        printf( " ManxOS ver. " );
        //TODO: implement %d in printf
        putchar( _digit_to_char( VERSION_MAJOR, 10 ) );
        putchar( '.' );
        putchar( _digit_to_char( VERSION_MINOR, 10 ) );
        putchar( '.' );
        putchar( _digit_to_char( VERSION_PATCH, 10 ) );
        putchar( '\n' );
        printf( "========\n" );
}

static void kernel_testColors( void )
{
        for ( unsigned int col = 0; col < 16; col++ )
        {
                terminal_setcolor( col );
                putchar( 'a' );
        }
}

void kernel_main( void )
{
	terminal_initialize();
	
        kernel_introMessage();
        printf( "Hello, World!\n" );
        kernel_testColors();

}
