/*
Problem Description :

Task : To force the given implementation of the quick sort algorithm to efficiently process sequences with
few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
partition procedure should partition the array into three parts: < x part, = x part, and > x part.

Input Format : The first line of the input contains an integer n. 
               The next line contains a sequence of n integers a0 , a1 , ... , an−1 .

Constraints : 1 ≤ n ≤ 10 5 ; 1 ≤ a i ≤ 10 9 for all 0 ≤ i < n.

Output Format : Output this sequence sorted in non-decreasing order.

Sample 1 :
Input : 
5
2 3 9 2 2
Output : 
2 2 2 3 9

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void partition(vector <ll> &data , ll low , ll high , ll &p1 , ll &p2) {
	if(data.size() == 2) {
		if(data[high] < data[low])
			swap(data[high] , data[low]);
		p1 = low;
		p2 = high;
		return;
	}

	ll k = low , pivot = data[high];
	while(k <= high) {
		if(data[k] < pivot) {
			swap(data[k] , data[low]);
			k++;
			low++;
		}
		else if(data[k] == pivot)
			k++;
		else if(data[k] > pivot) {
			swap(data[k] , data[high]);
			high--;
		}
	}
	p1 = low-1;
	p2 = k;
}

void quickSort(vector <ll> &data , ll low , ll high) {
	if(low < high) {
		ll p1 , p2;
		partition(data , low , high , p1 , p2);
		quickSort(data , low , p1);
		quickSort(data , p2 , high);
	}
}

int main() {
	ll n;
	cin >> n;
	vector <ll> data(n);
	for(ll i = 0 ; i < n ; i++)
		cin >> data[i];
	quickSort(data , 0 , n-1);
	for(ll i = 0 ; i < n ; i++)
		cout << data[i] << " ";
	return 0;
}
