#include <cstdio>
#include <iostream>
#include <cstring>
#define MAX 1000000

using namespace std;

int main()
{
    char str[MAX], *aux;
    int tam,contador;
    bool letra;
    while(cin.getline(str,MAX)){
        contador = 0;
        aux = strtok(str," ");
        while(aux != NULL){
            letra = false;
            tam = strlen(aux);
            for(int i = 0; i < tam; i++){
                if( (aux[i] >= 65 && aux[i] <= 90) || (aux[i] >= 97 && aux[i] <= 122) ){
                    if(!letra){
                        contador++;
                        letra = true;
                    }
                }else{
                    letra = false;
                }
            }
            aux = strtok(NULL," ");
        }
        printf("%d\n",contador);
    }
    return 0;
}
