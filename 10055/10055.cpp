#include <cstdio>

using namespace std;

typedef long long ll;

int main()
{
    ll h, o;
    while(scanf("%lld %lld",&h,&o) != EOF){
        if(h >= o)
            printf("%lld\n",h - o);
        else
            printf("%lld\n",o - h);
    }
    return 0;
}
