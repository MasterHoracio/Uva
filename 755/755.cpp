#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

string directorio[100000];

char change(char c){
    if(c == 'A' || c == 'B' || c == 'C')
        return '2';
    else if(c == 'D' || c == 'E' || c == 'F')
        return '3';
    else if(c == 'G' || c == 'H' || c == 'I')
        return '4';
    else if(c == 'J' || c == 'K' || c == 'L')
        return '5';
    else if(c == 'M' || c == 'N' || c == 'O')
        return '6';
    else if(c == 'P' || c == 'R' || c == 'S')
        return '7';
    else if(c == 'T' || c == 'U' || c == 'V')
        return '8';
    else if(c == 'W' || c == 'X' || c == 'Y')
        return '9';
    else
        return c;
}

int main()
{
    int cases,len,n,leng;
    char str[100];
    string number;
    scanf("%d",&cases);
    while(cases--){
        leng = 0;
        map <string,int> repeat;
        scanf("%d",&n);
        getchar();
        for(int i = 0; i < n; i++){
            gets(str);
            number = "";
            len = strlen(str);
            for(int j = 0; j < len; j++){
                if(str[j] == '-')
                    continue;
                else
                    number += change(str[j]);
            }
            number.insert(3,"-");
            repeat[number]++;
            if(repeat[number] == 2)
                directorio[leng++] = number;
        }
        sort(directorio,directorio+leng);
        if(leng == 0)
            printf("No duplicates.\n");
        else{
            for(int i = 0; i < leng; i++)
                printf("%s %d\n",directorio[i].c_str(),repeat[directorio[i]]);
        }
        if(cases != 0)
            printf("\n");
    }
    return 0;
}
