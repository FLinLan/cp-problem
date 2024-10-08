import java.io.*;
import java.util.*;

// javac template.java && java template < input.txt > output.txt
public class template {
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
        
        int nextInt() {
            return Integer.parseInt(next());
        }
        
        long nextLong() {
            return Long.parseLong(next());
        }
        
        double nextDouble() {
            return Double.parseDouble(next());
        }
        
        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {}
            return str;
        }
    }
    
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        int t = 1; // Default to 1 test case
        
        // Uncomment the next line if you want to read the number of test cases
        // t = fs.nextInt();
        
        for (int i = 0; i < t; i++) {
            solve(fs, out);
        }
        
        out.close();
    }
    
    static void solve(FastScanner fs, PrintWriter out) {
        // Solution for each test case goes here
        // Example:
        int n = fs.nextInt();
        out.println(n);
    }
}
