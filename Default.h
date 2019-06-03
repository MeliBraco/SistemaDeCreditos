#include <stdio.h>
#include <stdlib.h>

struct cliente{
    char* nombre;
    int edad;
    struct cliente *referido;
};

struct credito{
    struct cliente usuario;
    int pagado;
    int deuda;
};

