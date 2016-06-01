#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#define MAXC 30

using namespace std;

map<char,char> parent;
map<char,int> n_nod;
bool adyacente[MAXC];

struct pareja{
    char p;
    char q;
};

char Find(char c){
    if(parent[c] == c)
        return parent[c];
    else
        return Find(parent[c]);
}

void Union(char p, char q){
    int rp, rq;
    rp = Find(p);rq = Find(q);
    if(n_nod[rp] > n_nod[rq])
        parent[rq] = rp;
    else if(n_nod[rq] > n_nod[rp])
        parent[rp] = rq;
    else{
        parent[rp] = rq;
        n_nod[rq]++;
    }
}

int main()
{
    int cases, tree, acorns;
    char puntos[55], c;
    queue <pareja> edges;
    pareja pa;
    scanf("%d",&cases);
    while(cases--){
        getchar();
        parent.clear();n_nod.clear();
        tree = acorns = 0;
        fill(adyacente,adyacente+MAXC,false);
        while(getchar() == '('){
            pa.p = getchar();
            getchar();
            pa.q = getchar();
            getchar();getchar();
            adyacente[pa.p - 'A'] = true;
            adyacente[pa.q - 'A'] = true;
            edges.push(pa);
        }
        while((c = getchar()) == '*');
        scanf("%s",puntos);
        for(int i = 0; i < strlen(puntos);i++){
            if( (i + 1) % 2 != 0){
                parent[puntos[i]] = puntos[i];
                n_nod[puntos[i]] = 0;
            }
        }
        while(!edges.empty()){
            pa = edges.front();
            edges.pop();
            Union(pa.p,pa.q);
        }
        for(int i = 0; i < strlen(puntos); i++){
            if( (i + 1) % 2 != 0){
                if(adyacente[puntos[i] - 'A'])
                    tree += Find(puntos[i]) == puntos[i];
                else
                    acorns++;
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n", tree, acorns);
    }
    return 0;
}
