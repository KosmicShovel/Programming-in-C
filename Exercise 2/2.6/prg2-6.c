/* This program adds two integer values
   and displays the results             */

#define io <stdio.h>
#define i int
#define r return 0;
#define v void
#define a __asm
#define sys system
#define p "pause"
#include io

unsigned char text[] = "The sum of %i and %i is %i\n";

i main(v) {
    // Allocate variables
    i sum = -4, val1 = -8, val2 = -12;
    a{
        // Assign variables
        mov     DWORD PTR val1, 0x32
        mov     DWORD PTR val2, 0x19
        mov     eax, DWORD PTR val1

        // Add the values and set sum
        add     eax, DWORD PTR val2
        mov     DWORD PTR sum, eax

        // Load variables to registers
        mov     ecx, DWORD PTR sum
        push    ecx
        mov     edx, DWORD PTR val2
        push    edx
        mov     eax, DWORD PTR val1
        push    eax

        // Load format text
        push    OFFSET text

        // Call printf
        call    printf
        add     esp, 16
    }
    sys(p);
    r
}