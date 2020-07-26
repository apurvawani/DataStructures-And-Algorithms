/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. 
You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another 
box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the 
higher box. Of course, you can rotate a box so that any side functions as its base. It is also allowable to use 
multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height 
of the highest possible stack so formed.

Input:
The first line of input contains an integer T denoting the number of test cases then T test cases follow. 
Each test case contains an integer N denoting the total no of boxes available. 
In the next line are 3*N space separated values denoting the height, width and length of the N boxes.

Output:
For each test case in a new line output will be the highest possible stack height which could be formed.

Your Task:
Complete the function maxHeight() which takes three arrays height[], width[], length[], and N as a number 
of boxes and returns the highest possible stack height which could be formed.

Expected Time Complexity : O(N*N)
Expected Auxiliary Space: O(N)

Constraints:
1<=T<=100
1<=N<=100
1<=l,w,h<=100
*/

#include<bits/stdc++.h>
using namespace std;

struct Box {
    int h , w , l;
};

bool compare(Box b1 , Box b2) {
    return (b1.w*b1.l > b2.w*b2.l ? true : false);
}

int maxHeigth(vector<Box> b , int n);

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<Box> b(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> b[i].h;
        cin >> b[i].w;
        cin >> b[i].l;
    }
    cout << maxHeight(b , n) << endl;
  }
  return 0;
}

int maxHeight(vector<Box> b , int n) {
  vector<Box> rot(3*n);
    int index = 0;
    for(int i = 0 ; i < n ; i++) {
        rot[index].h = b[i].h;
        rot[index].w = min(b[i].w , b[i].l);
        rot[index].l = max(b[i].w , b[i].l);
        index++;
        
        rot[index].h = b[i].w;
        rot[index].w = min(b[i].h , b[i].l);
        rot[index].l = max(b[i].h , b[i].l);
        index++;
        
        rot[index].h = b[i].l;
        rot[index].w = min(b[i].w , b[i].h);
        rot[index].l = max(b[i].w , b[i].h);
        index++;
    }
    
    sort(rot.begin() , rot.end() , compare);
    
    vector<int> dp(3*n);
    for(int i = 0 ; i < 3*n ; i++)
        dp[i] = rot[i].h;
    
    for(int i = 1 ; i < 3*n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            if(rot[i].w < rot[j].w && rot[i].l < rot[j].l && dp[i] < dp[j] + rot[i].h)
                dp[i] = dp[j] + rot[i].h;
        }
    }
    
    int max = -1;
    for(int i = 0 ; i <3*n ; i++) {
        if(dp[i] > max)
            max = dp[i];
    }
    
    return max;
}
