#include <stdio.h>
#include "Default.h"
#include <string.h>
#include <stdlib.h>
#include "Excepciones.c"



void ingresar(){

    struct Cliente nuevoCliente;

    char nombreAux[100];

    char apellidoAux[100];

    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    printf("Ingresar Id:\n");
    scanf("%d", &nuevoCliente.Id);

    if(buscarId(&nuevoCliente.Id, longitud) == 0) {

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

       //nuevoCliente.refClienteId = 0;

        //struct Cliente *referido = NULL;

        inicializacionCredito(&nuevoCliente);

        nuevoCliente.limiteCredito = limiteCredito(&nuevoCliente);

        guardarEnArchivo(&nuevoCliente);

        printf("El Empleado fue ingresado correctamente \n\n");
    }
    else
    {
        printf("Ya se encuentra disponible un cliente con el mismo Id, vuelva a ingresar los datos \n\n");

        ingresar();
    }
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
            strcpy(vCliente[longitud].apellido, token);

            token = strtok(NULL, ",");
            strcpy(vCliente[longitud].nombre, token);

            token = strtok(NULL, ",");
            vCliente[longitud].edad = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].dni = atoi(token);

            token = strtok(NULL, ",");
            vCliente[longitud].limiteCredito = atof(token);

           // token = strtok(NULL, ",");
          //  vCliente[longitud].refClienteId = atof(token);

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
        //imprimirReferido(aImprimir);

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
    encontroId(encontro, id);
}

void buscarClientePorNombre()
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    char nombre [50];

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

    encontroNombre(encontro,nombre);
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

//ARREGLAR REFERIDO
/*
struct Cliente* buscarReferidoPorId(int id,struct Cliente* vCliente)
{
    int longitud = getCantidadCliente(vCliente);

    for(int i = 0; i<longitud; i++)
    {
        if(vCliente[i].Id == id)
        {
            return &vCliente[i];
        }
    }
}

void referirCliente(){

    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    char nombre [100];

    char refe[100];

    printf("Ingresar Nombre del cliente que refiere:\n");
    scanf("%s", nombre);

    printf("Ingresar Nombre del cliente referido:\n");
    scanf("%s", refe);

    for(int i = 0; i<longitud; i++)
    {
        if(strcmp(vCliente[i].nombre , nombre) == 0)
        {
            if(vCliente[i].refClienteId != 0) {
                for (int f = 0; f < longitud; f++) {
                    if (strcmp(vCliente[f].nombre, refe) == 0) {
                        vCliente[i].refCliente = &vCliente[f];
                        vCliente[i].refClienteId = vCliente[f].Id;
                        vCliente[i].limiteCredito = 2000;
                        printf("La referencia se agrego correctamente");
                        encontro = 1;
                        actualizarArchivo(1, 100, vCliente);
                    }
                }
            }else{
                printf("Este cliente ya tiene un referido");
                encontro =1;
            }
        }
    }if (encontro == 0){
        printf("El nombre del cliente o del referido no existen");
    }
}

void imprimirReferido(struct Cliente refAimprimir){

    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    if (refAimprimir.refClienteId != 0){
        refAimprimir.refCliente = buscarReferidoPorId(refAimprimir.refClienteId, vCliente);
        printf("- CLIENTE REFERIDO : %c", refAimprimir.refCliente->nombre);
    }else{
        printf("ESTE CLIENTE NO TIENE REFERIDOS");
    }
}
*/
