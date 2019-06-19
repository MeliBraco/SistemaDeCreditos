#include <stdlib.h>

void encontroId(int encontro, int id){

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el id: %d ", id);
    }
}

void encontroNombre(int encontro, char nombre[50]){

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el Nombre:%s", nombre);
    }
}

void encontroEdad(int encontro, int edadA, int edadB){

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el rango de edad: %d - %d", edadA, edadB);
    }

}

int buscarId(int *id, int longitud)
{
    struct Cliente vCliente[100];

    cargarClientes(vCliente);

    int encontro = 0;

    for(int i = 0; i<longitud; i++)
    {
        if(encontro == 0)
        {
            if(vCliente[i].Id == *id)
            {
                encontro = 1;

            }
        }
    }

    return encontro;
}