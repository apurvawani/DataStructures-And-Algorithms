/*
Arya has a chessboard with N rows (numbered 1 through N) and N columns (numbered 1 through 
N); a square in row r and column c is denoted by (r,c).

Arya has already placed K rooks on the chessboard in such a way that no two rooks attack 
each other. Note that two rooks attack each other if they are in the same row or in the same
column and there is no rook between them. She is busy learning how to tame a dragon right 
now, so she asked you to place as many other rooks as possible on the chessboard in such a 
way that afterwards, no two rooks on the chessboard attack each other. Help Arya and choose 
the positions of these rooks.

Input :
The first line of the input contains a single integer T denoting the number of test cases. 
The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
Each of the next K lines contains two space-separated integers r and c denoting that Arya 
placed a rook on the square (r,c).

Output :
For each test case:
Let's assume that you placed P rooks on squares (r1,c1),(r2,c2),…,(rP,cP).
You should print a single line containing 2P+1 space-separated integers P,r1,c1,…,rP,cP.
P must be maximum possible.
If there are multiple possible answers, the sequence r1,c1,…,rP,cP should be 
lexicographically smallest.

Constraints :
1≤T≤100
1≤N≤106
0≤K≤N
1≤ri,ci≤N for each valid i
no two initially placed rooks attack each other
the positions of all initially placed rooks are pairwise distinct
the sum of N over all test cases does not exceed 10^6

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n , k , x = 0;
        cin >> n >> k;
        int row[n] = {0} , col[n] = {0} , count = k;
        while(count--) {
            int r , c;
            cin >> r >> c;
            row[r-1] = 1;
            col[c-1] = 1;
        }
        cout << n-k << " ";
        for(int i = 0 ; i < n ; i++) {
            if(row[i] == 0) {
                //x = 0;
                while(x < n) {
                    if(col[x] == 0) {
                        col[x] = 1;
						break;
                    }
                    x++;
                }
				row[i] = 1;
                cout << i+1 << " " << x+1 << " "; 
                x = x+1;
            }
        }
        cout << endl;
	}
	return 0;
}
