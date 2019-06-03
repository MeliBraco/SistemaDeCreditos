#include <stdio.h>
#include <stdlib.h>

struct Cliente{

    char nombre[100];

    char apellido[100];

    int edad;

    int Id;

    unsigned int dni;

    struct Cliente * refCliente;
};

void ingresar();

void FilePath(struct Cliente *);

void guardar(struct Cliente *, FILE *);
