#include<bits/stdc++.h>

using namespace std;

// Stack - LIFO 
// Use: Implement Recursion internally.


// Queue - FIFO 
// Use: BFS, DFS


int main(){
	stack<int> stk;

	stk.push(1);
	stk.push(10);
	stk.push(1);
	stk.push(100);
	stk.push(1000);         // LIFO

	while(!stk.empty()){
		cout<<stk.top()<<"\n";
		stk.pop();
	}



	queue<string> qu;
	qu.push("abc");
	qu.push("def");
	qu.push("abc");
	qu.push("xcd");
	qu.push("ageu");

	while(!qu.empty()){
		cout<<qu.front()<<"\n";
		qu.pop();
	}


	return 0;
}