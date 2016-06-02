#include <cstdio>
#include <cmath>
#define MAX 10000002

using namespace std;
typedef long long ll;

ll Fact[MAX];

ll calculate(){
    double logaritmo = 0;
    Fact[1] = 1;
    for(int i = 2; i < MAX; i++){
        logaritmo += log10(i);
        Fact[i] = floor(logaritmo) + 1;
    }
}

int main()
{
    ll cases, n;
    calculate();
    scanf("%lld",&cases);
    while(cases--){
        scanf("%lld",&n);
        printf("%lld\n",Fact[n]);
    }
    return 0;
}
