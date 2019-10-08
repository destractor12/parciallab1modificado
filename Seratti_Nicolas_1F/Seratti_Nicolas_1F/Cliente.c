#include "Cliente.h"

void cargarHarcodeEstructurajuegos(eJuegos listado[],int tamanio)
{
    char nombre[3][51]={"Jumanji","El juego de la Oca","Carrera de mentes"};
    //int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    //int [3]= {1,2,3};
    float num[3]={540.24,237.18,331.97};
    //char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    //int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    //char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<tamanio; i++)
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

void menu(eCliente listado[],int tamanio,eJuegos listadojuegos[],eAlquileres listadoalquileres[])
{
    inicializarEstadosEstructura(listado,tamanio);
    cargarHarcodeEstructurajuegos(listadojuegos,tamanio);
    char seguir='s';
    int opcion;
    int indice;
    int flag=-1;
    do
    {
        printf("1- Agregar cliente");
        printf("\n2- Modificar cliente");
        printf("\n3- Borrar cliente");
        printf("\n4- mostrar ordenados");
        printf("\n5- mostrar juegos");
        printf("\n6- Agregar alquiler");
        //printf("\n7- Mostrar uno a uno");
        //printf("\n8- Mostrar uno a muchos");
        printf("\n9- Salir\n");
        scanf("%d",&opcion);
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
            ordenarSegunCriteriojuegos(listadojuegos,tamanio);
            break;
        case 6:
            //mostrarBorrados(listado,tamanio);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
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
        break;
    case 5:
        mostrarListaEstructura(listado,tamanio);
        Id=getInt("\nIngresa el Id del telefono que queres modificar ");
        indice=buscarPorIdEstructura(listado,tamanio,Id);

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

float modificarFlotanteEstructura(eGenericaUsuario listado[],int indice,float dato)
{
    if(indice!=-1)
    {
        getFloat("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }
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
    printf("\n\nNombre: %s\nApellido: %s\nId: %d",listado[i].nombre,listado[i].apellido,listado[i].codigodecliente);
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
    printf("\n\nNombre: %s\nId: %d",listado[i].descripcionjuegos,listado[i].codigodejuegos);
}


void altaalquiler(eCliente listado[],int tamanio,int indice)
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
