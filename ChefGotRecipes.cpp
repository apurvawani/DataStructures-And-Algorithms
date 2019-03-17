#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll vowels(vector <ll> arr) {
    ll result = 0;
    for(int i = 1 ; i < 32 ; i++) {
        for(int j = 1 ; j < 32 ; j++) {
            int v = i | j;
            if((v == 31) && (i != j)) {
                result += arr[i]*arr[j];
            }
        }
    }
    if(arr[31] != 0) {
        result += arr[31]*(arr[31]-1);
    }
    return result;
}

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll res = 0;
        ll n;
        cin >> n;
        string s;
        vector <ll> counter(32,0); 
        while(n--) {
            cin >> s;
            ll d = s.length();
            ll i = 0 , temp = 0;
            while(d--) {
                if(s[i] == 'a')
                    temp |= 16;
                if(s[i] == 'e')
                    temp |= 8;
                if(s[i] == 'i')
                    temp |= 4;
                if(s[i] == 'o')
                    temp |= 2;
                if(s[i] == 'u')
                    temp |= 1;
                i++;
            }
            counter[temp]++;
        }
        res = vowels(counter);
        cout << res/2 << endl;
    }
	return 0;
}
