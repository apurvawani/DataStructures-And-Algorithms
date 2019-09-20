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
			sum = sum/2;
			bool pt[sum+1];
			forr(i , 0 , sum+1)
				pt[i] = false;
			pt[0] = true;
			forr(k , 0 , n) {
				for(ll i = sum ; i >= 0 ; i--){
					if(i >= ar[k])
						pt[i] = pt[i] || pt[i-ar[k]];
				}
			}
			if(pt[sum])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}