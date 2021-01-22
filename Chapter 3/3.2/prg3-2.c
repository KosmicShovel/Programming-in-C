#define io <stdio.h>
#define i int
#define r return 0;
#define v void
#define asm __asm
#define sys system
#define p "pause"
#include io

unsigned char text1[] = "a - b = %i\n";
unsigned char text2[] = "b * c = %i\n";
unsigned char text3[] = "a / c = %i\n";
unsigned char text4[] = "a + b * c = %i\n";
unsigned char text5[] = "a * b + c * d = %i\n";

i main(v) {
    int a = 100, b = 2, c = 25, d = 4;
    asm{
        mov eax, a
        sub eax, b // Subtraction
        push eax
        push OFFSET text1
        call printf
        add esp, 8

        mov eax, b
        imul eax, c // Multiplication
        push eax
        push OFFSET text2
        call printf
        add esp, 8

        mov eax, a
        cdq
        idiv c // Division
        push eax
        push OFFSET text3
        call printf
        add esp, 8

        mov eax, b
        imul eax, c // Precedence
        add eax, a
        push eax
        push OFFSET text4
        call printf
        add esp, 8

        mov eax, a
        imul eax, b
        mov ecx, c
        imul ecx, d
        add eax,ecx
        push eax
        push OFFSET text5
        call printf
        add esp, 8
    }
    sys(p);
    r
}