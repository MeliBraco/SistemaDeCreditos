#include "Default.h"
#include <stdio.h>
#include <stdlib.h>

void agregarCliente(char* nombre, int edad){

    //Debe agregar un cliente a la base de datos
}

void eliminarCliente(char* nombre){
    //Debe eliminar un cliente de la base de datos
}

void buscarCliente(char* cliente){
    //busca un cliente, debe imprimir los creditos que debe y si tiene o no un referido
}

void referenciarCliente(char* cliente, char* referencia){
    //Agrega un referenciado al cliente
}
void PedirCredito(char* nombre, int monto,struct credito **UnCredito){
    //Pide un credito
}

void PagarCredito(char* nombre, int monto,struct credito **UnCredito){
    //Paga una parte de un credito
}

void CancelarCredito(char* nombre, struct credito **UnCredito){
    // Cancela el credito
}

