#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct nodo{
    char name[20];
    int inferior;
    int superior;
};

nodo BaseDatos[10000];

bool cmp(nodo x, nodo y){
    if(x.inferior < y.inferior)
        return true;
    return false;
}

int main()
{
    int cases, db, q, query, cont;
    char str[50], res[20];
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&db);
        getchar();
        for(int i = 0; i < db; i++){
            gets(str);
            sscanf(str,"%s %d %d",BaseDatos[i].name,&BaseDatos[i].inferior,&BaseDatos[i].superior);
        }
        stable_sort(BaseDatos,BaseDatos+db,cmp);
        scanf("%d",&q);
        for(int i = 0; i < q; i++){
            scanf("%d",&query);
            cont = 0;
            for(int j = 0; j < db; j++){
                if(BaseDatos[j].inferior > query)
                    break;
                if(query > BaseDatos[j].inferior && query < BaseDatos[j].superior){
                    cont++;
                    strcpy(res,BaseDatos[j].name);
                }if(cont >= 2)
                    break;
            }
            if(cont == 0 || cont >= 2)
                printf("UNDETERMINED\n");
            else
                printf("%s\n",res);
        }
        if(cases != 0)
            printf("\n");
    }
    return 0;
}
