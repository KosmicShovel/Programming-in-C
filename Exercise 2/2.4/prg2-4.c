#define io <stdio.h>
#define i int
#define r return 0;
#define v void
#define a __asm
#define sys system
#define p "pause"
#include io

unsigned char text[] = "The sum of 50 and 25 is %i\n";

i main(v) {
    i sum = -4;
    a{
        mov     DWORD PTR sum, 0x32
        add     DWORD PTR sum, 0x19

        mov     eax, DWORD PTR sum
        push    eax

        push    OFFSET text

        call    printf
        add     esp, 8
    }
    sys(p);
    r
}