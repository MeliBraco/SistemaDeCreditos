#include <stdlib.h>

struct Cliente{

    int Id;

    char nombre[100];

    char apellido[100];

    int edad;

    unsigned int dni;

    int ListaCreditos [3];

    float limiteCredito;

    struct Cliente * refCliente;
};


void ingresar();

void inicializacionCredito();

void guardarEnArchivo(struct Cliente *);

void getClientes();

char * tipoCredito(int);

float limiteCredito(struct Cliente *);

struct Cliente * parsearCliente();

void buscarClientePorId();

void buscarClientePorNombre();

void imprimirCliente(struct Cliente);

void solicitarCredito();

int menuTipoCredito();

int DeudaActual(struct Cliente *, float);

void sobrescribirArchivo(struct Cliente *);

void exepcionId(int, int);