        .globl mirror

        .text

mirror:

    push    %ebp                # Backup Base pointer.
    movl    %esp,       %ebp    # Set local base pointer.
                                # Backup needed registers.
    push    %esi
    push    %edi

    movl    8(%ebp),    %esi    # Address of source string (first param) -> esi.
    movl    $0,         %ecx    # Initialize counter.
    subl    $1,         %esi    # Move back esi of one char. (Will be undone.)

go_end:

    addl    $1,         %esi    # See, what did I say?
    addl    $1,         %ecx    # Increment counter.
    cmpb    $0,         (%esi)  # Check if we've reached the end-of-string char.
    jne     go_end              # Jump back while we haven't.

    movl    %esi,       %edi    # Dest index is now on the end-of-string char.
    subl    $2,         %esi    # Move back esi to the letter before the last.
    subl    $2,         %ecx    # Update counter accordingly.

revcopy:

    movb    (%esi),     %al
    movb    %al,        (%edi)  # First tour in this loop overwrite the EOS.
    subl    $1,         %esi    # Switch source back one letter.
    addl    $1,         %edi    # Switch dest forth one letter.
    subl    $1,         %ecx    # Decrement counter.
    jnz     revcopy             # Go back while there's characters to copy.    

    movb    $0,         (%edi)  # Place a new EOS char at the end.

    pop     %edi                # Restore all backed up registers.
    pop     %esi
    pop     %ebp

    ret

