#include <cstdio>
#include <locale>
#include <sstream>
#include <string>

using namespace std;
int i,v,x,l,c;
string pages;

void toRomans(char num, int pos){
    int n = (int) num - 48;
    if(pos == 1){//si son unidades
        if(n < 4)
            i += n;
        else if(n == 4)
            i += 1, v += 1;
        else if(n == 5)
            v += 1;
        else if(n <= 8)
            v += 1, i += n - 5;
        else
            x += 1, i += 1;
    }else if(pos == 2){//si son decenas
        if(n < 4)
            x += n;
        else if(n == 4)
            x += 1, l += 1;
        else if(n == 5)
            l += 1;
        else if(n <= 8)
            l += 1, x += n - 5;
        else
            x += 1, c += 1;
    }else{//si son centeneas
        if(n < 4)
            c += n;
    }
}

int main()
{
    int j,p;
    while(scanf("%d",&p)){
        if(p == 0)
            break;
        i = v = x = l = c = 0;
        for(int k = 1; k <= p; k++){
            ostringstream convert;
            convert << k;
            pages = convert.str();j = 0;
            for(int i = pages.length() - 1; i >= 0; i--){
                j++;
                toRomans(pages[i],j);
            }
        }
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",p,i,v,x,l,c);
    }
    return 0;
}
