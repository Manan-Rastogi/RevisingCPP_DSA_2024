#include<bits/stdc++.h>

using namespace std;

// Selection Sort
void SelectionSort(int a[], int n){
	for(int i=0;i<n;i++){
		int min_index=i;                     // Taking 1st element as min
		for (int j=i+1; j<n;j++){
			if (a[j] < a[min_index]){        // searching for lin from next element
				min_index = j;
			}
		}
		swap(a[i], a[min_index]);            // Replace curr element with element at min index
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	// TC- O(n^2)
}



// Merge Sort

void merge(int s, int m, int e, int *arr){

	// Let's split it in 2 halves
	int l_sz = m - s + 1;
	int r_sz = e - m;

	int l_arr[l_sz + 1], r_arr[r_sz + 1];

	for(int i=s; i<=e; i++){
		if (i <=m){
			l_arr[i-s] = arr[i];
		}else{
			r_arr[i-m-1] = arr[i];
		}
	}

	l_arr[l_sz] = r_arr[r_sz] = INT_MAX;

	// Let's Merge the Splitted Arrays
	int l_i = 0;
	int r_i = 0;
	int k = s;

	while (k<=e){
		if (l_arr[l_i] <= r_arr[r_i]){
			arr[k] = l_arr[l_i];
			l_i++;
		}else{
			arr[k] = r_arr[r_i];
			r_i++;
		}
		k++;
	}
}


void mergeSort(int *a, int s, int e){
	if (s==e) return;
	int m= s+(e-s)/2;
	
	mergeSort(a, s, m);
	mergeSort(a, m+1,e);

	merge(s, m, e, a);
}



int main(){
	int n;
	cin>>n;

	int a[n];

	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	
	// SelectionSort(a, n);


	mergeSort(a, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;

	return 0;
}