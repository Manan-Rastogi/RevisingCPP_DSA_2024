#include<bits/stdc++.h> 
using namespace std;

bool is_positive(int x){
	return x>0;
}

int main(){
	// ********************************* Lambda Function
	cout<< [](int x){return x+2;}(7) << endl;
		//    param  return     (value of x)

	auto sum = [](int x, int y){return x + y;};

	cout<<sum(2, 77)<<endl;



	vector<int> v = {2, 4, 6, 8, 0, 10};

	cout<<all_of(v.begin(), v.end(), [](int x){return x%2==0;})<<endl;          
	// return true if func returns true for all values in array.

	cout<<any_of(v.begin(), v.end(), is_positive)<<endl;


	cout<<none_of(v.begin(), v.end(), is_positive)<<endl;	


	return 0;
}

