/*
Given a number N, the task is to find the sum of all the elements from all possible subsets of a set formed by first N natural numbers.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains a 
number N as input.

Output:
For each test case, print the sum in new line.

Constraints:
1 <= T <= 50
1 <= N <= 50
*/


#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n , sum = 0;
	    unsigned long long int res = 0;
	    cin >> n;
	    for(int i = 1 ; i <= n ; i++) {
	        sum += i;
	    }
	    res = pow(2 , (n-1))*sum;
	    cout << res << endl;
	}
	return 0;
}
