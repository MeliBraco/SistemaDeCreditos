#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
            //nuevoCliente->refClienteId,
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
           // nuevoCliente->refClienteId,
            nuevoCliente->ListaCreditos[0],
            nuevoCliente->ListaCreditos[1],
            nuevoCliente->ListaCreditos[2]);

    fclose(archivo);
}

void actualizarArchivo(int encontro, int longitud, struct Cliente *vCliente)
{
    //longitud es la longitud del array de clientes cargados en memoria

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

/*
void borrarEnArchivo(int encontro,int longitud, struct Cliente *vCliente){
    //debe sobreescribir el csv con el array que tiene en memoria

}*/