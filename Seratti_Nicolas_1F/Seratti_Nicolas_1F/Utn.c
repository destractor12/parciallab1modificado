#include "Utn.h"
#include <stdlib.h>


char getString(char mensaje[], char caracter[])
{

    printf("%s",mensaje);
    gets(caracter);
    fflush(stdin);
    return caracter;
}

int getInt(char mensaje[])
{
    int A;
    printf("%s",mensaje);
    scanf("%d",&A);
    fflush(stdin);
    return A;
}

float getFloat(char mensaje[],float numeroIngresado)
{
    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);
    fflush(stdin);
    return numeroIngresado;
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
}

/*void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}*/

int validarStringEntero(char datoAValidar[])
{
    int A;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ');
        }
        else
        {
            i=i+1;
        }
    }
    A=atoi(datoAValidar);
    return A;
}

char validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

char validarStringCaracter(char datoAValidar)
{
        if(isalpha(datoAValidar)==0||datoAValidar==' ')
        {
            do
            {
                printf("\nIngresa un caracter valido ");
                scanf("%c",&datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar)==0||datoAValidar==' ');
        }
        return datoAValidar;
}

float validarStringFloat(char datoAValidar[])
{
    float numero;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0)
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0);
        }
        else
        {
            i=i+1;
        }
    }
    numero=atof(datoAValidar);
    return numero;
}


char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
        seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}
