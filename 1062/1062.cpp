#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int computeStack(string containers){
	vector < stack <char> > pilas;
	bool check;

	for(int i = 0; i < containers.length(); i++){

		check = false;

		for(int j = 0; j < pilas.size(); j++){
			if(pilas[j].top() >= containers[i]){
				pilas[j].push(containers[i]);
				check = true;
				break;
			}
		}
		if(!check){
			stack <char> temp;
			temp.push(containers[i]);
			pilas.push_back(temp);
		}
	}

	return pilas.size();
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string containers;
	int TC = 1;

	while(getline(cin,containers) && containers != "end"){
		cout << "Case " << TC << ": " << computeStack(containers) << "\n";
		TC++;
	}

	return 0;
}