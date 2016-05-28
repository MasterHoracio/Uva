#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int n, sumatoria, promedio, k, cases = 0;
    while(scanf("%d",&n) && n){
        cases++;
        int pilas[n];sumatoria = k = 0;
        for(int i = 0; i < n; i++)
            scanf("%d",&pilas[i]), sumatoria += pilas[i];
        promedio = sumatoria / n;sort(pilas,pilas+n);
        for(int i = n - 1; i >= 0; i--){
            if(pilas[i] > promedio)
                k += pilas[i] - promedio;
            else
                break;
        }
        printf("Set #%d\n",cases);
        printf("The minimum number of moves is %d.\n\n",k);
    }
    return 0;
}
