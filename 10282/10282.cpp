#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int main(){
	string str,index,result,q;
	char cad[100];
	map <string,string> mp;
	while(gets(cad)){
		if(strlen(cad) == 0)
			break;

		result = strtok(cad," ");
		index = strtok(NULL," ");
		mp[index] = result;
	}

	while(gets(cad)){
		str = cad;
		q = mp[str];
		if(q.length() == 0)
			printf("eh\n");
		else
			printf("%s\n",q.c_str());
	}

	return 0;
}