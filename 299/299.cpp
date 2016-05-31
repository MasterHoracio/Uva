#include <cstdio>

using namespace std;

int main()
{
    int cases,n,moves,temp;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&n);moves = 0;
        int train[n];
        for(int i = 0; i < n; i++)
            scanf("%d",&train[i]);
        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(train[j] > train[j + 1]){
                    temp = train[j];
                    train[j] = train[j + 1];
                    train[j + 1] = temp;
                    moves++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",moves);
    }
    return 0;
}
