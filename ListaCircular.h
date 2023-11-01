#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include <stdbool.h>

typedef struct _lista TListaCircular;

TListaCircular *Create_List();
_Bool Insert_List_End(TListaCircular *, int);
int Calculo_Posicao(TListaCircular *, int, int);

void Print_List(TListaCircular *);
void Destroy_List(TListaCircular *);


#endif