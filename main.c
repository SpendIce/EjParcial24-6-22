#include <stdio.h>
#include "Listas.h"

int main() {
    ListaSimple *lista1 = newListaSimple(newNodoSimple(2, newNodoSimple(5, newNodoSimple(9, newNodoSimple(10, newNodoSimple(7, NULL))))));
    ListaSimple *lista2 = newListaSimple(newNodoSimple(2, newNodoSimple(8, newNodoSimple(1, newNodoSimple(10, newNodoSimple(9, NULL))))));
    printf("Ejercicio 1: \n");
    printS(lista1);
    int *diferencia = Ej2(lista1, lista2);
    Ej1(lista1, lista2);
    printS(lista1);
    int i = 0;
    printf("Ejercicio 2: \n");
    while(diferencia[i] != '\0')
    {
        printf("%d \t",diferencia[i]);
        i++;
    }
    printf("\n");
    ListaSimple *lista3 = newListaSimple(newNodoSimple(3, newNodoSimple(8, newNodoSimple(3, newNodoSimple(4, newNodoSimple(7, newNodoSimple(3, NULL)))))));
    printf("Ejercicio 3: \n");
    printS(lista3);
    Ej3(lista3);
    printS(lista3);
    int vector1[] = {5, 3, 9, 2, 4, -1};
    int vector2[] = {4, 5, 7, 1, 9, -1};
    int *interseccion = Ej4(vector1, vector2);
    printf("Ejercicio 4: \n");
    for(int i = 0; vector1[i] != -1; i++)
        printf("%d \t",vector1[i]);
    printf("\n");
    for(int i = 0; vector2[i] != -1; i++)
        printf("%d \t",vector2[i]);
    printf("\n");
    for(int i = 0; interseccion[i] != -1; i++)
        printf("%d \t",interseccion[i]);
    printf("\nEjercicio 5: \n");
    NodoDoble *D1 = newNodoDoble(5, NULL, NULL);
    NodoDoble *D2 = newNodoDoble(10, D1, NULL);
    D1->sig = D2;
    NodoDoble *D3 = newNodoDoble(6, D2, NULL);
    D2->sig = D3;
    NodoDoble *D4 = newNodoDoble(4, D3, NULL);
    D3->sig = D4;
    NodoDoble *D5 = newNodoDoble(1, D4, NULL);
    D4->sig = D5;
    ListaDoble *listaD1 = newListaDoble(D1);
    printD(listaD1);
    Ej5(listaD1, newNodoDoble(3, NULL, NULL), 1);
    printD(listaD1);
    printf("Ejercicio 6: \n");
    for(int i = 0; vector1[i] != -1; i++)
        printf("%d \t",vector1[i]);
    printf("\n");
    for(int i = 0; vector2[i] != -1; i++)
        printf("%d \t",vector2[i]);
    printf("\n");
    printD(Ej6(vector1, vector2));
    printf("Ejercicio 7: \n");

    return 0;
}
