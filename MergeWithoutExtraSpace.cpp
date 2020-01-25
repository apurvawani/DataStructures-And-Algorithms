/*
Given two sorted arrays arr1[] and arr2[] in non-decreasing order with size n and m. The task is to merge the two sorted arrays
into one sorted array (in non-decreasing order).

Note: Expected time complexity is O((n+m) log(n+m)). DO NOT use extra space.  We need to modify existing arrays as following.

Input:
First line contains an integer T, denoting the number of test cases. First line of each test case contains two space separated integers X and Y, denoting the size of the two sorted arrays. Second line of each test case contains X space separated integers, denoting the first sorted array P. Third line of each test case contains Y space separated integers, denoting the second array Q.

Output:
For each test case, print (X + Y) space separated integer representing the merged array.

Constraints:
1 <= T <= 100
1 <= X, Y <= 5*104
0 <= arr1i, arr2i <= 109

Example:
Input:
2
4 5
1 3 5 7
0 2 6 8 9
2 3
10 12
5 18 20

Output:
0 1 2 3 5 6 7 8 9
5 10 12 18 20

Explanation:
Testcase 1: After merging two non-decreasing arrays, we have, 0 1 2 3 5 6 7 8 9.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	   int x , y;
    	cin >> x >> y;
    	int arr1[x] , arr2[y];
    	for(int i = 0 ; i < x ; i++)
    	    cin >> arr1[i];
    	for(int i = 0 ; i < y ; i++)
    	    cin >> arr2[i];
    	int gap = ((x+y)/2 + (x+y)%2) , i = 0 , j = 0;
    	while(gap > 0) {
    	   for(i = 0 ; i+gap < x ; i++) {
    	       if(arr1[i] > arr1[i+gap])
    	            swap(arr1[i] , arr1[i+gap]);
    	   }
    	   for(j = (gap > x ? gap-x : 0) ; i < x && j < y ; i++ , j++) {
    	       if(arr1[i] > arr2[j])
    	            swap(arr1[i] , arr2[j]);
    	   }
    	   if(j < y) {
    	       for(j = 0 ; j + gap < y ; j++) {
    	           if(arr2[j] > arr2[j+gap])
    	                swap(arr2[j] , arr2[j+gap]);
    	       }
    	   }
    	   if(gap <= 1)
    	       break;
    	   gap = gap/2 + gap%2;
    	}   
    	for(auto p : arr1)
	       cout << p << " ";
	    for(auto p : arr2)
	       cout << p << " ";
	    cout << endl;
	}
	return 0;
}
