//
// Created by Juani on 21/6/2023.
//

#ifndef EJPARCIAL24_6_22_LISTAS_H
#define EJPARCIAL24_6_22_LISTAS_H

typedef struct nodoSimple
{
    int num;
    struct nodoSimple *sig;
}NodoSimple;
typedef struct nodoDoble
{
    int num;
    struct nodoDoble *sig;
    struct nodoDoble *prev;
}NodoDoble;
typedef struct listaSimple
{
    NodoSimple *header;
}ListaSimple;
typedef struct listaDoble
{
    NodoDoble *header;
}ListaDoble;
NodoSimple *newNodoSimple(int, NodoSimple*);
NodoDoble *newNodoDoble(int, NodoDoble*, NodoDoble*);
ListaSimple *newListaSimple(NodoSimple*);
ListaDoble *newListaDoble(NodoDoble*);
void Ej1(ListaSimple*, ListaSimple*);
int* Ej2(ListaSimple*, ListaSimple*);
void Ej3(ListaSimple*);
void printS(ListaSimple*);
int* Ej4(int*, int*);
void Ej5(ListaDoble*, NodoDoble*, int);
void printD(ListaDoble*);
ListaDoble *Ej6(int*, int*);
#endif //EJPARCIAL24_6_22_LISTAS_H