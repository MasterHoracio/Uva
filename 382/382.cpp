#include <cstdio>
#include <cmath>

using namespace std;

int getSumatoria(int n){
    int sq = (int) sqrt(n) + 1;
    int sumatoria = 0;
    for (int i = 1; i < sq; i++){
        if (n % i == 0 && i*i!=n)
            sumatoria += (i + (n / i));
        if(n % i == 0 && i*i==n)
           sumatoria += i;
    }
    sumatoria -= n;
    return sumatoria;
}

int main()
{
    int num,sum;

    printf("PERFECTION OUTPUT\n");
    while (scanf("%d", &num), num){
        sum = getSumatoria(num);
        if(num == sum)
            printf("%5d  PERFECT\n",num);
        if(sum < num)
            printf("%5d  DEFICIENT\n",num);
        if(sum > num)
            printf("%5d  ABUNDANT\n",num);
    }
    printf("END OF OUTPUT\n");

    return 0;
}
