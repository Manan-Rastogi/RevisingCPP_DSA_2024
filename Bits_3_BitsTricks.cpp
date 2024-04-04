#include<bits/stdc++.h> 
using namespace std;


void printBinary(int n){
    for(int i = 10; i >= 0; i--){
        cout << ((n >> i) & 1); 
    }
    cout << endl; 	
}


int main(){
	//////////////////// Even odd Check
	// observe 0th bit - even have 0, odd have 1
	for(int i=0;i<19;i++){
		if (i&1) {
			cout<<i<<" - Odd\n";
		}else{
			cout<<i<<" - Even\n";
		}
	}

	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
	
	///////////////////// Multiply Divide by 2
	int n = 5;
	cout<<n<<endl;
	n = n >> 1;    // n/2
	cout<<n<<endl;

	n = n << 1;    // n*2 
	cout<<n<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

	///////////////////// Upper Lower Case Conversion
	printBinary('A');
	printBinary('a');

	printBinary('Y');
	printBinary('y');

	// Observe binaries. small chars have 1 after leftmost 1 of Caps.
	// Observing More - 5th bit is set in smalls while not set in Caps.

	char T= 't';
	char t= T | (1<<5);
	cout<<t<<endl;
	cout<<char(t & ~(1<<5))<<endl;

	// Observing More - char(1<<5) is a singe space ' ', char(1011111) is _ {only consider no of 1 we require for chars}
	cout<<char('X' | ' ')<<endl;
	cout<<char('k' & '_')<<endl;


	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

	//////////////////////// Clear LSB's
	printBinary(59);
	// unset all bits till 4th digit.
	int ic = 4; //0 to 4

	printBinary(59 & (~((1<<(ic+1))-1)));
	// 00000111011 &  00000100000 or 11111100000


	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";

	//////////////////////// Clear MSB's
	printBinary(59);
	ic = 3;
	printBinary(59 & ((1<<(ic+1))-1));
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";


	//////////////////// Check Power of 2

	int ch=15;

	cout<<((ch & (ch-1)) == 0);

	return 0;

}