import java.io.*;
import java.util.*;

// javac BitStrings.java && java BitStrings < input.txt > output.txt
public class BitStrings {
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
        int mod = (int)1e9 + 7;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = (ans * 2) % mod;
        }
        return ans;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        
        int n = Integer.parseInt(fs.next());
        
        out.println(count(n));
        out.close();
    }
}
