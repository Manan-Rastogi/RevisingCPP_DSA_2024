#include<bits/stdc++.h> 
using namespace std;

class Complex {
	int real, img;
	public:
		void getData(){
			cout<<"Real = "<< real << endl;
			cout<<"Img = "<< img <<endl;
		}

		void setData(int a, int b){
			real= a;
			img= b ;
		}

		void updateImg(int d){
			img= d;
		}

};

int main(){
	Complex c1;
	Complex* c2 = &c1;
	c1.setData(1, 54);
	c1.getData();

	(*c2).getData();
	c2->getData();                // dereference pointer to run functions using ->


	Complex *c3 = new Complex;
	c3 = &c1;
	c3->getData();

	c1.updateImg(221);
	c1.getData();
	c2->getData();

	return 0;
}