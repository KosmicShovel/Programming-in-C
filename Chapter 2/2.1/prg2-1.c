﻿#define io <stdio.h>
#define i int
#define r return 0;
#define v void
#define a __asm
#define sys system
#define p "pause"
#include io

unsigned char text[] = "Programming is fun.\n";

i main(v) {
    a{
        push    OFFSET text
        call    printf
        add     esp, 4
    }
    sys(p);
    r
}