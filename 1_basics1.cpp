#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<"Hello"<<"\n";

	//////////////// Datatypes

	// char, int, float, double, bool
	char c='a';
	int a=2;
	float b= 2.3;
	a= 2.3;

	double z= 1.76;
	bool d= true;

	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<z<<"\n";

	// long int, long long int
	long long x=12000009;
	cout<<x<<endl;


	//// Precedence

	// DTs
	// double > float > long long int > long int > int > char
	cout<<'c' + 2<<endl;
	cout<<7/2<<endl;
	cout<<7/2.0<<endl;


	///// Rough Ranges
	// -1e9 < int < 1e9
	// -1e12 < long int < 1e12
	// -1e18 < long long int < 1e18

	// int overflow
	int max_int= INT_MAX;
	cout<<max_int<< "\n" ;
	cout<<max_int + 1 << "\n";           // Cycle back to -ve

	int A= 100000;
	int B= 100000;

	long int C= A*B;            // A and B are int so their prod is int which can not be calculated here inspite C is long bcus A*B will be calculated as int.
	cout<<C<<endl;


	long long int Cll= A * 1LL * B;  
	cout<<Cll<<endl; 

	double aa= 100000;
	double bb= 100000;

	double cc= aa * bb;
	cout<<cc<<endl;           // scientific notation
	cout<< fixed << setprecision(0) <<cc<<endl;    // fixed- remove scientific notation

	
	// string and getline
	string str1;
	cin >> x;
	cin.ignore();     // getline reads from current posn of cursor. Use this to ignore curr line and get from next line.
	getline(cin, str1);
	cout<<str1<<endl;


	// Arrays
	int arr[10];
	arr[11] = 10;          // Undefined behaviour. Might not work in other systems or online platform. Avoid using it.
	cout<<arr[11]<<endl;

	char sarr[10];

	// Locally you can create an arr of max size around 1e5. Any bigger array will give segmentation fault.
	// You can create higher size (around 1e7) arr Globally with const arr size.


	// Online Judges TC - 1e7-1e8 iters in 1 sec

	// Avg time :
	// 1e7- 1sec
	// 1e8- 10sec
	// 1e9- 100sec
	// 1e10- 1000sec
	// 1e11- 10000sec


	
		
}	
