#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

// TC= O(n) SC=O(1)
void reverse(int *arr, int n){
	int i=1, j=n;

	while(j>i){
		arr[i] = arr[i] ^ arr[j];
		arr[j] = arr[j] ^ arr[i];
		arr[i] = arr[i] ^ arr[j];
		i++; j--;
	}
}

int main(){
	int arr[N];
	int n; cin>>n; 

	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}

	cout<<"Size= " << sizeof(arr)<<endl;
	cout<<"Elements= "<<sizeof(arr)/sizeof(arr[0])<<endl;

	// Reversing the array

	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}

	cout<<endl;
	reverse(arr, n);

	for(int i=1;i<=n;i++){
		cout<<arr[i]<<" ";
	}
}