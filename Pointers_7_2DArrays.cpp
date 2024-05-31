#include<bits/stdc++.h>
using namespace std;

int main(){
	// dynamic allocation for 2D array
	int n, m; cin>>n>>m; 

	int** arr= new int*[n];  // pointer to pointer to access each row as a dynamic 1D array.

	for(int i=0;i<n;i++){
		arr[i] = new int[m];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}


	// Release Memory
	for(int i=0;i<n;i++){
		delete []arr[i];
	}
	delete []arr;
}