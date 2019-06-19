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
    Shell(vCliente,longitud);

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

void Shell( struct Cliente *array, int n) {

    int i,x,y,tmp;

    for(i = 1; i < n; i = i*3+1) {}

    while (i > 0) {
        for(x = i; x < n; x++) {
            y = x;
            tmp = array[x].Id;
            while (y >= i && array[y - i].Id > tmp) {
                array[y] = array[y - i];
                y = y - i;
            }
            array[y].Id = tmp;
        }
        i = i / 2;
    }
}


/*
void borrarEnArchivo(int encontro,int longitud, struct Cliente *vCliente){
    //debe sobreescribir el csv con el array que tiene en memoria

}*/