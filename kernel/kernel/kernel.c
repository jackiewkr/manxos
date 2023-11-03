#include <stdio.h>

#include <kernel/tty.h>

#define VERSION_MAJOR ( 0 )
#define VERSION_MINOR ( 0 )
#define VERSION_PATCH ( 1 )

void kernel_introMessage( void )
{
        printf( " ManxOS ver. %i.%i.%i\n", VERSION_MAJOR, VERSION_MINOR, 
                VERSION_PATCH );
        printf( "========\n" );
}

void kernel_main( void )
{
	terminal_initialize();
	
        kernel_introMessage();
        printf( "Hello, World!\n" );

}
