#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    int n, m;
    string st, sb, re;
    while(cin>>n>>st){
        m = -1;
        map<string,int> mp;
        map<string,int>::iterator it;
        for(int i = 0; i < st.length() - n + 1; ++i){
            sb = st.substr(i,n);
            mp[sb]++;
        }for(it = mp.begin(); it != mp.end(); it++){
            if(it->second > m){
                m = it->second;
                re = it->first;
            }
        }
        cout<<re<<endl;
    }
    return 0;
}
