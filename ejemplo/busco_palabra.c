/*2.(X Puntos) Implemente una función que reciba un string con palabras, busque una palabra pasada 
como parámetro y contar la cant que se repite
int contarPalabra(char *str, char *palabracontar)
//un espacio entre cada palñabra
Donde:
● str: Puntero al string con palabras
● palabraContar: Palabra a contar en el string.
Devuelve la cantidad de palabras encontradas o un número negativo en caso de error.
*/
#include<stdio.h>
#include <string.h>
#define MAXIMA_LONGITUD_CADENA 50
int contarPalabra(char *str, char *palabracontar);
int comparo(char* pal, char* pal_comparar);
int main()
{
    int cant_repite=0;
    char palabras[MAXIMA_LONGITUD_CADENA];
    char palabracontar[MAXIMA_LONGITUD_CADENA];

    printf("Ingrese palabras: ");
    fgets(palabras, MAXIMA_LONGITUD_CADENA, stdin);

    printf("Ingrese palabra que quiere buscar: ");
    scanf("%s",palabracontar );

    cant_repite = contarPalabra( palabras , palabracontar);

    printf("\nPalabra ingresasa : %s\n", palabras);

    printf("Se repite  %d veces\n", cant_repite);
    return 0;
}

int contarPalabra(char *str, char *palabracontar)
{
    //armar un vector con una palabra y esoo lo comparo con la pal q debo buscar
    char aux[30];
    int i = 0;
    int  palabra_igual = 0;
    int i_aux = 0, verifico_comparacion = 0; 

    //ver la cndicion cuando no finalice con un espacio 
    while( str[i]!= '\0')
    {
        if( (str[i]>='A' && str[i]<='Z') || (str[i]>='a' &&str[i]<='z') || (str[i] ==' ') || (str[i+1] =='\0') )
        {
            if(  str[i] ==' '|| str[i+1] == '\0')
            {
                aux[i_aux]= '\0';//ya lo tengo armado ahora lo COMPARO 

                verifico_comparacion = comparo( aux , palabracontar);
                if(verifico_comparacion == 0)
                {
                    palabra_igual++;
                }
                printf("palabra armada: %s\n", aux);
                //ver para las otras palbras-> i=0
                // para las otras palbras-> i=0
                i_aux =0;
            }
            else
            {
                aux[i_aux] = str[i] ;//aca voy poneniendo todas las palabras juntas en 1 vector, edbo separar ç
                //cada palabra , debo armar mi palabra
                //debo cerrrar el string
                i_aux++;
            }

        }
        i++;
    }

    return palabra_igual;
}
int comparo(char* pal, char* pal_comparar)
{
    int i = 0, bien = 0;
    //primero saber el largo, si son iguales hago el while

    if( strlen(pal) != strlen(pal_comparar) )
    {
        return -1;
    }
    while(pal[i] != '\0')
    {
        if( pal[i] == pal_comparar[i])
        {
            bien++;
        }
        i++;
    }
    if(bien != strlen(pal) )//es decir no coinciden todas las letras
    {
        return -1;
    }

    return 0;
}
