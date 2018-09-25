/*
On one Sunday morning, Shahrukh, Shreyans, Vrushabh, Arnav and Nilakshi were sitting idle. As usual doing nothing 
great but trying to show Shreyans’ parents that they are working on a big project.
Suddenly, Vrushubh got an idea that they should make a problem statement regarding strings for the contest. But, 
Shreyans argues with him because he likes to solve mathematical problem statements.
To settle down their fight, Shahrukh and Arnav asks them to solve a problem. The problem states that they are given 
with a string. They have to print “YES” for the string if it contains a substring which is a palindrome, else “NO”.
Help Shreyans and Vrushabh to settle down the fight.

Input Format : 
First line contains no. of test cases, t.
Following t lines contains String s.

Constraints :
1<=t<=100
1<=stringlength of s<=10^6

Output Format :
Print YES – If a substring palindrome exists,
else, NO.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0 ; i < t ; i++) {
        string s;
        cin >> s;
        int k = 0;
        bool r;
        while(k != s.length()) {
            if(s[k] == s[k+1] || s[k] == s[k+2]) {
                r = true;
                break;
            }
            else {
                r = false;
            }
            k++;
        }
        if(r) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0; 
}