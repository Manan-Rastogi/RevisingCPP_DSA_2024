#include<bits/stdc++.h> 

using namespace std;

int main(){
	int n;
	cin>>n; 

	vector<int> v(n);

	for(int i=0; i<n; i++){
		cin>>v[i];
	}


	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}

	int min = *min_element(v.begin(), v.end());
	cout<<"\nMin Element= "<<min;

	int max = *max_element(v.begin(), v.end());
	cout<<"\nMax Element= "<<max;

	int sum = accumulate(v.begin(), v.end(), 0);        // 0-> initial sum
	cout<<"\nSUM= "<<sum;

	int count1 = count(v.begin(), v.end(), 1);
	cout<<"Count of 1= "<<count1<<endl;

	auto it= find(v.begin(), v.end(), 1);
	if (it != v.end())
		cout<<"Element found at "<<*it<<endl;
	else
		cout<<"Element Not Found";

	cout<<"Reverse:"<<endl; 
	reverse(v.begin(), v.end());           // Works for string as well.
	for(auto val:v){
		cout<<val<<" ";
	}
	cout<<endl;

	

	return 0;
}