#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
queue <ll> qu;

void getPrimeFactors(ll n){
    while(n % 2 == 0){
        qu.push(2);
        n /= 2;
    }
    for(int i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            qu.push(i);
            n /= i;
        }
    }
    if(n > 2)
        qu.push(n);
}

int main()
{
    ll n, c;
    bool negativo;
    while(scanf("%lld",&n) && n){
        negativo = false;c = 0;
        if(n  < 0)
            negativo = true, n *= -1;
        getPrimeFactors(n);
        if(negativo){
            printf("%lld = -1",n *= -1);
            while(!qu.empty()){
                printf(" x %lld",qu.front());
                qu.pop();
            }
        }
        else{
            printf("%lld = ",n);
            while(!qu.empty()){
                if(c == 0)
                    printf("%lld",qu.front());
                else
                    printf(" x %lld",qu.front());
                c++;
                qu.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
