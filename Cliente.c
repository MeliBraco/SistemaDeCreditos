#include <stdio.h>
#include "Default.h"
#include <string.h>
#include <stdlib.h>
#include "Excepciones.c"

void ingresar(){

    struct Cliente nuevoCliente;

    char nombreAux[100];

    char apellidoAux[100];

    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    printf("Ingresar Id:\n");
    scanf("%d", &nuevoCliente.Id);

    if(buscarId(&nuevoCliente.Id, getCantidadCliente(vCliente)) == 0) {

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

        nuevoCliente.referidoID = 0;

        inicializacionCredito(&nuevoCliente);

        nuevoCliente.limiteCredito = limiteCredito(&nuevoCliente);

        guardarEnArchivo(&nuevoCliente);

        printf("El Empleado fue ingresado correctamente \n\n");

    }
    else
    {
        printf("Ya se encuentra vigente un cliente con ese Id, vuelva a ingresar los datos \n\n");

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

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[0] = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[1] = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].ListaCreditos[2] = atof(token);

            token = strtok(NULL, ",");
            vCliente[longitud].referidoID = atof(token);

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
    struct Cliente vCliente[1000];

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
        printf("-ID Referido = %d \n", aImprimir.referidoID);
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
    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int encontro = 0;

    int id;

    printf("Ingresar Id:\n");
    scanf("%d", &id);

    for(int i = 0; i< getCantidadCliente(vCliente); i++)
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
    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int encontro = 0;

    char nombre [50];

    printf("Ingresar Nombre:\n");
    scanf("%s", nombre);

    for(int i = 0; i< getCantidadCliente(vCliente); i++)
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
    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int encontro = 0;

    int edadA, edadB;

    printf("Ingresar Rango de edad:\nMenor Valor:");
    scanf("%d", &edadA);

    printf("Mayor Valor:");
    scanf("%d", &edadB);

    for(int i = 0; i< getCantidadCliente(vCliente); i++)
    {
        if(vCliente[i].edad >= edadA && vCliente[i].edad <= edadB )
        {
            imprimirCliente(vCliente[i]);

            encontro = 1;
        }
    }

    encontroEdad(encontro,edadA,edadB);
}

void ordenar()
{
    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    actualizarArchivo(1,getCantidadCliente(vCliente), vCliente);

    printf("Se ordenaron los clientes vigentes por ID \n\n");
}

void referirCliente(){

    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    int id;

    int refeID;

    printf("Ingresar ID del cliente que refiere:\n");
    scanf("%d", &id);

    printf("Ingresar ID del cliente referido:\n");
    scanf("%d", &refeID);

    // primero evalua que ningun ID sea cero y luego que existan esos clientes

    int clienteReferido = buscarId(&id,longitud);

    int clienteAReferido = buscarId(&refeID,longitud);

    if(id != 0 && refeID != 0) {

        if (clienteReferido == 1 && clienteAReferido == 1) {

            if(encontro == 0) {

                for (int i = 0; i < longitud; i++) {

                    if (vCliente[i].Id == id) {

                        if(vCliente[i].referidoID == 0) {

                            vCliente[i].referidoID = refeID;

                            vCliente[i].limiteCredito = calcularNuevoLimiteReferido(vCliente[i]);

                            printf("La referencia se agrego correctamente");

                            encontro = 1;
                        }
                        else
                        {
                            printf("El cliente ingresado ya tiene un referido");
                        }
                    }
                }
            }
        } else {

            printf("No existe el cliente que desea referir %d o el cliente referido %d", id, refeID);
        }
    }
    else
    {
        printf("Los ID ingresados no pueden ser cero");
    }

    actualizarArchivo(encontro, longitud, vCliente);
}

void eliminarReferido()
{
    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int encontro = 0;

    int id;

    printf("Ingresar ID del cliente a desreferenciar:\n");
    scanf("%d", &id);

    if (buscarId(&id,longitud) == 1) {

        if(encontro == 0) {

            for (int i = 0; i < longitud; i++) {

                if (vCliente[i].Id == id) {

                    if(vCliente[i].referidoID != 0) {

                        vCliente[i].referidoID = 0;

                        vCliente[i].limiteCredito = 1000;


                        printf("Se quito la referencia al ID %d", id);

                        encontro = 1;
                    }
                }
            }
        }
    }

    actualizarArchivo(encontro, longitud, vCliente);
}

int calcularNuevoLimiteReferido(struct Cliente cliente)
{
    float limite = cliente.limiteCredito;

    float sumadorCredito;

    for(int i = 0; i<3; i++){

        sumadorCredito += cliente.ListaCreditos[i];
    }

    float incremento  = 2000 - (limite + sumadorCredito);

    return limite + incremento;
}

