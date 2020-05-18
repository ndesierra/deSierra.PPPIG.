#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 20
typedef struct{

int id;
int procesador;
char marca[TAM];
float precio;
} Notebook;

float aplicarDescuento(float precio);
int contarCaracteres(char cadena[], char caracter);
int ordenarArray(Notebook array[], int tam);

int main()
{
    float precioProducto = 10;
    char palabra[TAM] = "oso";
    char letra = 'o';
    Notebook array[TAM] = {{1,91,"Intel",150}, {2,95,"Sata2",300}, {3,97,"Core2",50}};

    //EJERCICIO 1
    precioProducto = aplicarDescuento(precioProducto);

    printf("El precio del producto es %.2f \n\n", precioProducto);

    //EJERCICIO 2

    palabra[TAM] = contarCaracteres(palabra, letra);

    //EJERCICIO 3

    ordenarArray(array, TAM);

    return 0;
}

float aplicarDescuento(float precio)
{
    float precioConDescuento;

    precioConDescuento = precio - ((precio * 5)/100);

    return precioConDescuento;
}


int contarCaracteres(char cadena[], char caracter)
{
	int retorno = -1;
	int contador = 0;

	for(int i = 0; cadena[i] != '\0'; i++)
    {
		if(cadena[i] == caracter)
		{
			contador++;
			retorno = 0;
		}
	}
	printf("El caracter %c aparece %d en la palabra %s\n", caracter, contador, cadena);

	return retorno;
}

int ordenarArray(Notebook array[], int tam)
{
    int retorno = -1;
    Notebook auxNote;

    for(int i=0; i < tam -1; i++)
        {
            for(int j=i+1; j < tam; j++)
            {
                if( (strcmp(array[i].marca, array[j].marca) > 0) ||
                        ((strcmp(array[i].marca, array[j].marca) == 0) && array[i].precio < array[j].precio))
                {
                    auxNote = array[i];
                    array[i] = array[j];
                    array[j] = auxNote;

                }
            }
        }

    retorno = 0;
    system("pause");

    return retorno;
}
