#include <stdio.h>
#include "Cliente.c"
#include "Creditos.c"
#include "Archivo.c"

int main() {

    menu();

    return 0;
}


void menu() {

    int opciones;

    do{
        printf("\nMENU CLIENTE"
               "\n1-  Ingresar Empleado"
               "\n2-  Listar todos los Empleados "
               "\n3-  Buscar empleado por legajo"
               "\n4-  Buscar empleado por nombre"
               "\n5-  Buscar empleado por rango de edad"
               "\n6-  Solicitar credito"
               "\n7-  Pagar credito"
               "\n8-  Cancelar credito"
               "\n9-  Listar creditos"
               "\n10- Referencias Cliente"
               "\n11- Salir \n "
               "\nIngrese una Opcion:");

        scanf("%d", &opciones);

        switch(opciones) {

            case 1:
                ingresar();
                break;

            case 2:
                getClientes();
                break;

            case 3:
                buscarClientePorId();
                break;

            case 4:
                buscarClientePorNombre();
                break;

            case 5:
                buscarClientePorEdad();
                break;

            case 6:
                solicitarCredito();
                break;

            case 7:
                pagarCredito();
                break;

            case 8:
                cancelarCredito();
                break;

            case 9:
                listarCreditos();
                break;

            case 10:
                //falta
                break;

            case 11:
                Salir();
                break;

            default:
                printf("Opcion Incorrecta. \n por favor ingrese un numero del 1 al 11 \n");
        }

    }while(opciones != 11);
}


void Salir(){

    printf("Programa Finalizado. \n");

    system("exit");
}
