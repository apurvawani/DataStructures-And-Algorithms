/*
Given a binary matrix of size N x N which represents the pixels of a logo.
1 indicates that the pixel is colored and 0 indicates no color.
Align the center of logo with the origin of Cartesian plane. Now if the colored pixels of the logo are symmetric 
about both X-axis and Y-axis, then the logo is symmetric.
Print "YES" if logo is symmetric else print "NO".
*/ 



import java.util.*;
class SymmetricLogo {
    public static void main(String args[] ) throws Exception {
        // Write your code here
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for(int i = 0 ; i < T ; i++){
            boolean check = true;
            int N = scan.nextInt();
            Vector<String> logo = new Vector<String>(N);
            for(int j = 0 ; j < N ; j++){
                String pixel = scan.next();
                int n = pixel.length();
                char[] ch = pixel.toCharArray();
                for(int ch_i = 0 ; ch_i < n ; ch_i++){
                    if(ch[ch_i]!=ch[n-ch_i-1]){
                        check = false;
                        break;
                    }
                }
                logo.add(pixel);
            }
            boolean c = true;
            if(check){
                for(int j = 0 ; j < N ; j++){
                    String p1 = logo.get(j);
                    String p2 = logo.get(N-1-j);
                    boolean value = p1.equals(p2); 
                    if(!value){
                        c = false;
                        break;
                    }
                }
            }
            if(c && check){
                System.out.println("YES");
            }
            else{
                System.out.println("NO");
            }
        }
    }
}
