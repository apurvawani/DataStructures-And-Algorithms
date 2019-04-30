/*
You are given a rooted tree with N nodes (numbered 1 through N); node 1 is the root. Each node has a value; let's 
denote the value of node i by Ai. You may perform the following operation any number of times (including zero): 
choose any node which still exists in the tree and remove the whole subtree of this node including itself.
Let's define the profit as the sum of values of all nodes which currently exist in the tree minus X·k, where k 
denotes the number of times this operation was performed. Find the maximum possible profit.

Input :
The first line of the input contains a single integer T denoting the number of test cases. The description of T test 
cases follows.
The first line of each test case contains two space-separated integers N and X.
The second line contains N space-separated integers A1,A2,…,AN.
Each of the following N-1 lines contains two space-separated integers u and v denoting that nodes u and v are 
connected by an edge.

Output :
For each test case, print a single line containing one integer — the maximum profit.

Constraints :
1 <= T <= 10
1 <= N <= 10^5
1 <= X <= 10^9
1 <= u , v <= N
|Ai| <= 10^9 for each valid i
the graph described on the input is a tree

Subtasks :
Subtask #1 (30 points): 1 <= N <= 1000
Subtask #2 (70 points): original constraints

Example Input :
1
3 5
1 -5 -10
1 2
2 3

Example Output :
-4

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

vector<ll> s[100005];
vector <ll> ar;
ll n , x;

ll dfs(ll p , ll c) {
    ll res = ar[c];
    for(i , 0 , s[c].size()) {
        if(s[c][i] != p) {
            res += dfs(c , s[c][i]);
        }
    }
    return max(res , -x);
}

int main() {
    io;
    ll t , temp;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        ar.push_back(0);
        for(i , 1 , n+1) {
            cin >> temp;
            ar.push_back(temp);
        }
        ll edges = n-1;
        ll p , q;
        while(edges--) {
            cin >> p >> q;
            s[p].push_back(q);
            s[q].push_back(p);
        }
        ll result = dfs(1 , 1);
        cout << result << endl;
        ar.clear();
        ms(s , 0);
    }
    return 0;
}
