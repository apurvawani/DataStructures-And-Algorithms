/*
The first line contains two space-separated integers, N(the number of sequences) and Q(the number of queries), 
respectively. Each of the Q subsequent lines contains a query in the format defined below.
The 2 types of queries that can be performed on your list of sequences (seqList) are described below:
1. Query: 1 x y
   1. Find the sequence, seq, at index ((x^lastAnswer)%N) in seqList.
   2. Append integer y to sequence seq.
2. Query: 2 x y
   1. Find the sequence, seq, at index ((x^lastAnswer)%N) in seqList.
   2. Find the value of element y % size in seq(where is the size of seq) and assign it to lastAnswer.
   3. Print the new value of lastAnswer on a new line.
*/


import java.io.*;
import java.util.*;

public class DynamicArray {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT.*/
        int lastAnswer = 0;
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int Q = scan.nextInt();
        Vector< Vector<Integer> > seqList = new Vector< Vector<Integer> >(N);
        for(int i = 0 ; i < N ; i++){
            seqList.add(new Vector<Integer>());
        }
        for(int i = 0 ; i < Q ; i++){
            int queryNo = scan.nextInt();
            int x = scan.nextInt();
            int y = scan.nextInt();
            int seqNo = ((x ^ lastAnswer) % N);
            Vector<Integer> seq = seqList.get(seqNo);
            if(queryNo==1){
                seq.add(y);
            }
            else{
                lastAnswer = seq.get(y % seq.size());
                System.out.println(lastAnswer);
            }
        }
    }
}