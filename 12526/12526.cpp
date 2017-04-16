#include <cstdio>
#include <cstring>

#define maxn 27

using namespace std;

struct nodo{
	int count;
	bool end;
	nodo *edge[27];

	nodo(){
		for(int i = 0; i < maxn; i++)
			edge[i] = NULL;
		count = 0;
		end = false;
	}
}*trie;

void _build(char word[], int len){
	nodo *temp = trie;
	int position;
	for(int i = 0; i < len; i++){
		position = word[i] - 'a';
		if(temp->edge[position] == NULL){
			temp->count += 1;
			temp->edge[position] = new nodo();
		}
		temp = temp->edge[position];
	}
	temp->end = true;
}

int _search(char word[], int len){
	nodo *temp = trie;
	int position, ans = 0;
	for(int i = 0; i < len; i++){
		position = word[i] - 'a';
		temp = temp -> edge[position];
		if(temp -> count > 1 || temp -> end == true)
			ans++;
	}
	return ans;
}

void _delete(nodo *temp){
	for(int i = 0; i < maxn; i++)
		if(temp -> edge[i])
			_delete(temp -> edge[i]);
	delete(temp);
}

int main(){
	int n, len[100005];
	double sum;
	char word[100005][85];

	while(scanf("%d",&n) != EOF){
		trie = new nodo();
		for(int i = 0; i < n; i++){
			scanf("%s",word[i]);
			len[i] = strlen(word[i]);
			_build(word[i], len[i]);
		}

		sum = 0.0;

		for(int i = 0; i < n; i++)
			sum += _search(word[i], len[i]);
		
		printf("%.2lf\n",sum/(double)n);

		_delete(trie);
	}
	return 0;
}