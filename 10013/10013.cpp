#include <cstdio>

using namespace std;

int n1[1000000];
int n2[1000000];
int re[1500000];

int main()
{
    int cases, len, carry, sum;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d",&len);
        for(int i = 0; i < len; i++)
            scanf("%d %d",&n1[i],&n2[i]);
            carry = 0;
        for(int i = len - 1; i >= 0; i--){
            sum = n1[i] + n2[i] + carry;
            if(sum > 9){
                re[i] = sum % 10;
                carry = 1;
            }else{
                re[i] = sum;
                carry = 0;
            }
        }
        for(int i = 0; i < len; i++)
            printf("%d",re[i]);
        printf("\n");
        if(cases != 0)
            printf("\n");
    }
    return 0;
}
