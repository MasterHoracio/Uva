#include <cstdio>
#define M 4
#define N 7500

using namespace std;

typedef long long ll;
ll s[]={5,10,25,50};
ll ways[N] = {1,1,1,1,1};

/*ll cuenta(ll n, ll m){
    if(n < 0 || m < 0)
        return 0;
    if(n == 0)
        return 1;
    return cuenta(n,m - 1) + cuenta(n - s[m], m);
}*/
void cuenta(){
    for(int i = 5; i < N; ++i)
        ways[i] = ways[i - 1];
    for(int i = 0; i  < M; ++i)
        for(int j = s[i]; j < N; ++j)
            ways[j] += ways[j - s[i]];
}

int main()
{
    ll n;
    cuenta();
    while(scanf("%lld",&n) != EOF)
        printf("%lld\n",ways[n]);
    return 0;
}
