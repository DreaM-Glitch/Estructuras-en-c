
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo;
    char nombre [30];
    char genero;

} alumno;


int posicionMenor (alumno arreglo[], int pos, int validos);
int cargar (alumno arreglo1[],int dim);
int numeroGenero(alumno arreglo[],int validos, char genero1);
void mostrar (alumno arreglo1[], int validos);
void informacion (alumno arreglo[], int validos,int dato);
void mostrarLegajos (alumno arreglo[], int validos);
void mostrarGenero (alumno arreglo[],int validos, char genero1);
void seleccion (alumno arreglo[], int validos);
void insertar (alumno arreglito[],int validos, int dato);
void mostrarUno (alumno arreglo1[], int posicion);
void mostrarNombre (alumno arreglo1[], int validos);
int main()

{
    int op,validos,matricula1, nuevo, cant;
    char opcion1,opcion;
    alumno datos1[100];

    printf("--------ELIJA UNA OPCION----------\n");
    printf("OPCIONES:\nEjercicio 1\nEjercicio 2\nEjercicio 3\nEjercicio 4\nEjercicio 5\nEjercicio 6\nEjercicio 7\nEjercicio 8\n");
    fflush(stdin);
    printf("RESPUESTA: ");
    scanf("%i", &op);
    printf("\n\n");


switch (op)
{
case 1:
printf("Hacer una funcion que cargue un arreglo de alumnos, hasta que el usuario lo decida.\n\n\n");
validos=cargar(datos1,100);
mostrar(datos1,validos);

break;

case 2:
printf ("Hacer una funcion que muestre un arreglo de alumnos por pantalla. Modularizar.\n\n\n");
validos=cargar(datos1,100);
mostrar(datos1,validos);

break;

case 3:
printf("Hacer una funcion que muestre por pantalla los datos de un alumno, conociendo su matricula.\nModularizar. \n\n\n");
validos=cargar(datos1,100);
printf("\nIngrese el numero de matricula: ");
fflush(stdin);
scanf("%i",&matricula1);

informacion(datos1,validos,matricula1);

break;

case 4:
printf("Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de seleccion.\nEl criterio de ordenacion es el numero de matricula.\n\n\n");
validos=cargar(datos1,100);
seleccion (datos1,validos);
mostrar(datos1,validos);

    break;

case 5:
printf("Hacer una funcion que muestre por pantalla los datos de los estudiantes de un genero determinado (se envia por parametro).\nModularizar.\n\n\n");
validos=cargar(datos1,100);
printf("Que genero desea mostrar?: ");
fflush(stdin);
scanf("%c",&opcion);

mostrarGenero(datos1,validos,opcion);

    break;

case 6:
printf("Hacer una funcion que inserte en un arreglo ordenado por matricula un nuevo dato, conservando el orden.\n\n\n ");
validos=cargar(datos1,100);
printf("Ingrese la nueva matricula: ");
fflush(stdin);
scanf("%i",&nuevo);

insertar(datos1,validos,nuevo);
mostrarLegajos(datos1,validos);

    break;

case 7:
printf("Hacer una funcion que ordene el arreglo de alumnos por medio del metodo de insercion.\nEl criterio de ordenacion es el nombre.\n\n\n");
validos=cargar(datos1,100);
ordenamientoInsersion(datos1,validos);
mostrarNombre(datos1,validos);
    break;


case 8:
printf("Hacer una funcion que cuente y retorne la cantidad de estudiantes de un genero determinado\n(se envia por parametro) que tiene un arreglo de alumnos.\n\n\n");
validos=cargar(datos1,100);
printf("Que genero desea mostrar?: ");
fflush(stdin);
scanf("%c",&opcion1);

cant= numeroGenero (datos1,validos,opcion1);
printf("La cantidad de alumno es de: %i", cant);

    break;

default:
    printf("opcion no valida\n");
    break;

}
}




/// ************************************* FUNCIONES ********************************************


int cargar (alumno arreglo1[],int dim)
{
    int i=0;
    char op='s';

    while(i<dim && op=='s')

    {
        printf("Ingrese el legajo: ");
        fflush(stdin);
        scanf("%i", &arreglo1[i].legajo);
        printf("Ingrese el nombre: ");
        fflush(stdin);
        gets(arreglo1[i].nombre);
        printf("M o F (escribir en mayuscula): ");
        fflush(stdin);
        scanf("%c",&arreglo1[i].genero);

        i++;
        printf("\nSi desea seguir presione 's' ");
        fflush(stdin);
        scanf("%c",&op);
        printf("\n");
    }

    return i;
}

void mostrar (alumno arreglo1[], int validos)
{
    int i=0;

    while(i<validos)
    {

        printf("\n\nLegajo: %i\n",arreglo1[i].legajo);
        printf("Nombre: %s\n",arreglo1[i].nombre);
        printf("Genero: %c\n",arreglo1[i].genero);

        printf("\n\n-------------------------------------\n\n");
        i++;

    }

}


void informacion (alumno arreglo[], int validos,int dato)
{
    int i=0;
    int flag=0;

    while (i<validos && flag == 0)
    {
        if(arreglo[i].legajo==dato)
        {
            mostrarUno(arreglo,i);
            flag=1;
        }
        i++;
    }
}

void mostrarUno (alumno arreglo1[], int posicion)
{
    int i=posicion;

    printf("\n\nLegajo: %i\n",arreglo1[i].legajo);
    printf("Nombre: %s\n",arreglo1[i].nombre);
    printf("Genero: %c\n",arreglo1[i].genero);


}

void seleccion (alumno arreglo[], int validos)
{
    int i=0;
    int posmenor;
    int aux;

    while (i<validos-1)
    {
        posmenor=posicionMenor(arreglo,i,validos);
        aux=arreglo[posmenor].legajo;
        arreglo[posmenor].legajo=arreglo[i].legajo;
        arreglo[i].legajo=aux;
        i++;
    }
}


int posicionMenor (alumno arreglo[], int pos, int validos)
{
    int menor=arreglo[pos].legajo;
    int posmenor=pos;
    int i=pos+1;
    while (i<validos)
    {
        if(menor>arreglo[i].legajo)
        {
            menor=arreglo[i].legajo;
            posmenor=i;

        }
        i++;
    }
    return posmenor;
}

void mostrarNombre (alumno arreglo1[], int validos)
{
    int i=0;

    while(i<validos)
    {

       printf("Nombre: %s\n",arreglo1[i].nombre);


        printf("\n\n-------------------------------------\n\n");
        i++;

    }

}






void mostrarGenero (alumno arreglo[],int validos, char genero1)
{
    int i=0;

    while(i<validos)
    {
        if(arreglo[i].genero == genero1)
        {
            mostrarUno(arreglo,i);
        }
        i++;
    }


}


void insertar (alumno arreglito[],int validos, int dato)
{
    int i;
    i=validos-1;

    while (i>=0 && dato>arreglito[i].legajo)
    {
        arreglito[i+1].legajo=arreglito[i].legajo;
        i--;
    }


    arreglito[i+1].legajo=dato;

}


void mostrarLegajos (alumno arreglo[], int validos)
{
    int i=0;

    while (i<validos)
    {
        printf("\n\nLegajo: %i\n",arreglo[i].legajo);

        i++;
    }
}

void ordenamientoInsersion(alumno arr[],int validos)
{
    int i=0;

    while(i<validos-1)
    {

        menor(arr,i,arr[i+1]);
        i++;
    }
}


void menor(alumno arreglo[], int posicion,alumno dato)
{
    int i=posicion;
    while(i>=0 && strcmp(arreglo[i].nombre,dato.nombre)== 1)
    {
        arreglo[i+1] = arreglo[i];
        i--;

    }

    arreglo[i+1]=dato;
}



int numeroGenero(alumno arreglo[],int validos, char genero1)
{
    int i=0;
    int cantidad=0;

    while(i<validos)
    {
        if(arreglo[i].genero == genero1)
        {
            cantidad++;
        }
        i++;
    }

return cantidad;
}
