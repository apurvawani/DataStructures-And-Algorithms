/*
Today is Arnav's B'day. All his friends have bought a chocolate cake for him. After cutting the cake, Arnav explains 
to all his friends that this time he has planned something different rather than just giving a treat in dominos.
Arnav has planned to visit an Orphanage in Pune and celebrate his B'day with 44 children in Orphanage. All his 
friends were really touched by his decision. One of his friends, Vrushabh asked him about what he is going to buy for 
the children in Orphanage. Arnav has decided to buy a Gift Hamper for each of them containing all the necessary items
required for them. Shreyans suggested him to distribute all the Gift Hampers equally among the children.
Arnav buys N Gift Hampers. Help Arnav to find out whether he can distribute them equally among the children in 
Orphanage.

Input Format :
First line contains number of test cases t
Each line contains N gift hampers.

Constraints :
1 <= t <= 1e5
0 <= n <= 1e444

Output Format :
Print "YES" if Arnav can distribute them equally among the children in Orphanage.
else print "NO".
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int t;
    cin >> t;
    for(long long int i = 0 ; i < t ; i++) {
        string n;
        cin >> n;
        long long int k = n.length() , p , sum1 = 0 , sum2 = 0 , q = 0;
        bool f;
        while(q < k) {
            if(n[q] != '0') {
                f = true;
                break;
            }
            else{
                f = false;
            }
            q++;
        }
        if(!f) {
            cout << "NO" << endl;
        }
        else {
            p = (n[k-2]-48)*10 + (n[k-1]-48);              
            if(p % 4 == 0) {
                long long int j = 0;
                while(j < k) {
                    if(j % 2 == 0) {
                        int r = n[j] - '0';
                        sum1 += r;
                    }
                    else {
                        int s = n[j] - '0';
                        sum2 += s;                        
                    }
                    j++;
                }
                if((abs(sum1-sum2)) % 11 == 0) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }   
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
