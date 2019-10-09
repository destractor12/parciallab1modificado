#include "Cliente.h"

void cargarHarcodeEstructurajuegos(eJuegos listado[],int tamanio)
{
    char nombre[3][51]= {"Jumanji","El juego de la Oca","Carrera de mentes"};
    //int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    //int [3]= {1,2,3};
    float num[3]= {540.24,237.18,331.97};
    //char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    //int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    //char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<3; i++)
    {
        listado[i].codigodejuegos=idAutoIncrementalEstructurajuegos(listado,tamanio);
        strcpy(listado[i].descripcionjuegos,nombre[i]);
        listado[i].importe=num[i];
        listado[i].isEmpty=1;
    }
}

int idAutoIncrementalEstructurajuegos(eJuegos listado[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void inicializarEstadosEstructura(eCliente listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        listado[i].isEmpty=0;
    }
}

void inicializarEstadosEstructuraalquiler(eAlquileres listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        listado[i].isEmpty=0;
    }
}

int generica_buscarEspacio (eCliente* list, int len)
{
    int indice = -1;
    int i;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int generica_buscarEspacioalquiler(eAlquileres* list, int len)
{
    int indice = -1;
    int i;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/*int generica_findGenericById(eCliente* list, int len, int id)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1 && list[i].codigodecliente==id)
        {
            return i;
        }
    }

    return -1;
}*/

void menu(eCliente listado[],int tamanio,eJuegos listadojuegos[],int tamaniojuego,eAlquileres listadoalquileres[], int tamanioalquiler)
{
    inicializarEstadosEstructura(listado,tamanio);
    inicializarEstadosEstructuraalquiler(listadoalquileres,tamanioalquiler);
    cargarHarcodeEstructurajuegos(listadojuegos,tamaniojuego);
    cargarHarcode(listado,tamanio);
    char seguir='s';
    int opcion;
    int indice;
    int indicealquiler;
    int flag=-1;
    int flagalquileres;
    float promedio;
    do
    {
        printf("1- Agregar cliente");
        printf("\n2- Modificar cliente");
        printf("\n3- Borrar cliente");
        printf("\n4- mostrar ordenados");
        printf("\n5- mostrar juegos");
        printf("\n6- Agregar alquiler");
        printf("\n7- Informes");
        printf("\n8- Salir\n");
        scanf("%d",&opcion);
        opcion=validarEntero(opcion,"una opcion correcta",1,8);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            indice=generica_buscarEspacio(listado,tamanio);
            alta(listado,tamanio,indice);
            flag=0;
            break;
        case 2:
            if(flag==0)
            {
                modificarEstructura(listado,tamanio);
            }
            else
            {
                printf("no se ingresaron datos en el sistema");
            }

            break;
        case 3:
            if(flag==0)
            {
                darDeBajaEstructura(listado,tamanio,"\nEstas seguro que queres dar de baja este usuario? (S/N) ");
            }
            else
            {
                printf("no se ingresaron datos en el sistema");
            }
            break;
        case 4:
            if(flag==0)
            {
                ordenarSegunCriterio(listado,tamanio);
            }
            else
            {
                printf("no se ingresaron datos en el sistema");
            }
            break;
        case 5:
            ordenarSegunCriteriojuegos(listadojuegos,tamaniojuego);
            break;
        case 6:
            indicealquiler=generica_buscarEspacioalquiler(listadoalquileres,tamanioalquiler);
            flagalquileres=altaalquiler(listadoalquileres,tamanioalquiler,indicealquiler,listado, tamanio,listadojuegos);
            if(flagalquileres==0)
            {
                printf("se dio de alta con exito");
            }
            else
            {
                printf("no se pudo dar de alta");
            }
            break;
        case 7:
            promedio=promedioalquileres(listadoalquileres,tamanioalquiler,listadojuegos);
            printf("el promedio de los importes de los juegos alquilados es: %.2f",promedio);
            system("\npause");
            system("cls");
            superarpromedio(listadojuegos,tamaniojuego,listadoalquileres,tamanioalquiler);
            system("\npause");
            system("cls");
            burbujeoeficiente(listadojuegos,tamaniojuego);
            system("\npause");
            system("cls");
            insercionclientes(listado,tamanio);
            break;
        case 8:
            seguir='n';
            break;
        }
        if(seguir!='n')
        {
            seguir=deseaContinuar("\nDesea continuar con el programa? (S/N) ");

        }

        system("cls");
    }
    while(seguir=='s');
}


void alta(eCliente listado[],int tamanio,int indice)
{
    if(indice!=-1)
    {
        listado[indice].codigodecliente=idAutoIncrementalEstructura(listado,tamanio);
        getString("Nombre: ",listado[indice].nombre);
        validarStringCadena(listado[indice].nombre);
        //stringToUpper(listado[indice].nombre);
        getString("Apellido: ",listado[indice].apellido);
        validarStringCadena(listado[indice].apellido);
        //stringToUpper(listado[indice].nombre);
        getChar("sexo: ", listado[indice].sexo);
        validarStringCaracter(listado[indice].sexo);
        getString("Domicilio: ",listado[indice].domicilio);
        getString("Telefono: ",listado[indice].telefono);
        listado[indice].isEmpty=1;
    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int idAutoIncrementalEstructura(eCliente listado[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void modificarEstructura(eCliente listado[],int tamanio)
{
    fflush(stdin);
    int Id;
    int indice;
    int opcion;
    opcion=getInt("\nQue queres modificar?\n1- Apellido\n2- Nombre\n3- Sexo\n4- Domicilio\n5- Telefono\nIngrese un el numero de la opcion: ");
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del apellido que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);
        modificarStringEstructura(listado,indice,listado[indice].apellido);
        break;
    case 2:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del nombre que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);
        modificarStringEstructura(listado,indice,listado[indice].nombre);
        break;
    case 3:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del sexo que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);
        break;
    case 4:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del domicilio que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);
        modificarStringEstructura(listado,indice,listado[indice].domicilio);
        break;
    case 5:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del telefono que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);
        modificarStringEstructura(listado,indice,listado[indice].telefono);
        break;
    }
}

char modificarStringEstructura(eCliente listado[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa el nuevo dato: ",caracter);
        //stringToUpper(caracter);
    }
    else
    {
        printf("\nId no encontrado");
    }
    return caracter;
}

float modificarFlotanteEstructura(eCliente listado[],int indice,float dato)
{
    if(indice!=-1)
    {
        getFloat("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }

    return dato;
}

void mostrarListaEstructura(eCliente listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            mostrarUnoEstructura(listado,tamanio,i);
        }

    }
}

void mostrarUnoEstructura(eCliente listado[],int tamanio,int i)
{
    printf("\n\nNombre: %s\nApellido: %s\nId: %d\nDomicilio: %s\nTelefono: %s\nSexo: %c",listado[i].nombre,listado[i].apellido,listado[i].codigodecliente,listado[i].domicilio,listado[i].telefono, listado[i].sexo);
}

int buscarPorIdEstructura(eCliente listado[],int tamanio,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1 && listado[i].codigodecliente==id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void darDeBajaEstructura(eCliente listado[],int tamanio,char mensaje[])
{
    int Id;
    int indice;
    fflush(stdin);
    mostrarListaEstructura(listado,tamanio);
    Id=getInt("\nIngresa el Id a dar de baja ");
    indice=buscarPorIdEstructura(listado,tamanio,Id);
    borrarEntidadEstructura(listado,indice,mensaje);
}

void borrarEntidadEstructura(eCliente listado[],int indice,char mensaje[])
{
    char pregunta;
    if(indice!=-1)
    {
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            listado[indice].isEmpty=-1;
        }

    }
    else
    {
        printf("\nId no encontrado");
    }
}

void ordenarSegunCriterio(eCliente listado[],int tamanio)
{
    eCliente aux;
    int i;
    int j;
    for(i=0; i<tamanio-1; i++)
    {
        for(j=i+1; j<tamanio; j++)
        {
            if(listado[i].isEmpty==1&&listado[j].isEmpty==1)
            {
                if(strcmp(listado[i].nombre,listado[j].nombre)>0&&strcmp(listado[i].apellido,listado[j].apellido)>0)
                {
                    aux=listado[i];
                    listado[i]=listado[j];
                    listado[j]=aux;
                }
            }
        }
    }
    mostrarListaEstructura(listado,tamanio);
}

void ordenarSegunCriteriojuegos(eJuegos listado[],int tamanio)
{
    eJuegos aux;
    int i;
    int j;
    for(i=0; i<tamanio-1; i++)
    {
        for(j=i+1; j<tamanio; j++)
        {
            if(listado[i].isEmpty==1&&listado[j].isEmpty==1)
            {
                if(strcmp(listado[i].descripcionjuegos,listado[j].descripcionjuegos)>0)
                {
                    aux=listado[i];
                    listado[i]=listado[j];
                    listado[j]=aux;
                }
            }
        }
    }
    mostrarListaEstructurajuegos(listado,tamanio);
}

void mostrarListaEstructurajuegos(eJuegos listado[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            mostrarUnoEstructurajuegos(listado,tamanio,i);
        }

    }
}

void mostrarUnoEstructurajuegos(eJuegos listado[],int tamanio,int i)
{
    printf("\n\nId: %d\nNombre: %s\nImporte: %.2f",listado[i].codigodejuegos,listado[i].descripcionjuegos,listado[i].importe);
}


int altaalquiler(eAlquileres listadoalquileres[],int tamanio,int indice,eCliente listadoclientes[], int tamaniocliente,eJuegos listadojuegos[])
{
    int retorno=-1;
    if(indice!=-1)
    {
        mostrarListaEstructura(listadoclientes,tamaniocliente);
        listadoalquileres[indice].codigodealquileres=idAutoIncrementalEstructuraalquileres(listadoalquileres,tamanio);
        listadoalquileres[indice].codigodecliente=getInt("\nIngrese un Id de cliente: ");
        system("cls");
        mostrarListaEstructurajuegos(listadojuegos, 3);
        listadoalquileres[indice].codigodejuegos=getInt("\nIngrese un Id de juego: ");
        listadoalquileres[indice].fecha.dia=getInt("\nIngrese el dia de alquiler: ");
        listadoalquileres[indice].fecha.mes=getInt("\nIngrese el mes de alquiler: ");
        listadoalquileres[indice].fecha.anio=getInt("\nIngrese el año de alquiler: ");
        listadoalquileres[indice].isEmpty=1;
        retorno=0;
    }
    else
    {
        printf("\nNo hay lugares libres");
    }
    return retorno;
}

int idAutoIncrementalEstructuraalquileres(eAlquileres listado[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            contador=contador+1;
        }
    }
    return contador;
}


float promedioalquileres(eAlquileres listado[], int tamanio, eJuegos listadojuegos[])
{
    float total=0;
    float promedio=0;
    int contador=0;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listado[i].isEmpty==1)
        {
            if(listado[i].codigodejuegos==listadojuegos[i].codigodejuegos)
            {
                total=total+listadojuegos[i].importe;
                contador++;
            }

        }


    }
    printf("el Total de los importes de los juegos alquilados es: %.2f",total);
    system("pause");
    promedio=total/contador;
    return promedio;
}

int validarEntero(int numero,char texto[],int min,int max)
{
    while(numero<min || numero>max)
    {

        printf("\nReingrese %s",texto);
        scanf("%d",&numero);
    }
    return numero;
}

void burbujeoeficiente(eJuegos listado[], int tamanio)
{
    eJuegos aux;
    int j;
    int flagnoestaordenado=1;
    while(flagnoestaordenado==1)
    {
        flagnoestaordenado=0;
        for(j=1; j<tamanio; j++)
        {
            if(listado[j].importe>listado[j-1].importe)
            {
                aux=listado[j];
                listado[j]=listado[j-1];
                listado[j-1]=aux;
            }
        }
    }
    mostrarListaEstructurajuegos(listado,tamanio);
}


void cargarHarcode(eCliente listado[],int tamanio)
{
    char nombre[3][51]= {"jose","juan","pedro"};
    char apellido[3][51]= {"Gomez","Vargas","Bardini"};
    char sexo[3]= {'m','m','m'};
    char direccion[3][51]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892"};
    char telefono[3][21]= {"39665247","46057895","22367458"};
    //char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<3; i++)
    {
        listado[i].codigodecliente=idAutoIncrementalEstructura(listado,tamanio);
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].sexo=sexo[i];
        strcpy(listado[i].domicilio,direccion[i]);
        strcpy(listado[i].telefono,telefono[i]);
        listado[i].isEmpty=1;
    }
}

void insercionclientes(eCliente listado[],int tamanio)
{
    int i;
    int j;
    eCliente temp;
    for(i=1; i<tamanio; i++)
    {
        temp=listado[i];
        j=i-1;
        while(j>=0 && strcmp(temp.apellido,listado[j].apellido)>0)
        {
            listado[j+1]=listado[j];
            j--;
        }
        listado[j+1]=temp;
    }
    mostrarListaEstructura(listado,tamanio);
}

void superarpromedio(eJuegos listado[],int tamanio,eAlquileres listadoalquileres[], int tamanioalquileres)
{
    int i;
    int contador=0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i].importe<promedioalquileres(listadoalquileres[i],tamanioalquileres,listado))
        {
            contador++;
        }
    }
    printf("la cantidad de juegos que no superan el promedio es: %d",contador);
}
