#include "ListaCircular.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    TListaCircular *L1 = Create_List();
    int m, n, i;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        Insert_List_End(L1, i);
    }
    Calculo_Posicao(L1, m, n);
    Print_List(L1);

Destroy_List(L1);
return 0;
}