#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#define TAM 3


int main()
{
    eCliente clientes[TAM];

    eJuegos juegos[TAM];

    eAlquileres alquiler[TAM];

    menu(clientes, TAM, juegos,alquiler);

    return 0;
}
