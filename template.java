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
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);


        out.println();
        out.close();
    }
}
