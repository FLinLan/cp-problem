import java.io.*;
import java.util.*;

// javac CoinPiles.java && java CoinPiles < input.txt > output.txt
public class CoinPiles {
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
    
    public static boolean validPiles(int a, int b) {
        if ((a + b) % 3 != 0) return false;
        if (a > 2*b || 2*a < b) return false;
        return true;
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int T = Integer.parseInt(fs.next());
        
        for (int i = 0; i < T; i++) {
            int a = Integer.parseInt(fs.next());
            int b = Integer.parseInt(fs.next());
            
            if (validPiles(a, b)) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        }
        out.close();
    }
}
