#include<bits/stdc++.h>
using namespace std;

// Binary Search can be applied on :
// Monotonic Function: funx that keeps an order intact. Eg: 1 2 3 4 5 OR  5 3 2 1 0 
// Predicate Function: funx that always return true false in order. Eg F F F F T T T T (It is also monotonic)


int main(){
	int n;
	cin>>n;
	vector<int> v(n, 0);

	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	
	// Binary Search

	int x;
	cin>>x;

	int start=0, end=n-1;
	while(end - start > 1){
		int mid = start + (end-start)/2;

		if (v[mid] < x){
			start=mid+1;
		}else{
			end=mid;
		}
	}

	if (v[start] == x){
		cout<<start<<endl;
	}else if (v[end] == x){
		cout<<end<<endl;
	}else{
		cout<<"Not Found"<<endl;
	}
}
