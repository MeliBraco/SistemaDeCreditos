#include <stdlib.h>

struct Cliente{

    char nombre[100];

    char apellido[100];

    int edad;

    int Id;

    unsigned int dni;

    unsigned int credito;

    struct Cliente * refCliente;
};

void ingresar();

void FilePathGuardar(struct Cliente *);

void guardar(struct Cliente *, FILE *);

void getFicheros();

void getClientes(char [50]);

void buscarClientePorId();

void imprimirCliente(struct Cliente);