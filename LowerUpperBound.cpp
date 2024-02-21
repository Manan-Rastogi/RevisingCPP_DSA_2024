#include<bits/stdc++.h>

using namespace std;

// Lower Bound will return given element if present or next greater element;

// Upper Bound will return greater element

// For arrays , vectors these 2 are logN functions

// For maps and sets they are O(N) (internal working- GOOGLE)

// so in case of sets and maps use their inbuilt func. s.lower_bound(x)

int main(){
	int a[10] = {1, 4, 6, 8, 9, 99, 111, 211, 424, 10000};

	int *ptr= lower_bound(a, a+10, 7);
	if (ptr != (a+10)){                           // if an element which is not present and its greater element is also not present. It returns a garbage value
		cout<<*ptr<<endl;
	}

	int *uptr = upper_bound(a, a+10, 7);        
	cout<<*uptr<<endl;

	return 0;
}