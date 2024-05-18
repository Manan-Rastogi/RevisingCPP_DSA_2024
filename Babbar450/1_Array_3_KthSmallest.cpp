// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include<bits/stdc++.h> 
using namespace std;

// kthSmallest is using priority queue[max heap] to find kth min element. Idea is to keep the length of pq limited to k, then the front of this pq will be the answer. 
int kthSmallest_pq(int arr[], int l, int r, int k){
	priority_queue<int> pq;

	for(int i=l;i<=r;i++){
		if(pq.size() < k){
			pq.push(arr[i]);
		}else if(pq.size() == k){
			int x = pq.top();
			if(x > arr[i]){
				pq.pop();
				pq.push(arr[i]);
			}
		}
	}

	return pq.top();
}


int count_smaller_equal(int *arr, int mid, int r){
	int count= 0;
	int k=0;
	while(k<r+1){
		if(arr[k] <= mid){
			count++;
		}
		k++;
	}
	return count;
}

int kthSmallest_bs(int arr[], int l, int r, int k){
	int lo= INT_MAX, hi= INT_MIN;
	for(int i=l;i<=r;i++){
		lo= min(lo, arr[i]);
		hi= max(hi, arr[i]);
	}

	while(lo < hi){
			int mid= lo + (hi-lo)/2;

			if(count_smaller_equal(arr, mid, r) < k){
				lo= mid+1;
			}else{
				hi=mid;
			}
		}
	

	return lo;
}

int main(){
	int n; cin>>n; 

	int* arr= new int[n]; 
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	int k; cin>>k;
	

	cout<<kthSmallest_pq(arr, 0, n-1, k)<<endl;
	cout<<kthSmallest_bs(arr, 0, n-1, k);

	delete[] arr;
	return 0;
}