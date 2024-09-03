import java.io.*;
import java.util.*;

// javac TowerOfHanoi.java && java TowerOfHanoi < input.txt > output.txt
public class TowerOfHanoi {
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

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(fs.next());

        // Base Case 1
        if (n == 1) {
            out.println("1");
            out.println("1 3");
            out.close();
            return;
        }

        // Base Case 2
        if (n == 2) {
            out.println("3");
            out.println("1 2");
            out.println("1 3");
            out.println("2 3");
            out.close();
            return;
        }

        int moves = 3*(n-2);

        out.println(moves);
        out.println("1 2");
        out.println("1 3");
        out.println("2 3");

        for (int i = 0; i < n-2; i++) {
            out.println("3 2");
            out.println("1 3");
            out.println("2 3");
        }
        out.close();
    }
}
