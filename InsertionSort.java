/*
You have been given an A array consisting of N integers. All the elements in this array are guaranteed to be unique. 
For each position i in the array A you need to find the position A[i] should be present in, if the array was a sorted 
array. You need to find this for each i and print the resulting solution.

Input Format:
The first line contains a single integer N denoting the size of array A. The next line contains N space separated integers 
denoting the elements of array A.

Output Format:
Print N space separated integers on a single line , where the Ith integer denotes the position of A[i] if this array were sorted.

Constraints:
1 <= N <= 100
1 <= A[i] <= 100
*/

import java.util.*;

class TestClass {
    
	public static void main(String args[] ) throws Exception {
        
		Scanner scan = new Scanner(System.in);
        
		int n = scan.nextInt();
        
		int j , key;
        
		int[] arr = new int[n];
        
		for(int i = 0 ; i < n ; i++) {
            
			arr[i] = scan.nextInt();
        
		}
        
		int[] a = new int[n];
        
		for(int i = 0 ; i < n ; i++) {
            
			a[i] = arr[i];
        
		}
        
		for(int i = 1 ; i < n ; i++) {
            
			key = arr[i];
            
			j = i-1;
            
			while(j >= 0 && arr[j] > key) {
                
				arr[j+1] = arr[j];
                
				j--;
            
			}
            
			arr[j+1] = key;
        
		}
        
		for(int i = 0 ; i < n ; i++) {
            
			for(int k = 0 ; k < n ; k++) {
                
				if(a[i]==arr[k]) {
                    
					System.out.print(k+1 + " ");
                    
					break;
                
				}
            
			}
        
		}
    
	}

}
