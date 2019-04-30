/*
You are given a sequence of non-negative integers A1,A2,…,AN. At most once, you may choose a non-negative integer X and for each valid i,
change Ai to Ai^X (^ denotes bitwise XOR).
Find the minimum possible value of the sum of all elements of the resulting sequence.

Input :
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of the input contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output :
For each test case, print a single line containing one integer - the minimum possible sum.

Constraints :
1 <= T <= 1,000
1 <= N <= 10^5
1 <= Ai <= 10^9 for each valid i
the sum of N over all test cases does not exceed 10^6

Subtasks :
Subtask #1 (50 points) :
1 <= N <= 10^3
1 <= Ai <= 10^3 for each valid i

Subtask #2 (50 points) : original constraints

Example Input :
3
5
2 3 4 5 6
4
7 7 7 7
3
1 1 3

Example Output :
14
0
2
*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define prec(n) fixed<<setprecision(n)
#define eps 0.000001
#define all(v) v.begin(), v.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define for(i , p , n) for(ll i = p ; i < n ; i++)
#define MAXN 10000003
typedef long long ll;
using namespace std;
ll mult(ll a,ll b, ll p=MOD) {return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD) {return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}

int main() {
    io;
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        for(i , 0 , n) {
            cin >> a[i];
        }
        ll x = 1 , p , temp = 0 , res = 0;
        for(i , 0 , 32) {
            temp = 0;
            for(j , 0 , n) {
                p = a[j] & x;
                if(p != 0)
                    temp++;
            }
            x = x << 1;
            if(temp > n/2) {
                res += pow(2 , i);
            }
        }
        ll sum = 0;
        for(i , 0 , n) {
            sum += a[i] ^ res;
        }
        cout << sum << endl;
    }
    return 0;
}
