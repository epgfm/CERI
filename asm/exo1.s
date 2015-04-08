    .globl _aggr     # The proc name will be _aggr.

    .text

_aggr:

    # (%esp) is now the return address.

    push    %ebp               # Backup previous base pointer.
    movl    %esp,       %ebp   # Set local base pointer.
    push    %eax               # Backup all needed registers.
    push    %ebx               #
    push    %ecx               #
    push    %edx               #
    push    %edi               #

    movw    8(%ebp),    %bx    # Get Second parameter from the stack into ebx.
    movw    12(%ebp),   %cx    # Get First parameter from the stack into ecx.
                               #  Register ecx is the logic choice because we'll sum up to the parameter's value.

    movl    $0,        %edi    # Init edi to zero. We'll use it as the aggregator.

    # Let's calculate a-b one time, and we'll leave it into ebx.

    movw    %cx,       %ax    # Because we don't want to touch cx. a now in ax.
    subw    %bx,       %ax    # a -> a-b But we want it into b's register.
    movw    %ax,       %bx    #  because eax will be modified by the div.

    # Alright, the divisor is set into bx.
    # Time to start the loop.

loop:

    movw    $0,        %dx    # Clear dx wich may hold a remainder.
    movw    %cx,       %ax    # Load the numerator.
    
    idivw   %bx               # dx:ax / a-b -> ax (q) && dx (r)
                              # Signed version.
    addl    %eax,       %edi  # Aggregate the quotient. ( Result will be over
                              #  32 bits to take the probable carry 
                              #  into account)

    subw    $1,         %cx   # Decrement counter.

    jnz loop                  # While zero hasn't been reached, jump back into the loop.

    # Zero reached. End Sequence :

    movl    %edi,      12(%ebp) # Overwrite first parameter in the stack with the result.

    pop     %edi                # Restore backed up registers.
    pop     %edx                #
    pop     %ecx                #
    pop     %ebx                #
    pop     %eax                #

    pop     %ebp                # Restore previous base pointer.

    # Register %esp Now points to the return address again.

    ret     $4      # Pop the return address into eip, and discard the second parameter.

    # Upon return to caller the last value in the stack is now the result.
    # Pop to retreive.








