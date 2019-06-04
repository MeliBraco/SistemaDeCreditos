#include <stdio.h>
#include "Default.h"
#include <string.h>

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

        archivo = fopen("Archivo1.txt", "a");
    }
    else if(nuevoCliente->Id > 500 && nuevoCliente->Id <= 1000){

        archivo = fopen("Archivo2.txt", "a");
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

    //guardar en archivo

    fputs("ID:", archivo);
    fputs(auxId ,archivo);
    fputs(" ---->", archivo);
    fputs(" NOMBRE:", archivo);
    fputs(nuevoCliente->nombre ,archivo);
    fputs(" APELLIDO:", archivo);
    fputs(nuevoCliente->apellido ,archivo);
    fputs(" DNI:", archivo);
    fputs(auxDNI, archivo);
    fputs(" EDAD:", archivo);
    fputs(auxEdad, archivo);
    fputs(" TOTAL CREDIT0: $", archivo);
    fputs(auxCredito, archivo);
    fputs(" \n", archivo);

    fclose(archivo);
}


