#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(){
	char str[100000];
	string s,t,res;
	int lent,lens,j;
	while(gets(str)){
		s = strtok(str," ");
		t = strtok(NULL," ");
		lent = t.length();
		lens = s.length();
		j = 0;res = "";
		for(int i = 0; i < lent && j < lens; i++){
			if(t[i] == s[j]){
				res += s[j];
				j++;
			}
		}
		if(res.compare(s) != 0)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}