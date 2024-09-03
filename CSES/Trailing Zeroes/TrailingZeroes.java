import java.io.*;
import java.util.*;

// javac TrailingZeroes.java && java TrailingZeroes < input.txt > output.txt
public class TrailingZeroes {
    static class FastScanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");
        
        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {}
            }
            return st.nextToken();
        }
    }
    
    public static long factorial(int n) {
        long factor = 1; // Change 'int' to 'long' to prevent overflow
        int MOD = (int)1e9 + 7;
        for (int i = 1; i <= n; i++) {
            factor = (factor * i);
        }
        return factor;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        

        int n = Integer.parseInt(fs.next());
                
        String factor = Long.toString(factorial(n));

        int N = factor.length();
        int ptr = N-1;

        int count = 0;
        while (ptr >= 0 && factor.substring(ptr,ptr+1).equals("0")) {
            count++;
            ptr--;
        }
        out.println(count);
        out.close();
    }
}
