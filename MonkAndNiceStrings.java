/*
Monk's best friend Micro's birthday is coming up. Micro likes Nice Strings very much, so Monk decided to gift him one.
Monk is having N nice strings, so he'll choose one from those. But before he selects one, he need to know the Niceness
value of all of those. Strings are arranged in an array A, and the Niceness value of string at position i is defined 
as the number of strings having position less than i which are lexicographicaly smaller than A[i]. Since nowadays, 
Monk is very busy with the Code Monk Series, he asked for your help.
Note: Array's index starts from 1.

Input:
First line consists of a single integer denoting N.
N lines follow each containing a string made of lower case English alphabets.

Output:
Print N lines, each containing an integer, where the integer in 'i' th line denotes Niceness value of string A[i]. 

*/

import java.util.*;


class TestClass {
    
	public static void main(String[] args) {
        
		Scanner scan = new Scanner(System.in);
        
		int n = scan.nextInt();
        
		String[] s = new String[1010];
        
		int j = 0;
        
		s[0] = "A";
        
		for(int i = 1 ; i <= n ; i++) {
            
			String str = "";
            
			str = scan.next();
            
			for(j = i - 1 ; j >= 0 ; j--) {
                
				if(s[j].compareTo(str) >= 0) {
                    
					s[j+1] = s[j];
                
				}
                
				else {
                    
					break;
                
				}
            
			}
            
			System.out.println(j);
            
			s[j+1] = str;
        
		}
    
	}

}
