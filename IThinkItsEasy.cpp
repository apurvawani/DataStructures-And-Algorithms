/*
Given a set of strings print the set sorted according to their size. If the size of the strings are equal, must 
maintain the original order of the set.

Input :

The first line of input has an integer T that indicates the number of sets of strings, each set may contain between 
1 and 50 inclusive elements, and each of the strings of the set may contain between 1 and 50 inclusive 
characters('a' to 'z').

Output:

The output should contain the set of input strings ordered by the length of strings.A blank space must be printed 
between two words.

*/

#include<bits/stdc++.h>

using namespace std;

vector <string> merge(vector <string> &set , vector <string> &result , int * len , int * temp , int start , int mid , int end) {
    int i = start;
    int j = mid;
    int k = start;
    while((i < mid) && (j <= end)) {
        if(len[i] <= len[j]) {
            temp[k] = len[i];
            result[k] = set[i];
            k++;
            i++;
        }
        else {
            temp[k] = len[j];
            result[k] = set[j];
            k++;
            j++;
        }
    }
    while(i < mid) {
        temp[k] = len[i];
        result[k] = set[i];
        k++;
        i++;
    }
    while(j <= end) {
        temp[k] = len[j];
        result[k] = set[j];
        k++;
        j++;
    }
    for(int t = start ; t <= end ; t++) {
        len[t] = temp[t];
        set[t] = result[t];
    }
    return result;
}

vector <string> mergeSort(vector <string> &set , vector <string> &result , int * len , int * temp , int start , int end) {
    int mid = 0;
    if(start < end) {
        mid = (start + end)/2;
        result = mergeSort(set , result , len , temp , start , mid);
        result = mergeSort(set , result , len , temp , mid+1 , end);
        result = merge(set , result , len , temp , start , mid+1 , end);
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while(T!=0) {
        vector <string> result;
        vector <string> set;
        set.clear();
        result.clear();
        string s , c;
        s.clear();
        getline(cin , s);
        for(int i = 0 ; i < s.size() ; i++) {
            if(isspace(s[i])) {
                set.push_back(c);
                result.push_back(c);
                c.clear();
            }
            else {
                c = c + s[i];
            }
        }
        set.push_back(c);
        result.push_back(c);
        c.clear();
        int l = set.size();
        int len[l];
        for(int i = 0 ; i < l ; i++) {
            len[i] = set[i].size();
            //cout << len[i];
        }
        int temp[l];
        result = mergeSort(set , result , len , temp , 0 , l-1);
        //cout << " ";
        for(int t = 0 ; t < result.size() ; t++) {
            cout << result[t] << " ";
        }
        cout << endl;
        T--;
    }
    return 0;
}