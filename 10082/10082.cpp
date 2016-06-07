#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map <char,char> mp;

void create(){
mp[']'] = '[';
mp['['] = 'P';
mp['P'] = 'O';
mp['O'] = 'I';
mp['I'] = 'U';
mp['U'] = 'Y';
mp['Y'] = 'T';
mp['T'] = 'R';
mp['R'] = 'E';
mp['E'] = 'W';
mp['W'] = 'Q';
mp[';'] = 'L';
mp['L'] = 'K';
mp['K'] = 'J';
mp['J'] = 'H';
mp['H'] = 'G';
mp['G'] = 'F';
mp['F'] = 'D';
mp['D'] = 'S';
mp['S'] = 'A';
mp['/'] = '.';
mp['.'] = ',';
mp[','] = 'M';
mp['M'] = 'N';
mp['N'] = 'B';
mp['B'] = 'V';
mp['V'] = 'C';
mp['C'] = 'X';
mp['X'] = 'Z';
mp['='] = '-';
mp['-'] = '0';
mp['0'] = '9';
mp['9'] = '8';
mp['8'] = '7';
mp['7'] = '6';
mp['6'] = '5';
mp['5'] = '4';
mp['4'] = '3';
mp['3'] = '2';
mp['2'] = '1';
mp['1'] = '`';
}


int main()
{
    char str[100000];
    int tam;
    create();
    while(gets(str)){
        tam = strlen(str);
        for(int i = 0; i < tam; i++){
            if(str[i] == ' ')
                printf(" ");
            else if(str[i] == 92)
                printf("]");
            else if(str[i] == 39)
                printf(";");
            else
                printf("%c",mp[str[i]]);
        }printf("\n");
    }
    return 0;
}
