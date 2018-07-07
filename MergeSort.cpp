/*
Given an array A on size N, you need to find the number of ordered pairs (i,j) such that i < j and A[i] > A[j].

Input:
First line contains one integer, N, size of array.
Second line contains N space separated integers denoting the elements of the array A.

Output:
Print the number of ordered pairs (i,j) such that i < j and A[i] > A[j].

Constraints:
1 <= N <= 1000000
1 <= A[i] <= 1000000

*/
#include<bits/stdc++.h>

using namespace std;

class TestClass {

    public:

    long long int mergeSort(int arr[] , int temp[] , int start , int end) {

        int mid;

        long long int count = 0;

        if(start < end) {

            mid = (start + end)/2;

            count = mergeSort(arr , temp , start , mid);

            count += mergeSort(arr , temp , mid+1 , end);

            count += merge(arr , temp , start , mid+1 , end);

        }

        return count;

    }
 
   long long int merge(int arr[] , int temp[] , int start , int mid , int end) {

        long long int count = 0;

        int i = start;

        int j = mid;

        int k = start;

        while((i < mid) && (j <= end)) {

            if(arr[i] <= arr[j]) {

                temp[k] = arr[i];

                i++;

                k++;

            }

            else {

                temp[k] = arr[j];

                j++;

                k++;

                count += (mid - i);
 
            }

        }

        while(i < mid){

            temp[k] = arr[i];

            k++;

            i++;

        }

        while(j <= end) {

            temp[k] = arr[j];

            k++;

            j++;

        }
        
	for(int l = start ; l <= end ; l++) {

            arr[l] = temp[l];

        }

        return count;

    }

};

int main() {

    TestClass t;

    int n;

    cin >> n;

    int arr[n];

    int temp[n];

    for(int i = 0 ; i < n ; i++) {

        cin >> arr[i];

    }

    long long int result = t.mergeSort(arr , temp , 0 , n-1);

    cout << result;

    return 0;

}