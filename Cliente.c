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

    FilePath(&nuevoCliente);

    printf("El Empleado fue guardado correctamente \n\n");
}

void FilePath(struct Cliente *nuevoCliente)
{
    //Elige en que archivo se va a escribir los datos del clinte segun ID

    FILE * archivo;

    if(nuevoCliente->Id > 0 && nuevoCliente->Id <= 500 ){

        archivo = fopen("Archivo1.csv", "a");
    }
    else if(nuevoCliente->Id > 500 && nuevoCliente->Id <= 1000){

        archivo = fopen("Archivo2.csv", "a");
    }

    guardar(nuevoCliente ,archivo);
}

void guardar(struct Cliente *nuevoCliente, FILE * archivo){

    char auxId[900];
    sprintf(auxId, "%d", nuevoCliente->Id);

    char auxEdad[3];
    sprintf(auxEdad, "%d", nuevoCliente->edad);

    char auxDNI[100];
    sprintf(auxDNI, "%d", nuevoCliente->dni);

    char auxCredito[100];
    sprintf(auxCredito, "%d", nuevoCliente->credito);

    fprintf (archivo,  "%d,%s,%s,%d,%d,%d",
             nuevoCliente->Id,
             nuevoCliente->apellido,
             nuevoCliente->nombre,
             nuevoCliente->edad,
             nuevoCliente->dni,
             nuevoCliente->credito);

    fclose(archivo);
}

void getFicheros()
{
    int opciones;

    do{
        printf("MENU FICEHROS:"
               "\n1- Archivo1.txt (ID 0 A 500)"
               "\n2- Archivo2.txt (ID 500 A 1000)"
               "\n2- Volver Menu Principal"
               "\nIngrese una Opcion:\n\n");

        scanf("%d", &opciones);

        switch(opciones) {

            case 1:
                getClientes("Archivo1.csv");

                break;

            case 2:
                getClientes("Archivo2.csv");

                break;

            default:
                printf("Archivo inexistente. \n");
        }

    }while(opciones !=6);
}

void getClientes(char nombre [50])
{
    FILE * archivo;

    archivo = fopen(nombre, "r");

    char cliente;

    while(cliente != EOF)
    {
        cliente = fgetc(archivo);

        printf("%c", cliente);
    }

    printf("\n");

    fclose(archivo);
}

