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
void menu(eCliente[],int,eJuegos[], int,eAlquileres[], int);
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
int altaalquiler(eAlquileres[],int,int,eCliente[],int,eJuegos[]);
int idAutoIncrementalEstructuraalquileres(eAlquileres[],int);
void inicializarEstadosEstructuraalquiler(eAlquileres[],int);
int generica_buscarEspacioalquiler(eAlquileres[], int);
float promedioalquileres(eAlquileres[],int,eJuegos[]);
void burbujeoeficiente(eJuegos[],int);
void cargarHarcode(eCliente[],int);
void insercionclientes(eCliente[],int);
int validarEntero(int,char[],int,int);
void superarpromedio(eJuegos[],int,eAlquileres[],int);
