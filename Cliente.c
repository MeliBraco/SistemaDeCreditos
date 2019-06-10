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
            vCliente[longitud].limiteCredito = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[0] = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[1] = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[2] = atof(token);

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


