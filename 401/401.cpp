#include <cstdio>
#include <cstring>
#define MAX 20

using namespace std;

bool check_Palindrome(char *palabra){
    int tam = strlen(palabra);
    char cpypalabra[MAX];
    strcpy(cpypalabra,palabra);
    for(int i = 0; i < tam; i++){
        if(palabra[i] == cpypalabra[tam - i - 1])
            continue;
        else
            return false;
    }
    return true;
}

bool check_Mirrored(char *palabra, char*mipalabra){
    int tam = strlen(palabra);
    for(int i = 0; i < tam; i++){
        if(palabra[i] == mipalabra[tam - i - 1])
            continue;
        else
            return false;
    }
    return true;
}

char getReverse(char letra){
    switch(letra){
        case 'A':
            return 'A';
        break;
        case 'H':
            return 'H';
        break;
        case 'I':
            return 'I';
        break;
        case 'M':
            return 'M';
        break;
        case 'O':
            return 'O';
        break;
        case 'T':
            return 'T';
        break;
        case 'U':
            return 'U';
        break;
        case 'V':
            return 'V';
        break;
        case 'W':
            return 'W';
        break;
        case 'X':
            return 'X';
        break;
        case 'Y':
            return 'Y';
        break;
        case 'E':
            return '3';
        break;
        case '3':
            return 'E';
        break;
        case 'J':
            return 'L';
        break;
        case 'L':
            return 'J';
        break;
        case 'S':
            return '2';
        break;
        case '1':
            return '1';
        break;
        case '2':
            return 'S';
        break;
        case 'Z':
            return '5';
        break;
        case '5':
            return 'Z';
        break;
        case '8':
            return '8';
        break;
        default:
            return ' ';
    }
}

int main()
{
    char str[MAX], strmi[MAX];
    int tam;
    bool isPalindrome, isMirrored;
    while(scanf("%s",str) != EOF){
        isPalindrome = isMirrored = false;
        tam = strlen(str);
        isPalindrome = check_Palindrome(str);
        strcpy(strmi,str);
        for(int i = 0; i < tam; i++)
            strmi[i] = getReverse(str[i]);
        isMirrored = check_Mirrored(str,strmi);
        if(!isMirrored && !isPalindrome)
            printf("%s -- is not a palindrome.\n\n",str);
        else if(!isMirrored && isPalindrome)
            printf("%s -- is a regular palindrome.\n\n",str);
        else if(isMirrored && !isPalindrome)
            printf("%s -- is a mirrored string.\n\n",str);
        else
            printf("%s -- is a mirrored palindrome.\n\n",str);
    }
    return 0;
}
