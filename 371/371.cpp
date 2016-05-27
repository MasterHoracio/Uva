#include <cstdio>
#define MAX -1

using namespace std;

typedef long long ll;
ll contador;

ll ackfun(ll n){
    while(1){
        if(n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        if(n == 1)
            break;
        contador++;
    }
    return contador + 1;
}

int main()
{
    ll inf, sup, maximo, numero, numeromaximo, aux;
    while(scanf("%lld %lld",&inf,&sup)){
        if(inf == 0 && sup == 0)
            break;
        if(inf > sup){
            aux = sup;
            sup = inf;
            inf = aux;
        }
        maximo = MAX;
        for(ll i = inf; i <= sup; i++){
            contador = 0;
            numero = ackfun(i);
            if(numero > maximo){
                numeromaximo = i;
                maximo = numero;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",inf,sup,numeromaximo,maximo);
    }
    return 0;
}
