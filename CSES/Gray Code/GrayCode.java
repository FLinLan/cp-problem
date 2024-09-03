import java.io.*;
import java.util.*;

// javac GrayCode.java && java GrayCode < input.txt > output.txt
public class GrayCode {
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

    public static String gray(String binary) {
        StringBuilder code = new StringBuilder();
        code.append(binary.charAt(0));

        for (int i = 1; i < binary.length(); i++) {
            if (binary.charAt(i-1) != binary.charAt(i)) {
                code.append("1");
            } else {
                code.append("0");
            }
        }
        return code.toString();
    }

    public static String padding(String binary, int n) {
        while (binary.length() < n) {
            binary = "0" + binary;
        }
        return binary;
    }

    public static void solve(FastScanner fs, PrintWriter out) {
        int n = fs.nextInt();
        int bitSequence = 1 << n;

        for (int i = 0; i < bitSequence; i++) {
            String binary = padding(Integer.toBinaryString(i), n);
            System.out.println(gray(binary));
        }
    }
}
