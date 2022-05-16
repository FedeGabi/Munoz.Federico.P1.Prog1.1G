#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

float aplicarDescuento(float numeroIngresado);
int contarCaracteres(char cadena[], char caracter);



typedef struct{
    int id;
    int procesador;
    char marca[20];
    float precio;
}Notebook;

int ordenarNotebooksXMarca(Notebook list[], int tam);

int main()
{

    Notebook listaNotebook[TAM];

    int id[4]={10, 11, 12, 13};
    int procesadorer[4]={32, 64, 32, 64};
    char marcas[4][20]={"AMD", "BANGHO", "BANGHO", "PHILLIPS"};
    float precios[4]= {122.5, 300, 233, 630.5};

    for(int i=0; i<TAM; i++)
    {
        listaNotebook[i].id= id[i];
        listaNotebook[i].procesador= procesadorer[i];
        strcpy(listaNotebook[i].marca, marcas[i]);
        listaNotebook[i].precio= precios[i];
    }


    float resultado;
    int cantidadCaracteres;
    char cadena[20]={"Pereteniensesiti"};

    resultado=aplicarDescuento(100);
    printf("%.2f\n", resultado);

    cantidadCaracteres=contarCaracteres(cadena, 'e');
    printf("%d\n", cantidadCaracteres);

    ordenarNotebooksXMarca(listaNotebook, TAM);
    for(int i=0; i<TAM; i++)
    {
        printf("%d %d %s %.2f\n ", listaNotebook[i].id, listaNotebook[i].procesador, listaNotebook[i].marca, listaNotebook[i].precio);
    }
    return 0;
}


float aplicarDescuento(float numeroIngresado)
{
    float resultado=0;
    if(numeroIngresado>0)
    {

        resultado=numeroIngresado- (numeroIngresado*5/100);
    }
    return resultado;
}

int contarCaracteres(char cadena[], char caracter)
{
    int contadorCaracter=0;
    if(cadena!= NULL)
    {
        for(int i=0; i<strlen(cadena); i++)
        {
            if(cadena[i]==caracter)
            {
                contadorCaracter++;
            }
        }
    }
    return contadorCaracter;
}

int ordenarNotebooksXMarca(Notebook list[], int tam)
{
    if(list!= NULL && tam>0)
    {
        Notebook auxNotebook;
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(list[i].marca, list[j].marca) <0 ||
                   (strcmp(list[i].marca, list[j].marca) == 0 &&
                    list[i].precio < list[j].precio))
                {
                    auxNotebook=list[i];
                    list[i]=list[j];
                    list[j]=auxNotebook;
                }
            }
        }
    }
}
