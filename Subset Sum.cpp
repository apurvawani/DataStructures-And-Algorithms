/*
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both 
subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case constitutes of two lines. First line contains 'N', representing the number of elements in the set and the second line contains the elements of 
the set.

Output:
Print YES if the given set can be partioned into two subsets such that the sum of elements in both subsets is equal, 
else print NO.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 

Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}. 
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MOD 1000000007
#define MOD9 1000000009
#define pi 3.1415926535
#define ms(s, n) memset(s, n, sizeof(s))
#define all(v) v.begin(), v.end()
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i , p , n) for(ll i = p ; i < n ; i++)
#define MAXN 10000003
#define endl "\n"
typedef long long ll;
using namespace std;
ll mult(ll a,ll b, ll p=MOD) {return ((a%p)*(b%p))%p;}
ll add(ll a, ll b, ll p=MOD) {return (a%p + b%p)%p;}
ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
ll inv(ll a, ll p = MOD) {return fpow(a, p - 2, p);}

bool demo(vector <ll> ar , ll index , ll sum) {
	if(sum == 0)
		return true;
	else if(index == ar.size() || sum < 0)
		return false;
	else {
		if(demo(ar , index+1 , sum-ar[index]))
			return true;
		ll k = index + 1;
		while(k < ar.size() && ar[k] == ar[index]) {
			k++;
		}
		return demo(ar , k , sum);
	}
}


int main() {
	io;
	ll t;
	cin >> t;
	while(t--) {
		ll n;
		cin >> n;
		vector <ll> ar(n);
		ll sum = 0;
		forr(i , 0 , n) {
			cin >> ar[i];
			sum += ar[i];
		}
		if(sum % 2 != 0)
			cout << "NO" << endl;
		else {
			if(demo(ar , 0 , sum/2))
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}
