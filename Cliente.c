#include <stdio.h>
#include "Default.h"
#include <string.h>
#include <stdlib.h>


void ingresar(){

    struct Cliente nuevoCliente;

    char nombreAux[100];

    char apellidoAux[100];

    printf("Ingresar Id:\n");
    scanf("%d", &nuevoCliente.Id);

    printf("Ingresar Apellido:\n");
    scanf("%s", apellidoAux);

    printf("Ingresar Nombre:\n");
    scanf("%s", nombreAux);

    printf("Ingresar edad:\n");
    scanf("%d", &nuevoCliente.edad);

    printf("Ingresar dni:\n");
    scanf("%d", &nuevoCliente.dni);

    strcpy(nuevoCliente.apellido, apellidoAux);

    strcpy(nuevoCliente.nombre, nombreAux);

    inicializacionCredito(&nuevoCliente);

    nuevoCliente.limiteCredito = limiteCredito(&nuevoCliente);

    guardarEnArchivo(&nuevoCliente);

    printf("El Empleado fue ingresado correctamente \n\n");
}

struct Cliente* cargarClientes(struct Cliente* vCliente){

    FILE *archivo = fopen("Archivo1.csv", "rt");

    char linea[100];

    char *token;

    int longitud = 0;

    while(!feof(archivo))
    {
        fgets(linea,100, archivo);

        token = strtok(linea, ",");
        if(*token != 10) {
            vCliente[longitud].Id = atoi(token);

            token = strtok(NULL, ",");
            strcpy(vCliente[longitud].nombre, token);

            token = strtok(NULL, ",");
            strcpy(vCliente[longitud].apellido, token);

            token = strtok(NULL, ",");
            vCliente[longitud].edad = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].dni = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].limiteCredito = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[0] = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[1] = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[2] = atoi(token);

            longitud++;
        }
    }
    fclose(archivo);
}

int getCantidadCliente(struct Cliente* vCliente){

    FILE *archivo = fopen("Archivo1.csv", "rt");

    char linea[100];

    char *token;

    int longitud = 0;

    while(!feof(archivo))
    {
        fgets(linea,100, archivo);

        token = strtok(linea,",");

        if(*token != 10)
        {
            vCliente[longitud].Id = atoi(token);

            longitud++;
        }
    }
    fclose(archivo);

    return longitud;
}

void getClientes()
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    for(int i = 0; i<longitud; i++)
    {
        imprimirCliente(vCliente[i]);

    }
}

void imprimirCliente(struct Cliente aImprimir){

    if(aImprimir.Id != 0)
    {
        printf("-ID = %d \n", aImprimir.Id);
        printf("-Apellido = %s \n", aImprimir.apellido);
        printf("-Nombre = %s \n", aImprimir.nombre);
        printf("-Edad = %d \n", aImprimir.edad);
        printf("-DNI = %d \n", aImprimir.dni);
        printf("-LIMITE DE CREDITO DISPONIBLE = %f \n", aImprimir.limiteCredito);

        for (int i = 0; i < 3; i++) {

            if (aImprimir.ListaCreditos[i] != 0) {

                printf("-%d)%s ----> monto $%d \n",i+1,tipoCredito(i),aImprimir.ListaCreditos[i]);
            }
        }
        printf("\n");
    }
}


//BUSCAR

void buscarClientePorId()
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    int id;

    printf("Ingresar Id:\n");
    scanf("%d", &id);

    for(int i = 0; i<longitud; i++)
    {
        if(encontro == 0)
        {
            if(vCliente[i].Id == id)
            {
                encontro = 1;

                imprimirCliente(vCliente[i]);
            }
        }
    }
    exepcionId(encontro, id);
}

void buscarClientePorNombre()
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    char nombre [100];

    printf("Ingresar Nombre:\n");
    scanf("%s", nombre);

    for(int i = 0; i<longitud; i++)
    {
        if(strcmp(vCliente[i].nombre , nombre) == 0)
        {
            imprimirCliente(vCliente[i]);

            encontro = 1;
        }
    }

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el Nombre:%s", nombre);
    }
}

void buscarClientePorEdad()
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    int edadA, edadB;

    printf("Ingresar Rango de edad:\nMenor Valor:");
    scanf("%d", &edadA);
    printf("Mayor Valor:");
    scanf("%d", &edadB);

    for(int i = 0; i<longitud; i++)
    {
        if(vCliente[i].edad >= edadA && vCliente[i].edad <= edadB )
        {
            imprimirCliente(vCliente[i]);

            encontro = 1;
        }
    }

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el rango de edad: %d - %d", edadA, edadB);
    }
}


//CREDITOS

void inicializacionCredito(struct Cliente *nuevoCliente)
{
    int longitudCreditos = 3;

    for(int i = 0; i < longitudCreditos; i++)
    {
        nuevoCliente->ListaCreditos[i] = 0;
    }
}

void solicitarCredito()
{
    struct Cliente vCliente[100];

    int encontro = 0;

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    float monto;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    printf("Ingresar el monto del Credito:\n");
    scanf("%f", &monto);

    int tipoCredito = menuTipoCredito()-1;

    int totalDeuda;

    for(int i = 0; i<longitud; i++)
    {
        if(encontro == 0)
        {
            if(vCliente[i].Id == id)
            {
                totalDeuda = DeudaActual(&vCliente[i], monto);

                if(vCliente[i].limiteCredito >= totalDeuda)
                {
                    vCliente[i].ListaCreditos[tipoCredito] = monto;

                    vCliente[i].limiteCredito = vCliente[i].limiteCredito - monto;
                } else{

                    printf("El Monto ingresado es insuficiente para solicitar un credito. Limite disponible: %f"
                            ,vCliente[i].limiteCredito - (totalDeuda - monto));
                }
                encontro = 1;
            }
        }
    }
    exepcionId(encontro, id);

    actualizarArchivo(encontro, longitud, vCliente);
}

void cancelarCredito() {

    struct Cliente vCliente[100];

    int encontro = 0;

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    int valorTipoCredito = menuTipoCredito() - 1;

    char *nombreTipoCredito = tipoCredito(valorTipoCredito);

    printf("Pagara el total del %s\n", nombreTipoCredito);

    for (int i = 0; i < longitud; i++) {

        if (encontro == 0 && vCliente[i].Id == id)
        {
            if(vCliente[i].ListaCreditos[valorTipoCredito] != 0 )
            {
                vCliente[i].limiteCredito =  vCliente[i].limiteCredito + vCliente[i].ListaCreditos[valorTipoCredito];

                vCliente[i].ListaCreditos[valorTipoCredito] = 0;

                printf("Su Limite Actual es de:: %f \n ", vCliente[i].limiteCredito, nombreTipoCredito);

                encontro = 1;

            }else{

                printf("NO posee deuda" );

                encontro = 1;
            }
        }

    }
    exepcionId(encontro, id);

    actualizarArchivo(encontro, longitud, vCliente);
}

int menuTipoCredito()
{
    int opciones;

    printf("\nTIPO DE CREDITOS"
           "\n1- Credito Hipotecario"
           "\n2- Credito Automotor"
           "\n3- Otros Creditos"
           "\nIngrese una Opcion:\n");

    scanf("%d", &opciones);

    return opciones;
}

float limiteCredito(struct Cliente *nuevoCliente)
{
    float limite;

    if(nuevoCliente->refCliente == NULL)
    {
        limite = 1000;
    }
    else {
        limite = 2000;
    }

    return limite;
}

char * tipoCredito(int i){

    char * nombre =  malloc(30);

    if(i == 0)
    {
        strcpy(nombre, "Credito Hipotecario");

    }
    else if(i == 1)
    {
        strcpy(nombre, "Credito Automotor");

    }else if(i == 2)
    {
        strcpy(nombre, "Otros Credito");
    }

    return nombre;
}

int DeudaActual(struct Cliente *nuevoCliente, float monto)
{
    int total = 0;
    int longitudCredito = 3;

    for(int j = 0; j<longitudCredito; j++)
    {
        total = total + nuevoCliente->ListaCreditos[j];
    }

    return total + monto;
}


//EXCEPCIONES

void exepcionId(int encontro, int id)
{
    if(encontro == 0)
    {
        printf("no se encontraron resultados para el Cliente con ID: %d", id);
    }
}


//MANEJO DE ARCHIVOS

void guardarEnArchivo(struct Cliente *nuevoCliente){

    FILE * archivo;

    archivo = fopen("Archivo1.csv", "a");

    fprintf(archivo, "\n%d,%s,%s,%d,%d,%f,%d,%d,%d",
            nuevoCliente->Id,
            nuevoCliente->apellido,
            nuevoCliente->nombre,
            nuevoCliente->edad,
            nuevoCliente->dni,
            nuevoCliente->limiteCredito,
            nuevoCliente->ListaCreditos[0],
            nuevoCliente->ListaCreditos[1],
            nuevoCliente->ListaCreditos[2]);

    fclose(archivo);
}

void sobrescribirArchivo(struct Cliente *nuevoCliente){

    FILE * archivo;

    archivo = fopen("Archivo1.csv", "w");

    fprintf(archivo, "\n%d,%s,%s,%d,%d,%f,%d,%d,%d",
            nuevoCliente->Id,
            nuevoCliente->apellido,
            nuevoCliente->nombre,
            nuevoCliente->edad,
            nuevoCliente->dni,
            nuevoCliente->limiteCredito,
            nuevoCliente->ListaCreditos[0],
            nuevoCliente->ListaCreditos[1],
            nuevoCliente->ListaCreditos[2]);

    fclose(archivo);
}

void actualizarArchivo(int encontro, int longitud, struct Cliente *vCliente)
{
    if(encontro == 1)
    {
        for (int i = 0; i < longitud; i++) {

            if(i == 0) {
                sobrescribirArchivo(&vCliente[i]);
            }
            else{
                guardarEnArchivo(&vCliente[i]);
            }
        }
    }
}