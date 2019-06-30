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

/*
    int idCero = 0;

    if(encontro == 1)
    {
        for (int i = 0; i < longitud; i++) {

            if(vCliente[i].Id != 0){

                if(idCero)
                {
                    if (i == 1) {

                        sobrescribirArchivo(&vCliente[i]);

                        idCero = 0;
                    }
                }
                else {

                    if (i == 0) {

                        sobrescribirArchivo(&vCliente[i]);

                    } else {

                        guardarEnArchivo(&vCliente[i]);
                    }
                }
            }

            else
            {
                idCero = 1;
            }
        }
    }*/
}

void Shell(struct Cliente *array, int n) {

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

