# Declare constants for the multiboot header.
.set ALIGN,    1<<0             # align loaded modules on page boundaries
.set MEMINFO,  1<<1             # provide memory map
.set FLAGS,    ALIGN | MEMINFO  # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002       # 'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS) # checksum of above, to prove we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# Reserve memory space
.section .bss
.align 16
# Reserve space for GDT
gdt:
gdt_null:
.zero 8 # null descriptor 8 bytes
gdt_code:
# code segment
gdt_data:
.skip 8 # data segment
gdt_end:

# Reserve 1 page for page directory
page_directory:
.skip 4096
# Reserve 1 page for a page table
page_table1:
.skip 4096
# Reserve 16 KiB for stack
stack_bottom:
.skip 16384
stack_top:

# The kernel entry point.
.section .text
.global _start
.type _start, @function
_start:
        # Set page dir to %ecx
        movl $page_directory, %ecx
        movl %ecx, %cr3

        # enable paging bit
        movl %cr0, %ecx
        orl 0x80000001, %ecx
        movl %ecx, %cr0

        # Move to stack top and setup kernel
	movl $stack_top, %esp

	# Call the global constructors.
	call _init

	# Transfer control to the main kernel.
	call kernel_main

	# Hang if kernel_main unexpectedly returns.
	cli
1:	hlt
	jmp 1b
.size _start, . - _start
