import java.io.*;
import java.util.*;

// javac TwoSets.java && java TwoSets < input.txt > output.txt
public class TwoSets {
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
        long n = fs.nextLong();
        long sums = (n*(n+1))/2;
        if (sums % 2 == 1) {
            out.println("NO");
            return;
        }

        long setSum = sums / 2;
        List<Long> set1 = new ArrayList<>();
        List<Long> set2 = new ArrayList<>();
        
        for (long val = n; val >= 1; val--) {
            if (val <= setSum) {
                set1.add(val);
                setSum -= val;
            } else {
                set2.add(val);
            }
        }

        out.println("YES");
        out.println(set1.size());
        for (long num : set1) {
            out.print(num + " ");
        }
        out.println();
        out.println(set2.size());
        for (long num : set2) {
            out.print(num + " ");
        }
    }
}
