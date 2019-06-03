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

    FilePath(&nuevoCliente);

    printf("El Empleado fue guardado correctamente \n\n");
}

void FilePath(struct Cliente *nuevoCliente)
{
    //Elige en que archivo se va a escribir los datos del clinte segun ID

    FILE * archivo;

    if(nuevoCliente->Id > 0 && nuevoCliente->Id <= 500 ){

        archivo = fopen("Cliente0_500.txt", "a");
    }
    else if(nuevoCliente->Id > 500 && nuevoCliente->Id <= 1000){

        archivo = fopen("Cliente500_1000.txt", "a");
    }

    //guardar(&nuevoCliente ,archivo);
}
