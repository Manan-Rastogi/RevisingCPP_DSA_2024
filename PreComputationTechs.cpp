// https://codeforces.com/contest/1426/problem/D
#include<bits/stdc++.h>
using namespace std;


/*
    1. Prefix Sum(Just Precalculate what's required)
    2. F/W and B/W Sum
    3. Hashing Technique

    4. Use Prefix Sum to store count/sum(l to r). 
        Eg: count of a from index l to r
        Soln: Presum -> in an array add 1 to index of a.
                     -> prefixsum = pf[i] <- pf[1] + .. + pf[i].
                     -> count/sum from l to r -> pf[r] - pf[l]

    5. Trick of adding k from a to b -> Check PreComputationGoodConceptQuestion.cpp
*/


int main(){
    // Input the size of the array
    int n;
    cin >> n;

    // Declare an array of long long integers
    long long int arr[n];

    // Input array elements
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Create a set to store cumulative sums and initialize other variables
    set<long long int> check;
    long long int Sum = 0; 
    int counter = 0;

    // Loop through the array to find subarrays with zero sum
    for(int i = 0; i < n; i++){
        // Calculate cumulative sum
        Sum += arr[i];

        // If cumulative sum is zero or it's already present in the set, it means
        // there is a subarray with zero sum
        if (Sum == 0 || (check.find(Sum) != check.end())){
            // Increment the counter for zero sum subarrays
            counter++;
            
            // Reset cumulative sum and clear the set for the next subarray
            Sum = arr[i];
            check.clear();
            check.insert(Sum);
            
            // Skip the rest of the loop body and continue with the next iteration
            continue;
        }

        // Insert the cumulative sum into the set
        check.insert(Sum);
    }

    // Output the count of subarrays with zero sum
    cout << counter << endl;
}
