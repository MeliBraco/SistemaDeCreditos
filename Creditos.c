#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void inicializacionCredito(struct Cliente *nuevoCliente)
{
    int longitudCreditos = 3;

    for(int i = 0; i < longitudCreditos; i++)
    {
        nuevoCliente->ListaCreditos[i] = 0;
    }
}

void solicitarCredito()
{
    struct Cliente vCliente[1000];

    int encontro = 0;

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    float monto;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    printf("Ingresar el monto del Credito:\n");
    scanf("%f", &monto);

    int tipoCredito = menuTipoCredito()-1;

    int totalDeuda;

    for(int i = 0; i<longitud; i++)
    {
        if(encontro == 0)
        {
            if(vCliente[i].Id == id)
            {
                if(vCliente[i].ListaCreditos[tipoCredito] == 0)
                {
                    totalDeuda = DeudaActual(&vCliente[i], monto);

                    if(vCliente[i].limiteCredito >= totalDeuda)
                    {
                        vCliente[i].ListaCreditos[tipoCredito] = monto;

                        vCliente[i].limiteCredito = vCliente[i].limiteCredito - monto;
                    } else{

                        printf("El Monto ingresado es insuficiente para solicitar un credito. Limite disponible: %f"
                                ,vCliente[i].limiteCredito - (totalDeuda - monto));
                    }
                }
                else
                {
                    printf("Debe saldar el credito seleccionado antes de solicitar otro");
                }
                encontro = 1;
            }
        }
    }
    encontroId(encontro, id);

    actualizarArchivo(encontro, longitud, vCliente);
}

void cancelarCredito() {

    struct Cliente vCliente[1000];

    int encontro = 0;

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    int valorTipoCredito = menuTipoCredito() - 1;

    char *nombreTipoCredito = tipoCredito(valorTipoCredito);

    printf("Pagara el total del %s\n", nombreTipoCredito);

    for (int i = 0; i < longitud; i++) {

        if (encontro == 0 && vCliente[i].Id == id)
        {
            if(vCliente[i].ListaCreditos[valorTipoCredito] != 0 )
            {
                vCliente[i].limiteCredito =  vCliente[i].limiteCredito + vCliente[i].ListaCreditos[valorTipoCredito];

                vCliente[i].ListaCreditos[valorTipoCredito] = 0;

                printf("Su Limite Actual es de: $%f\nDeuda %s: $%d ", vCliente[i].limiteCredito, nombreTipoCredito,vCliente[i].ListaCreditos[valorTipoCredito]);

                encontro = 1;

            }else{

                printf("NO posee deuda" );

                encontro = 1;
            }
        }

    }
    encontroId(encontro, id);

    actualizarArchivo(encontro, longitud, vCliente);
}

void pagarCredito() {

    struct Cliente vCliente[1000];

    int encontro = 0;

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    float monto;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    printf("Ingresar el monto del Credito:\n");
    scanf("%f", &monto);

    int valorTipoCredito = menuTipoCredito() - 1;

    char *nombreTipoCredito = tipoCredito(valorTipoCredito);

    printf("Se pagara $%f del %s\n", monto,nombreTipoCredito);

    for (int i = 0; i < longitud; i++)
    {
        if (encontro == 0 && vCliente[i].Id == id)
        {
            if(vCliente[i].ListaCreditos[valorTipoCredito] != 0)
            {
                if(monto <= vCliente[i].ListaCreditos[valorTipoCredito])
                {
                    vCliente[i].limiteCredito =  vCliente[i].limiteCredito + monto;

                    vCliente[i].ListaCreditos[valorTipoCredito] = vCliente[i].ListaCreditos[valorTipoCredito] - monto;

                    printf("Su Limite Actual es de: $%f\nDeuda %s: $%d ", vCliente[i].limiteCredito, nombreTipoCredito,vCliente[i].ListaCreditos[valorTipoCredito]);

                }
                else{

                    printf("El monto a abonar es mayor al total");
                }
            }
            else
            {
                printf("No posee deuda para el credito seleccionado");
            }

            encontro = 1;
        }
    }
    encontroId(encontro, id);

    actualizarArchivo(encontro, longitud, vCliente);
}

void listarCreditos(){

    struct Cliente vCliente[1000];

    cargarClientes(vCliente);

    int longitud = getCantidadCliente(vCliente);

    int id;

    int encontro = 0;

    printf("Ingresar el Id del Cliente:\n");
    scanf("%d", &id);

    printf("Los creditos vigente para el id %d:\n", id);

    for(int i = 0; i<longitud; i++)
    {
        if(encontro == 0)
        {
            if(vCliente[i].Id == id)
            {
                printf("CREDITO HIPOTECARIO: $%d\n" ,vCliente[i].ListaCreditos[0]);

                printf("CREDITO AUTOMOTOR: $%d\n" ,vCliente[i].ListaCreditos[1]);

                printf("OTROS CREDITOS: $%d\n" ,vCliente[i].ListaCreditos[2]);

                encontro = 1;
            }
        }
    }
}

int menuTipoCredito()
{
    int opciones;

    printf("\nTIPO DE CREDITOS"
           "\n1- Credito Hipotecario"
           "\n2- Credito Automotor"
           "\n3- Otros Creditos"
           "\nIngrese una Opcion:\n");

    scanf("%d", &opciones);

    return opciones;
}

float limiteCredito(struct Cliente *nuevoCliente)
{
    float limite = 1000;
/*
    if(nuevoCliente->refCliente == NULL)
    {
        limite = 1000;
    }
    else {
        limite = 2000;
    }
*/
    return limite;
}

char * tipoCredito(int i){

    char * nombre =  malloc(30);

    if(i == 0)
    {
        strcpy(nombre, "Credito Hipotecario");

    }
    else if(i == 1)
    {
        strcpy(nombre, "Credito Automotor");

    }else if(i == 2)
    {
        strcpy(nombre, "Otros Credito");
    }

    return nombre;
}

int DeudaActual(struct Cliente *nuevoCliente, float monto)
{
    int total = 0;

    int longitudCredito = 3;

    for(int j = 0; j<longitudCredito; j++)
    {
        total = total + nuevoCliente->ListaCreditos[j];
    }

    return total + monto;
}
