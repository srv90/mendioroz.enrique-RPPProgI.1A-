#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5


typedef struct
{
    int id;
    char procesador[60];
    char marca[60];
    int precio;

} Notebook;


int calcularIVA(int* precio);
int reemplazarCaracter(char [], char, char);
int ordenarNotebooks(Notebook lista[], int tam);

int main()
{

    int precio = 100;
    calcularIVA(&precio);
    printf("Precio con iva: %d", precio);
    char cadena [] = "mama";
    char caracterViejo = 'a';
    char caracterNuevo = 'e';
    int cantidad = reemplazarCaracter(cadena, caracterViejo, caracterNuevo);

    if(cantidad == 0 )
    {
        printf("Ocurrio un error");
    }
    else printf("\nEL caracter se reemplazo %d veces", cantidad);



    Notebook lista [TAM] = { {1, "intel", "hp", 6000}, {2, "intel", "hp", 1000}, {3, "intel", "dell", 1000},
        {4, "intel", "hp", 2000},{5, "amd", "sony", 4400}
    };

    if(ordenarNotebooks(lista, TAM))
    {
        printf("\nID      PROCESADOR      MARCA       PRECIO\n");
        for (int i=0; i<TAM ; i++ )
        {
            printf("%d      %10s      %10s      %d\n", lista[i].id, lista[i].procesador, lista[i].marca, lista[i].precio);
        }

    }
    else printf("Ocurrio un error");

    return 0;
}



int ordenarNotebooks(Notebook lista[], int tam)
{

    int retorno = 0;
    Notebook aux;
    if(lista != NULL && tam > 0)
    {
        for (int i=0; i<tam-1 ; i++ )
        {
            for (int j=i+1; j<tam ; j++ )
            {
                if(strcmp(lista[i].marca, lista[j].marca) > 0
                        || (strcmp(lista[i].marca, lista[j].marca)== 0 && lista[i].precio > lista[j].precio) )
                {
                    aux = lista[i];
                    lista[i] = lista[j];
                    lista[j] = aux;

                }
            }
        }
        retorno = 1;
    }

    return retorno;
}


int reemplazarCaracter(char palabra [], char caracterViejo, char caracterNuevo)
{
    int retorno =0;
    int tam = strlen(palabra);
    int cantidad =0;
    if(palabra != NULL)
    {

        for (int i=0; i<tam ; i++ )
        {
            if(palabra[i] == caracterViejo)
            {
                palabra[i] = caracterNuevo;
                cantidad++;
            }
        }
        retorno = cantidad;
    }
    return retorno;


}

int calcularIVA(int* precio)
{

    return *precio = *precio * 1.21;

}
