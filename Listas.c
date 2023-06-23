//
// Created by Juani on 21/6/2023.
//

#include "Listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

NodoSimple *newNodoSimple(int num, NodoSimple *sig)
{
    NodoSimple *aux = malloc(sizeof(NodoSimple));
    if(aux == NULL)
    {
        printf("No hay memoria disponible \n");
        exit(1);
    }
    aux->sig = sig;
    aux->num = num;
    return aux;
}

NodoDoble *newNodoDoble(int num, NodoDoble *prev, NodoDoble *sig)
{
    NodoDoble *aux = malloc(sizeof(NodoDoble));
    if(aux == NULL)
    {
        printf("No hay memoria disponible \n");
        exit(1);
    }
    aux->sig = sig;
    aux->num = num;
    aux->prev = prev;
    return aux;
}

ListaSimple *newListaSimple(NodoSimple *header)
{
    ListaSimple *aux = malloc(sizeof(ListaSimple));
    if(aux == NULL)
    {
        printf("No hay memoria disponible \n");
        exit(1);
    }
    aux->header = header;
    return aux;
}

ListaDoble *newListaDoble(NodoDoble *header)
{
    ListaDoble *aux = malloc(sizeof(ListaDoble));
    if(aux == NULL)
    {
        printf("No hay memoria disponible \n");
        exit(1);
    }
    aux->header = header;
    return aux;
}

void Ej1(ListaSimple *lista1, ListaSimple *lista2)
{
    NodoSimple *aux1 = lista1->header;
    NodoSimple *aux2 = lista2->header;
    NodoSimple *borrador = NULL;
    bool check = false;
    while(aux1->sig != NULL)
    {
        while(aux2 != NULL)
        {
            if(aux2->num == lista1->header->num)
            {
                borrador = lista1->header;
                lista1->header = lista1->header->sig;
                free(borrador);
                aux1 = lista1->header;
            }
            if(aux1->sig->num == aux2->num)
            {
                check = true;
                borrador = aux1->sig;
                aux1->sig = aux1->sig->sig;
                free(borrador);
            }
            aux2 = aux2->sig;
        }
        if(!check) {
            aux1 = aux1->sig;
        }
        aux2 = lista2->header;
        check = false;
    }
}

int* Ej2(ListaSimple *lista1, ListaSimple *lista2)
{
    NodoSimple *aux1 = lista1->header;
    NodoSimple *aux2 = lista2->header;
    int size = 0;
    while(aux1 != NULL)
    {
        size++;
        aux1 = aux1->sig;
    }
    aux1 = lista1->header;
    int *diff = malloc(sizeof(int)*size);
    bool check = false;
    int pos = 0;
    while(aux1 != NULL)
    {
        while(aux2 != NULL)
        {
            if(aux1->num == aux2->num)
            {
                check = true;
            }
            aux2 = aux2->sig;
            if(check)
                aux2 = NULL;
        }
        if(!check)
        {
            diff[pos] = aux1->num;
            pos++;
        }
        check = false;
        aux1 = aux1->sig;
        aux2 = lista2->header;
    }
    diff[pos] = '\0';
    return diff;
}

void Ej3(ListaSimple *lista)
{
    NodoSimple *aux = lista->header;
    NodoSimple *aux2 = aux;
    NodoSimple *borrador = NULL;
    while(aux != NULL)
    {
        while(aux2->sig != NULL)
        {
            if(aux->num == aux2->sig->num)
            {
                borrador = aux2->sig;
                aux2->sig = aux2->sig->sig;
                free(borrador);
            }
            else
                aux2 = aux2->sig;
        }
        aux = aux->sig;
        aux2 = aux;
    }
}



void printS(ListaSimple *lista)
{
    NodoSimple *aux = lista->header;
    while(aux!=NULL)
    {
        printf("%d \t",aux->num);
        aux = aux->sig;
    }
    printf("\n");
}

int *Ej4(int *vector1, int *vector2)
{
    int size;
    for(int i = 0; vector1[i] != -1; i++)
        size++;
    int *interseccion = malloc(size * sizeof(int));
    int k = 0;
    for(int i = 0; vector1[i] != -1; i++)
    {
        for(int j = 0;vector2[j] != -1; j++)
        {
            if(vector1[i] == vector2[j])
            {
                interseccion[k] = vector1[i];
                k++;
            }
        }
    }
    interseccion[k] = -1;
    return interseccion;
}

void Ej5(ListaDoble *lista, NodoDoble *pongo, int pos)
{
    NodoDoble *aux = lista->header;
    for(int i = 0; i < pos; i++)
        aux = aux->sig;
    aux->prev->sig = pongo;
    aux->sig->prev = pongo;
    pongo->sig = aux->sig;
    pongo->prev = aux->prev;
    free(aux);
}

void printD(ListaDoble *lista) {
    NodoDoble *aux = lista->header;
    while(aux!=NULL)
    {
        printf("%d \t",aux->num);
        aux = aux->sig;
    }
    printf("\n");
}

ListaDoble *Ej6(int *vector1, int *vector2) {
    ListaDoble *lista = newListaDoble(NULL);
    NodoDoble *aux = NULL;
    for(int i = 0; vector1[i] != -1; i++)
    {
        for(int j = 0; vector2[j] != -1; j++)
        {
            if(vector1[i] == vector2[j])
            {
                if(lista->header == NULL)
                {
                    lista->header = newNodoDoble(vector1[i], NULL, NULL);
                    aux = lista->header;
                }
                else
                {
                    aux->sig = newNodoDoble(vector1[i], aux, NULL);
                    aux = aux->sig;
                }
            }
        }
    }
    return lista;
}

