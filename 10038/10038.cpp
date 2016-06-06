#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, prev, dif, num;
    bool Jolly;
    while(scanf("%d",&n) != EOF){
        bool jol[n];Jolly = true;
        fill(jol,jol+n,false);
        scanf("%d",&num);
        prev = num;
        for(int i = 1; i < n; i++){
            scanf("%d",&num);
            dif = abs(prev - num);
            if(dif < 1 || dif > (n - 1) )
                Jolly = false;
            else if(jol[dif])
                Jolly = false;
            else
                jol[dif] = true;
            prev = num;
        }
        if(!Jolly)
            printf("Not jolly\n");
        else
            printf("Jolly\n");
    }
    return 0;
}
