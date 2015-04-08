    .globl _modsum     # The proc name will be _modsum.

    .text

_modsum:

    # (%esp) is now the return address.


    push    %ebp               # Backup previous base pointer.
    movl    %esp,       %ebp   # Set local base pointer.
    push    %ecx               # Backup needed registers.
    push    %esi

    movl    8(%ebp),    %ecx   # Set counter with the number of elements in the array.

    movl    12(%ebp),   %esi   # Store the address of the array into the source index.

    # Needed parameters are set. The rest of the work will use the float register's stack.

    # Let's initiate the loop.
    movl    $0,         8(%ebp) # I need a zero value to aggregate in the
                                #  register stack, and I've already loaded this
                                #  parameter.

                               # st(0)          st(1)           st(3)
    # [*1]
    flds    8(%ebp)            # 0


    # Note : Default for fmulp are st(0) & st(1). Store result in st(1), then p suffix pops st(0).

loop:

    # A = Anterior value. ( Initialized to zero back at [*1] )

                               # st(0)          st(1)           st(3)

    flds    (%esi)             # x              A
    flds    (%esi)             # x              x               A
    fmulp                      # x²             A
    flds   4(%esi)             # y              x²              A
    flds   4(%esi)             # y              y               x²             A
    fmulp                      # y²             x²              A
    faddp                      # y²+x²          A
    fsqrt                      # sqrt(y²+x²)    A
    faddp                      # sqrt(y²+x²)+A
                               #----------------------------------------------- 

    subl    $1,         %ecx   # Decrement counter.
    addl    $8,         %esi   # Switch to next couple of values,
    jnz     loop               #  and if the end was not reached yet,
                               #  jump back into the loop.


    fsts    12(%ebp)           # Store the value of st(0) as a 32 bits
                               #  float in former address of the array.
    pop     %esi               # Restore backed up registers.
    pop     %ecx
    pop     %ebp               # Restore previous base pointer.

    # (%esp) is now the return address of the procedure once again.

    ret     $4                 # Pop the return address into eip, then discards
                               #  the space used to pass the size of the array.

    # After return, flds (%esp) to retreive the result. 





