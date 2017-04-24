#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

const char combinations [13][4]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
const int value [13] {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

string convertion(int n){
	string roman = "";
	
	for(int i = 0; i < 13; i++){
		while(n >= value[i]){
			if(strlen(combinations[i]) == 1){
				roman += combinations[i][0];
			}else{
				roman += combinations[i][0];
				roman += combinations[i][1];
			}
			n -= value[i];
		}
	}
	return roman;
}

void memo(map <int, string> &romans, map <string, int> &arabic){
	for(int i = 1; i <= 4000; i++){
		romans[i] = convertion(i);
		arabic[romans[i]] = i;
	}
}

int main(){
	map <int, string> romans;
	map <string, int> arabic;
	char str[45];
	int num;
	
	memo(romans, arabic);
	
	while(scanf("%s",str) != EOF){
		(str[0] >= '0' && str[0] <= '9') ? printf("%s\n",romans[atoi(str)].c_str()) : printf("%d\n",arabic[str]);
	}
	
	return 0;
}
