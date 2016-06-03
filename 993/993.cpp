#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
ll numeros[10];

int main()
{
    ll cases, n;
    scanf("%lld",&cases);
    while(cases--){
        fill(numeros,numeros+10,0);
        scanf("%lld",&n);
        if(n < 10)
            printf("%lld\n",n);
        else{
            for(ll i = 9; i >= 2; i--){
                while(n % i == 0){
                    n /= i;
                    numeros[i]++;
                }
            }
            if(n != 1)
                printf("-1\n");
            else{
                for(ll i = 2; i < 10; i++)
                    while(numeros[i]--)
                        printf("%lld",i);
                printf("\n");
            }
        }
    }
    return 0;
}
