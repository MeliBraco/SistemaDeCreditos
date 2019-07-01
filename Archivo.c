#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void guardarEnArchivo(struct Cliente *nuevoCliente){

    FILE * archivo;

    archivo = fopen("Archivo1.csv", "a");

    fprintf(archivo, "\n%d,%s,%s,%d,%d,%f,%d,%d,%d,%d",
            nuevoCliente->Id,
            nuevoCliente->apellido,
            nuevoCliente->nombre,
            nuevoCliente->edad,
            nuevoCliente->dni,
            nuevoCliente->limiteCredito,
            nuevoCliente->ListaCreditos[0],
            nuevoCliente->ListaCreditos[1],
            nuevoCliente->ListaCreditos[2],
            nuevoCliente->referidoID);

    fclose(archivo);
}

void sobrescribirArchivo(struct Cliente *nuevoCliente){

    FILE * archivo;

    archivo = fopen("Archivo1.csv", "w");

    fprintf(archivo, "\n%d,%s,%s,%d,%d,%f,%d,%d,%d,%d",
            nuevoCliente->Id,
            nuevoCliente->apellido,
            nuevoCliente->nombre,
            nuevoCliente->edad,
            nuevoCliente->dni,
            nuevoCliente->limiteCredito,
            nuevoCliente->ListaCreditos[0],
            nuevoCliente->ListaCreditos[1],
            nuevoCliente->ListaCreditos[2],
            nuevoCliente->referidoID);

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

void Shell(struct Cliente *array, int n) {

    int i,x,y;

    int tmp, tmpDNI,tmpEdad,tmpReferido;

    char tmpNombre[100];

    char tmpApellido[100];

    float tmpLimiteCredito;

    int tmpHipotecario, tmpAutomotor, tmpOtros;

    for(i = 1; i < n; i = i*3+1) {} //la idea es que SOLO se incremente i a razón de i*3+1 por repetición

    while (i > 0) {

        for(x = i; x < n; x++) {

            y = x;

            tmp = array[x].Id;

            strcpy(tmpNombre, array[x].nombre);

            strcpy(tmpApellido, array[x].apellido);

            tmpEdad = array[x].edad;

            tmpDNI = array[x].dni;

            tmpLimiteCredito = array[x].limiteCredito;

            tmpHipotecario = array[x].ListaCreditos[0];

            tmpAutomotor = array[x].ListaCreditos[1];

            tmpOtros = array[x].ListaCreditos[2];

            tmpReferido = array[x].referidoID;

            while (y >= i && array[y - i].Id > tmp) {

                array[y] = array[y - i];

                y = y - i;
            }

            array[y].Id = tmp;

            strcpy(array[y].nombre , tmpNombre);

            strcpy(array[y].apellido, tmpApellido);

            array[y].edad = tmpEdad;

            array[y].dni = tmpDNI;

            array[y].limiteCredito = tmpLimiteCredito;

            array[y].ListaCreditos[0] = tmpHipotecario;

            array[y].ListaCreditos[1] = tmpAutomotor;

            array[y].ListaCreditos[2] = tmpOtros;

            array[y].referidoID = tmpReferido;

        }
        i = i / 2;
    }
}