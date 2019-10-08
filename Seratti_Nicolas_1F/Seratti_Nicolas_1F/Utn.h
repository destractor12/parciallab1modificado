#include<stdio.h>
#include<string.h>
#include<ctype.h>

char getString(char mensaje[], char caracter[]);

/** \brief Funcion que toma un entero y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param A int Entero que va a guardar el valor ingresado
 * \return int Retorna el entero validado
 *
 */
int getInt(char mensaje[]);

/** \brief Recibe un numero Flotante ingresado por el usuario y lo retorna
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param numeroIngresado float Numero flotante que ingresa el usuario
 * \return float El numero flotante ingresado por el usuario
 *
 */
float getFloat(char mensaje[],float numeroIngresado);

/** \brief Funcion que toma un caracter y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param caracter char Caracter que va a guardar el input
 * \return char Caracter validado
 *
 */
char getChar(char mensaje[],char caracter);

/** \brief Funcion que hace mayusculas las primeras letras de los nombres o strings que se ingresen
 *
 * \param caracter[] char String a modificar
 * \return void
 *
 */
void stringToUpper(char caracter[]);

/** \brief Funcion que valida si el dato ingresado es un numero entero
 *
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return int Retorna el entero ya validado
 *
 */
int validarStringEntero(char datoAValidar[]);

/** \brief Funcion que valida si el string ingresado es un string
 *
 * \param datoAValidar[] char Cadena a validar
 * \return char Retorna la cadena validada
 *
 */
char validarStringCadena(char datoAValidar[]);

/** \brief Funcion que valida si el caracter ingresado es un caracter
 *
 * \param datoAValidar char Caracter a validar
 * \return char Retorna el caracter validado
 *
 */
char validarStringCaracter(char datoAValidar);

/** \brief Funcion que valida si el dato ingresado es un numero flotante
 *
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return float Retorna el flotante ya validado
 *
 */
float validarStringFloat(char datoAValidar[]);

/** \brief Funcion que le pregunta al usuario si desea continuar
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \return char Retorna la respuesta del usuario
 *
 */
char deseaContinuar(char mensaje[]);
