#include "ListaCircular.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

typedef struct _lista{
    int size;
    TNo *inicio;
}TListaCircular;

TNo *Create_No(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo != NULL)
        novo->info = info;
    return novo;
}
TListaCircular *Create_List()
{
    TListaCircular *novo = malloc(sizeof(TListaCircular));
    if(novo != NULL){
        novo->inicio = NULL;
        novo->size = 1;
    }
    return novo;
}
_Bool Insert_List_End(TListaCircular *lista, int info)
{
    TNo *nova = Create_No(info);
    if(nova == NULL)    return false;
    if(lista->inicio == NULL)   lista->inicio = nova;
    else{
        TNo *aux = lista->inicio;
        while(aux->prox != lista->inicio){
            aux = aux->prox;
        }
        aux->prox = nova;
    }
    nova->prox = lista->inicio;
    lista->size++;
    return true;
}
void Remove_List_Begin(TListaCircular *lista)
{
    TNo *suc = lista->inicio;
    TNo *final = lista->inicio;
    suc = suc->prox;
    while(final->prox != lista->inicio)
        final = final->prox;
    lista->inicio = suc;
    final->prox = suc;
}
void Remove_List_End(TListaCircular *lista)
{
    TNo *ant;
    TNo *final = lista->inicio;
    while(final->prox != lista->inicio){
        ant = final;
        final = final->prox;
    }
    ant->prox = lista->inicio;
}
int Calculo_Posicao(TListaCircular *lista, int pos, int tamanho)
{
    if(lista->inicio == NULL)   return -1;
    else{
        TNo *aux = lista->inicio;
        TNo *antecessor;
        TNo *sucessor;
        for(int i = 0; i < pos; i++){
            antecessor = aux;
            aux = aux->prox;
            sucessor = aux->prox;
        }
        do{
            if(aux == lista->inicio){
                Remove_List_Begin(lista);
                aux = aux->prox;
            }
            else if(aux->prox == lista->inicio){
                Remove_List_End(lista); 
                aux = lista->inicio;
                }
            else{
                aux = sucessor;
                antecessor->prox = sucessor;       
            }
            for(int i = 0; i < pos; i++){
                antecessor = aux;
                aux = aux->prox;
                sucessor = aux->prox;
            }
            tamanho--;
        }while(tamanho > 1);
    return aux->info;
    }
}
void Print_List(TListaCircular *lista)
{   
    TNo *aux = lista->inicio;
    do{
        printf("%d ", aux->info);
        aux = aux->prox;
    }while(aux != lista->inicio);
}
void Destroy_List(TListaCircular *lista)
{
    TNo *aux = lista->inicio;
    TNo *outro;
    while(aux->prox != lista->inicio){
        outro = aux->prox;
        free(aux);
        aux = aux->prox;
    }
    lista->inicio = NULL;
}