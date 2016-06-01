#include <cstdio>
#include <cstring>
#define MAX 10000

using namespace std;

int main(){
    char str[MAX];
    int tam, aux = 0;
    while(gets(str)){
        tam = strlen(str);
        for(int i = 0; i < tam; i++){
            if(str[i] == '"'){
                aux++;
                if(aux % 2 == 0)
                    printf("''");
                else
                    printf("``");
            }else
                printf("%c",str[i]);
        }printf("\n");
    }
    return 0;
}
