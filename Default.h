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

void guardarEnArchivo(struct Cliente *);

void getClientes();

void buscarClientePorId();

void buscarClientePorNombre();

void imprimirCliente(struct Cliente);

