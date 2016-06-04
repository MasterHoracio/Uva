#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[80];
    int cases, tam, j, res;
    bool o;
    scanf("%d",&cases);
    getchar();
    while(cases--){
        gets(str);
        tam = strlen(str);
        res = j = 0;
        o = false;
        for(int i = 0; i < tam; i++){
            if(str[i] == 'O')
                o = true;
            else{
                o = false;
                j = 0;
            }
            if(o)
                res += ++j;
        }
        printf("%d\n",res);
    }
    return 0;
}
