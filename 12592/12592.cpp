#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
	map <string, string> slogan;
	string prince, people;
	int n, q;
	
	cin >> n;
	getchar();
	
	for(int i = 0; i < n; i++){
		getline(cin, prince);
		getline(cin, people);
		slogan[prince] = people;
	}
	
	cin >> q;
	getchar();
	
	for(int i = 0; i < q; i++){
		getline(cin, prince);
		cout << slogan[prince] << "\n";
	}
	
	return 0;
}
