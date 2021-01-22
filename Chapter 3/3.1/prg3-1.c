#define io <stdio.h>
#define i int
#define r return 0;
#define v void
#define a __asm
#define sys system
#define p "pause"
#include io

unsigned char text1[] = "integerVar = %i\n";
unsigned char text2[] = "floatingVar = %f\n";
unsigned char text3a[] = "doubleVar = %e\n";
unsigned char text3b[] = "doubleVar = %g\n";
unsigned char text4[] = "charVar = %c\n";
unsigned char text5[] = "boolVar = %i\n";

i main(v) {
    int       integerVar = 0xFFFFFFFFFFFFFFF8;
    float     floatingVar = 331.79f;
    double    doubleVar = 8.44e+11;
    char      charVar = 0xFFFFFFFFFFFFFFFE;
    _Bool     boolVar = 0xFFFFFFFFFFFFFFFE;

    a{
        // Loading 32-bit values
        mov DWORD PTR integerVar, 0x64
        // Loading 8-bit values
        mov BYTE PTR charVar, 87
        mov BYTE PTR boolVar, 0
    }
    printf(text1, integerVar);
    printf(text2, floatingVar);
    printf(text3a, doubleVar);
    printf(text3b, doubleVar);
    printf(text4, charVar);
    printf(text5, boolVar);
    sys(p);
    r
}