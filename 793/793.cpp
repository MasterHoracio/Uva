#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int padre[1000000];
int nnodos[1000000];

int Find(int c){
    if(padre[c] == c)
        return c;
    else
        return Find(padre[c]);
}

void Union(int p, int q){
    int RP,RQ;
    RP = Find(p);
    RQ = Find(q);
    if(RP == RQ)
        return;
    if(nnodos[RP] > nnodos[RQ])
        padre[RQ] = RP;
    else if(nnodos[RQ] > nnodos[RP])
        padre[RP] = RQ;
    else{
        padre[RQ] = RP;
        nnodos[RP]++;
    }
}

int main()
{
    int cases, n, p, q, bien, mal, rp, rq;
    char c;
    string s;
    scanf("%d",&cases);
    while(cases--){
        bien = mal = 0;
        scanf("%d",&n);
        getchar();
            for(int i = 1; i <= n; i++)
                padre[i] = i, nnodos[i] = 0;
        while(1){
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&p,&q);
            if(c == 'c')
                Union(p,q);
            else{
                rp = Find(p);
                rq = Find(q);
                if(rp == rq)
                    bien++;
                else
                    mal++;
            }
        }
        printf("%d,%d\n",bien,mal);
        if(cases != 0)
            printf("\n");
    }
    return 0;
}
