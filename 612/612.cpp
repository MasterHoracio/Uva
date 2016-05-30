#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 50

using namespace std;

struct nodo{
    char str[MAX];
    int fitness;
};

int ordena(char str[MAX]){
    int cont = 0, j = 0;char tmp;
    bool cambio = true;
    while(cambio){
        cambio = false;
        j++;
        for(int i = 0; i < strlen(str) - j; i++){
            if(str[i] > str[i + 1]){
                tmp = str[i];
                str[i] = str[i + 1];
                str[i + 1] = tmp;
                cambio = true;
                cont++;
            }
        }
    }
    return cont;
}

bool cmp (nodo x, nodo y){
    if ( x.fitness < y.fitness )
        return true;
    return false;
}

int main()
{
    int cases, nl, m;
    nodo n[100];char aux[MAX];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&nl,&m);
        for(int i = 0; i < m; i++){
            scanf("%s",n[i].str);
            strcpy(aux,n[i].str);
            n[i].fitness = ordena(aux);
        }
        stable_sort(n,n+m,cmp);
        for(int i = 0; i < m; i++){
            printf("%s\n",n[i].str);
        }
        if(cases != 0)
            printf("\n");
    }
    return 0;
}
