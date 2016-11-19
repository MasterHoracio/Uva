#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';}

bool duplicate(string name1, string name2){
	string str1, str2;
	if(name1.length() != name2.length())
		return false;

	str1 = str2 = "";

	for(int i = 0; i < name1.length(); i++){
		if(!isVowel(name1[i]))
			str1 += name1[i];
		if(!isVowel(name2[i]))
			str2 += name2[i];
	}

	return str1 == str2;
}

int main(){
	string name1, name2;
	int TC;

	cin >> TC;

	while(TC--){
		cin >> name1 >> name2;
		(duplicate(name1, name2)) ? cout << "Yes\n" : cout << "No\n";
	}
	return 0;
}