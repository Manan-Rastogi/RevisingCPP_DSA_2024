#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[5] = {1000, 4, 6, 2, 8};

	sort(a+1, a+4);

	for(int i=0; i<5; i++){
		cout << a[i] <<" ";
	}
	cout << endl;


	vector<int> v;
	v.push_back(6465);
	v.push_back(543);
	v.push_back(5325);
	v.push_back(55);
	v.push_back(5243);

	sort(v.begin() + 1, v.end());

	for(int i=0; i<5; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

}