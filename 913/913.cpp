#include <cstdio>

using namespace std;

typedef long long ll;

ll formula(ll n){
    return (n * (n + 2))/2;
}

int main()
{
    ll n, res;
    while(scanf("%lld",&n) != EOF){
        res = formula(n);
        printf("%lld\n",res + res - 2 + res - 4);
    }
    return 0;
}
