#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> v, int x) {
	int hi=v.size()-1, lo=0;
	int mid;
	while(hi - lo > 1){
		mid = lo + (hi-lo)/2;

		if (x > v[mid]){
			lo = mid + 1;
		}else{
			hi = mid;
		}
	}

	if(v[lo] >= x){
		return lo;
	}

	if(v[hi] >= x){
		return hi;
	}

	return -1;
}


int upper_bound(vector<int> v, int x) {
	int hi=v.size()-1, lo=0;
	int mid;
	while(hi - lo > 1){
		mid = lo + (hi-lo)/2;

		if (x >= v[mid]){
			lo = mid + 1;
		}else{
			hi = mid;
		}
	}

	if(v[lo] > x){
		return lo;
	}

	if(v[hi] > x){
		return hi;
	}

	return -1;
}

int main(){
	int n;
	cin>>n;
	vector<int> v(n,0);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	sort(v.begin(), v.end());


	int x;
	cin>>x;

	cout<<"Lower Bound "<<lower_bound(v, x)<<" --> "<<v[lower_bound(v,x)];

	cout<<"\nUpper Bound "<<upper_bound(v, x)<<" --> "<<v[upper_bound(v,x)];


	return 0;
}