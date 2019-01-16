/*
Given a number N, calculate the prime numbers upto N using Sieve of Eratosthenes.  

Input: 
The first line of the input contains T denoting the number of testcases. T testcases follow. Each testcase contains one line of input 
containing N.

Output: 
For all testcases, in a new line, print all the prime numbers upto or equal to N.

Constraints:
1 <= T<= 100
1 <= N <= 104

Example:
Input:
2
10
35
Output:
2 3 5 7
2 3 5 7 11 13 17 19 23 29 31 

*/

#include <bits/stdc++.h>
using namespace std;
#define N 10000 

int main() {
	int ar[N+1] = {0};
	for(int i = 2 ; i <= sqrt(N) ; i++) {
        int k = i*i;
        while(k <= N) {
            ar[k]++;
            k += i;
        }
	}
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    for(int i = 2 ; i <= n ; i++) {
	        if(ar[i] == 0) {
	            cout << i << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
