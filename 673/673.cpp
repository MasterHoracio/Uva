#include <cstdio>
#include <stack>
#include <cstring>
#define MAX 128

using namespace std;

int main()
{
    int cases, tam;
    bool bien;
    char str[MAX];
    stack <char> pila;

    scanf("%d",&cases);
    getc(stdin);

    while(cases--){
        bien = true;
        gets(str);
        tam = strlen(str);
        for(int i = 0; i < tam; i++){
            if(str[i] == '(' || str[i] == '[')
                pila.push(str[i]);
            else if(str[i] == ')'){
                if(pila.empty() || pila.top() != '('){
                    bien = false;
                    break;
                }
                pila.pop();
            }else if(str[i] == ']'){
                if(pila.empty() || pila.top() != '['){
                    bien = false;
                    break;
                }
                pila.pop();
            }
        }
        if(!bien || !pila.empty())
            printf("No\n");
        else
            printf("Yes\n");

        while(!pila.empty())
            pila.pop();
    }
    return 0;
}
