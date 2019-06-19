#include <stdlib.h>

void encontroId(int encontro, int id){

    if(encontro == 0)
    {
        printf("no se encontraron resultados para el id: %d ", id);
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