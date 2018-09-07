/*

You are given a string s of length n, which consists only of the first k letters of the Latin alphabet. All letters 
in string s are uppercase.
A subsequence of string s is a string that can be derived from s by deleting some of its symbols without changing the
order of the remaining symbols. For example, "ADE" and "BD" are subsequences of "ABCDE", but "DEA" is not.
A subsequence of s called good if the number of occurences of each of the first k letters of the alphabet is the same.
Find the length of the longest good subsequence of s.

Input :
The first line of the input contains integers n(1 <= n <= 10^5) and k(1 <= k <= 26).
The second line of the input contains the string s of length n. String s only contains uppercase letters from 'A' to 
the k-th letter of Latin alphabet.

Output :
Print the only integer — the length of the longest good subsequence of string s.

*/


#include <bits/stdc++.h>

using namespace std;


int main() {

    int n , k;

    char c = 'A';

    cin >> n >> k;

    string s;

    cin >> s;

    int c1[k] , c2[k];

    char ar[k];

    for(int i = 0 ; i < k ; i++) {

        c1[i] = 0;

        c2[i] = 0;

        ar[i] = c;

        c = c + 1;

    }

    ar[k] = '\0';

    for(int i = 0 ; i < n ; i++) {
        int t = 0;
        while(ar[t] != '\0') {
            if(s[i] == ar[t]) {
                c1[t]++;
            }
            t++;
        }
    }
    int min = c1[0];
    for(int j = 0 ; j < k ; j++) {
        if(c1[j] < min) {
            min = c1[j];
        }
    }
    /*cout << min << endl;
    for(int i = 0 ; i < k ; i++) {
        cout << c1[i];
    }*/
    int sum = 0;
    std::vector<char> result;
    if(min == 0) {
        cout << "0";
    }
    else {
        for(int i = 0 ; i < n ; i++) {
            int t = 0;
            while(ar[t] != '\0') {
                if(s[i] == ar[t] && c2[t] < min) {
                    result.push_back(s[i]);
                    //cout << t;
                    c2[t]++;
                    break;
                }
                t++;
            }
        }
        for(int i = 0 ; i < k ; i++) {
            sum += c2[i];
        }
        if(sum % k == 0) {
        cout << result.size();
    }
    }
    return 0;
}