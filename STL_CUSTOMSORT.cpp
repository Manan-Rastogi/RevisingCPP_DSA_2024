#include<bits/stdc++.h>
using namespace std;

// If it returns false the sort will swap else sort will not swap.
bool cmp(pair<int, int> a, pair<int, int> b){
	if (a.first != b.first){
		if (a.first > b.first) return true;
		return false;
	}else{
		if (a.second < b.second) return true;
		return false;
	}
}

// Trick to remember is to return what order you want
bool compare(pair<int, int> a, pair<int, int> b){
	if (a.first != b.first){
		return a.first < b.first;           // ascending order (1st < 2nd)
	} else{
		return a.second < b.second;
	}
}

int main(){
	vector<pair<int,int> > vp;

	vp.push_back({1, 9});
	vp.push_back({-1, 4});
	vp.push_back({5, 7});
	vp.push_back({6, 3});
	vp.push_back({2, 3});
	vp.push_back({7, 3});
	vp.push_back({1, -9});
	vp.push_back({-1, -9});

	sort(vp.begin(), vp.end(), compare);

	for(int i=0; i<vp.size(); i++){
		cout<<vp[i].first<<" - "<<vp[i].second<<endl;
	}

}