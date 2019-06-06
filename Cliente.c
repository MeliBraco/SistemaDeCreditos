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

    nuevoCliente.credito = 0;

    guardarEnArchivo(&nuevoCliente);

    printf("El Empleado fue guardado correctamente \n\n");
}

void guardarEnArchivo(struct Cliente *nuevoCliente){

    FILE * archivo;

    archivo = fopen("Archivo1.csv", "a");

    char auxId[900];
    sprintf(auxId, "%d", nuevoCliente->Id);

    char auxEdad[3];
    sprintf(auxEdad, "%d", nuevoCliente->edad);

    char auxDNI[100];
    sprintf(auxDNI, "%d", nuevoCliente->dni);

    char auxCredito[100];
    sprintf(auxCredito, "%d", nuevoCliente->credito);

    fprintf(archivo,  "\n %d,%s,%s,%d,%d,%d",
             nuevoCliente->Id,
             nuevoCliente->apellido,
             nuevoCliente->nombre,
             nuevoCliente->edad,
             nuevoCliente->dni,
             nuevoCliente->credito);

    fclose(archivo);
}

void getClientes()
{
    FILE *archivo = fopen("Archivo1.csv", "rt");

    struct Cliente vCliente[100];

    char linea[100];

    char *token;

    int longitud=1;

    int encontro = 0;

    while(!feof(archivo))
    {
        fgets(linea,100, archivo);

        token = strtok(linea,",");

        if(*token != 10)
        {
            vCliente[longitud].Id = atoi(token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].nombre,token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].apellido,token);

            token = strtok(NULL,",");
            vCliente[longitud].dni = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].edad = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].credito = atof(token);

        }
        longitud++;
    }
    fclose(archivo);

    for(int i = 0; i<longitud; i++)
    {
        imprimirCliente(vCliente[i]);
    }
}

void buscarClientePorId(int id)
{
    FILE *archivo = fopen("Archivo1.csv", "rt");

    struct Cliente vCliente[100];

    char linea[100];

    char *token;

    int longitud=1;

    int encontro = 0;

    while(!feof(archivo))
    {
        fgets(linea,100, archivo);

        token = strtok(linea,",");

        if(*token != 10)
        {
            vCliente[longitud].Id = atoi(token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].nombre,token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].apellido,token);

            token = strtok(NULL,",");
            vCliente[longitud].dni = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].edad = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].credito = atof(token);

        }
        longitud++;
    }
    fclose(archivo);

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
}

void buscarClientePorNombre(char nombre [100])
{
    FILE *archivo = fopen("Archivo1.csv", "rt");

    struct Cliente vCliente[100];

    char linea[100];

    char *token;

    int longitud=1;

    while(!feof(archivo))
    {
        fgets(linea,100, archivo);

        token = strtok(linea,",");

        if(*token != 10)
        {
            vCliente[longitud].Id = atoi(token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].nombre,token);

            token = strtok(NULL,",");
            strcpy(vCliente[longitud].apellido,token);

            token = strtok(NULL,",");
            vCliente[longitud].dni = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].edad = atoi(token);

            token = strtok(NULL,",");
            vCliente[longitud].credito = atof(token);

        }
        longitud++;
    }
    fclose(archivo);

    for(int i = 0; i<longitud; i++)
    {
        if(strcmp(vCliente[i].nombre , nombre) == 0)
        {
            imprimirCliente(vCliente[i]);
        }
    }
}

void imprimirCliente(struct Cliente aImprimir){

    printf("-Legajo = %d \n", aImprimir.Id);
    printf("-Apellido = %s \n", aImprimir.apellido);
    printf("-Nombre = %s \n", aImprimir.nombre);
    printf("-Edad = %d \n", aImprimir.edad);
    printf("-DNI = %d \n", aImprimir.dni);
    printf("-Credito = %d \n", aImprimir.credito);
    printf("\n");

}

