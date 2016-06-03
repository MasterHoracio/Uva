#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
	char str[50];
	while(scanf("%s",str)){
		if(strcmp(str,"#") == 0)
			break;
		if(!next_permutation(str,str+strlen(str))){
			printf("No Successor\n");
		}else{
			printf("%s\n",str);
		}
	}
	return 0;
}