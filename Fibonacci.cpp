#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> pre_comp(500 , -1);

ll fib(ll n) {
  if(pre_comp[n] == -1) {
    ll res;
    res = fib(n-1) + fib(n-2);
    pre_comp[n] = res;
    return res;
  } 
  else {
    return pre_comp[n];
  }
}

int main() {
  ll n;
  pre_comp[0] = 0;
  pre_comp[1] = 1;
  cin >> n;
  cout << fib(n) << endl;
  return 0;
}