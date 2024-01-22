// https://codeforces.com/contest/1426/problem/D
#include<bits/stdc++.h>
using namespace std;

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
