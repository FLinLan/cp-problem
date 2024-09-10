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
    
    public static int count(int n) {
        if (n == 0) return 0;
        return n/5 + count(n/5);
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(fs.next());
        out.println(count(n));
        out.close();
    }
}
