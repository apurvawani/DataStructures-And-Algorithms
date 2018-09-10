/*
Find out if it is possible to partition the first n positive integers into two non-empty disjoint sets S1 and S2
such that gcd(sum(S1),sum(S2))>1
Here sum(S) denotes the sum of all elements present in set S and gcd means thegreatest common divisor.
Every integer number from 1 to n should be present in exactly one of S1 or S2.

Input :
The only line of the input contains a single integer n (1 <= n <= 45000).

Output :
If such partition doesn't exist, print "No" (quotes for clarity).
Otherwise, print "Yes" (quotes for clarity), followed by two lines, describing S1 and S2 respectively.
Each set description starts with the set size, followed by the elements of the set in any order. Each set must be 
non-empty.
If there are multiple possible partitions — print any of them.
*/

#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    if(n == 1 || n == 2) {
        cout << "No";
    }
    else {
        vector <int> s1;
        vector <int> s2;
        int sum1 = 0 , sum2 = 0;
        for(int i = 1 ; i <= n ; i++) {
            if(i % 2 == 0) {
                s1.push_back(i);
                sum1 += i;
            }
            else {
                s2.push_back(i);
                sum2 += i;
            }
        }
        if(__gcd(sum1 , sum2) > 1) {
            cout << "Yes" << endl;
            cout << s1.size() << " ";
            for(int i = 0 ; i < s1.size() ; i++) {
                cout << s1[i] << " ";
            }
            cout << endl;
            cout << s2.size() << " ";
            for(int i = 0 ; i < s2.size() ; i++) {
                cout << s2[i] << " ";
            }
        }
    }
    return 0;
}