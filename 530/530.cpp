#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll formula(ll n, ll k){
    k = min(k,n-k);
    ll result = 1;
    for(ll i = 1; i <= k; i++)
        result = result *  (n - k + i) / i;
    return result;
}

int main()
{
    ll n,k;
    while(scanf("%lld %lld",&n,&k)){
        if(n == 0 && k == 0)
            break;
        printf("%lld\n",formula(n,k));
    }
    return 0;
}
