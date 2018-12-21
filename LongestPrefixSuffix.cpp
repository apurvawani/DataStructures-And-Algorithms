/*
Given a string of character, find the length of longest proper prefix which is also a proper suffix.
Example:
S = abab
lps is 2 because, ab.. is prefix and ..ab is also a suffix.

Input:
First line is T number of test cases. 1<=T<=100.
Each test case has one line denoting the string of length less than 100000.

Expected time compexity is O(N).

Output:
Print length of longest proper prefix which is also a proper suffix.

Example:
Input:
2
abab
aaaa

Output:
2
3
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t != 0) {
        string s;
    	cin >> s;
    	int l = s.length();
    	int a[l];
    	int i = 1 , j = 0;
    	a[0] = 0;
    	while(i < l) {
    	    if(s[j] == s[i]) {
    	        j++;
    	        a[i] = j;
    	        i++;
    	    } 
    	    else if(j != 0) {
    	        j = a[j-1];
    	    }
    	    else {
    	        a[i] = 0;
    	        i++;
    	    }
    	}
    	int result = (a[l-1] > l/2) ? l/2 : a[l-1]; 
    	cout << result << endl;
        t--;
    }
	return 0;
}
