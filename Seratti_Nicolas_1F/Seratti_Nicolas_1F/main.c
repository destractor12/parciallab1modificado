#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#define TAM 5
#define TAMCLIENTE 10
#define TAMJUEGO 3


int main()
{
    eCliente clientes[TAMCLIENTE];

    eJuegos juegos[TAMJUEGO];

    eAlquileres alquiler[TAM];

    menu(clientes, TAMCLIENTE, juegos,TAMJUEGO ,alquiler,TAM );

    return 0;
}
