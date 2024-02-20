#include<bits/stdc++.h>
using namespace std;



int main() {
	int num;
	cin >> num;    
	map<int, multiset<string> > ms;
	while(num--){
		string s;
		int x;
		cin>>s>>x;
		ms[x].insert(s);
	}

	auto it = ms.rbegin();
    while (it != ms.rend()) { 
        auto &names = it->second;
        for(auto n:names){
        	cout<<n<<" "<<it->first<<endl;
        }
        it++;
    }
}