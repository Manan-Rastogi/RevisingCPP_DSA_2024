#include<bits/stdc++.h> 
using namespace std;

// we want precision to be 5, So eps is set 1 higher
double eps = 1e-6;

int main(){
	double x;
	int n;
	cin>>x>>n;

	double lo=1, hi=x, mid=-1;

	while(hi - lo > eps){
		mid = lo + (hi-lo)/2;

		if (pow(mid, n) < x){
			lo=mid;
		}else{
			hi=mid;
		}
	}

	// TC - n*log(N*(10^d)) d-> decimals (precison), n -> nth root. N->x


	cout<<mid<<endl;

	return -1;
}
