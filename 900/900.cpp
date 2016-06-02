#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll fiv[51];

int main()
{
    ll n;
    fill(fiv,fiv+51,-1);
    fiv[1] = 1, fiv[2] = 2;
    for(ll i = 3; i < 51; i++)
        fiv[i] = fiv[i - 1] + fiv[i - 2];
    while(scanf("%lld",&n) && n)
        printf("%lld\n",fiv[n]);

    return 0;
}
