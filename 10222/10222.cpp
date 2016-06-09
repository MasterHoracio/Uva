#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

int main(){
	char str[100000];
	map<char,char>mp;
	int len;
	char Board[47] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 91, 93, 92,
                     'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 59, 39,
                     'z', 'x', 'c', 'v', 'b', 'n', 'm', 44, 46, 47,
                     '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 45, 61} ;
    for(int i = 2; i < 48; i++)
    	mp[Board[i]] = Board[i - 2];
	while(gets(str)){
		len = strlen(str);
		for(int i = 0; i < len; i++){
			if(str[i] == ' ' || str[i] == '\n')
				printf("%c",str[i]);
			else{
				if(str[i] >= 65 && str[i] <= 90)
					printf("%c",mp[str[i]+32]);
				else
					printf("%c",mp[str[i]]);
			}
		}printf("\n");
	}
	return 0;
}