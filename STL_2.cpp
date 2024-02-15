#include<bits/stdc++.h> 

using namespace std;

// iterators
int main(){

	// it -> iterator
	// *it -> value
	// v.begin() -> v[0]
	// v.end() -> next to last element in container
	// it++ -> moves to next iterator.         (works on maps and sets)
	// it+1 -> moves to next location.		   (doesnot work on maps and sets)

	vector<int> v = {1, 3, 5, 6, 8, 9};

	vector<int> :: iterator it = v.begin();

	cout<<(*it)<<endl;
	cout<<(*(it+1))<<endl;


	vector<pair<int, int >> vp = {{1,3}, {2,3}, {4,5}, {3,8}};
	vector<pair<int, int >> :: iterator it_vp;

	for(it_vp=vp.begin(); it_vp!=vp.end(); it_vp++){
		cout<<(*it_vp).first<<" - "<<(*it_vp).second<<endl;       // 1st syntax for pairs
		cout<<it_vp->first<<" - "<<it_vp->second<<endl;           // 2nd syntax for pairs
	}




	/////////////                 auto iterator and ranged loops              /////////////////
	for(int value: v){            // value is copy of the original value. Use &value for accessing via reference.
		cout<<value<<endl;		
	}

	auto x = 1.03;                // automatically takes datatype
	cout<<x<<endl;


	for(auto i=vp.begin(); i!=vp.end(); i++){
		cout<<(*i).first<<" - "<<(*i).second<<endl;      
	}



	return 0;
}