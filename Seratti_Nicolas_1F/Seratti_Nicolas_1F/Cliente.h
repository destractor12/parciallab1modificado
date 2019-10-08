#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "Fecha.h"
#include "Utn.h"

typedef struct
{
    int codigodecliente;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int isEmpty;// 0 si esta vacio, 1 si esta ocupado, -1 si esta borrado
}eCliente;

typedef struct
{
    int codigodejuegos;
    char descripcionjuegos[51];
    float importe;
    int isEmpty;
}eJuegos;

typedef struct
{
    int codigodealquileres;
    int codigodejuegos;
    int codigodecliente;
    eFecha fecha;
    int isEmpty;
}eAlquileres;

void cargarHarcodeEstructurajuegos(eJuegos[],int);
void inicializarEstadosEstructura(eCliente[],int);
void menu(eCliente[],int,eJuegos[],eAlquileres[];);
void alta(eCliente[], int, int);
int idAutoIncrementalEstructura(eCliente[], int);
int idAutoIncrementalEstructurajuegos(eJuegos[], int);
void modificarEstructura(eCliente[], int);
char modificarStringEstructura(eCliente[],int ,char[]);
void mostrarListaEstructura(eCliente[],int );
void mostrarUnoEstructura(eCliente[],int ,int );
int buscarPorIdEstructura(eCliente[],int ,int );
void darDeBajaEstructura(eCliente[],int,char[]);
void borrarEntidadEstructura(eCliente[],int ,char[]);
void ordenarSegunCriterio(eCliente[],int );
void mostrarUnoEstructurajuegos(eJuegos[],int ,int);
void mostrarListaEstructurajuegos(eJuegos[],int );
void ordenarSegunCriteriojuegos(eJuegos[],int );
void altaalquiler(eCliente[],int,int);
