/*
Given a 6x6 2D array and hourglass is defined as 
a b c
  d
e f g 
find the hourglass with maximum sum.

*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class TwoDArrays {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int arr[][] = new int[6][6];
        for(int i=0; i < 6; i++){
            for(int j=0; j < 6; j++){
                arr[i][j] = in.nextInt();
            }
        }
        int [] A = new int[16];
        int i , j , k;
        int S0 , S1 , S2 , Sum = 0;
        j = 0;
        k = 0;
        while(j<4){
            i = 0;
            while(i<4){
                S0 = arr[j][i] + arr[j][i+1] + arr[j][i+2]; 
                S1 = arr[j+1][i+1];
                S2 = arr[j+2][i] + arr[j+2][i+1] + arr[j+2][i+2];
                Sum = S0 + S1 + S2;
                A[k] = Sum;
                k++;
                i++;
            }
            j++;
        }
        int max = A[0];
        for(k = 0 ; k<16 ; k++){
            if(A[k]>max){
                max = A[k];
            }    
        }
        System.out.println(max);
    }
}
