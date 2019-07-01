#include <stdlib.h>
struct Cliente{

    int Id;
    char nombre[100];
    char apellido[100];
    int edad;
    unsigned int dni;
    int ListaCreditos [3];
    float limiteCredito;
    int referidoID;
};

void ingresar();

int getCantidadCliente(struct Cliente* vCliente);

void inicializacionCredito();

void guardarEnArchivo(struct Cliente *);

void getClientes();

char * tipoCredito(int);

float limiteCredito(struct Cliente *);

struct Cliente * parsearCliente();

void buscarClientePorId();

void buscarClientePorNombre();

void buscarClientePorEdad();

void imprimirCliente(struct Cliente);

void solicitarCredito();

int menuTipoCredito();

int DeudaActual(struct Cliente *, float);

void sobrescribirArchivo(struct Cliente *);

void encontroId(int, int);

struct Cliente* cargarClientes(struct Cliente * vCliente);

void cancelarCredito();

void actualizarArchivo(int, int, struct Cliente *vCliente);

void pagarCredito();

void listarCreditos();

void iniciarDatosVectorCliente(struct Cliente* vCliente);

int buscarId(int *, int);

void Shell(struct Cliente *vCliente, int n);

void referirCliente();

void eliminarReferido();

int calcularNuevoLimiteReferido(struct Cliente);

void ordenar();

void Salir();

void menu();

