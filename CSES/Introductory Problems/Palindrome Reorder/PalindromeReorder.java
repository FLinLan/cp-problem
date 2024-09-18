import java.io.*;
import java.util.*;

public class PalindromeReorder {
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

        char[] s = fs.next().toCharArray();
        int[] count = new int[26];

        for (char ch : s) {
            count[ch - 'A']++;
        }

        int oddCount = 0;
        StringBuilder middle = new StringBuilder();
        StringBuilder half = new StringBuilder();

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                oddCount++;
                middle.append((char) ('A' + i));
            }
            if (oddCount > 1) {
                out.println("NO SOLUTION");
                out.close();
                return;
            }
            // Append half of the characters for each letter
            for (int j = 0; j < count[i] / 2; j++) {
                half.append((char) ('A' + i));
            }
        }

        StringBuilder palindrome = new StringBuilder();
        palindrome.append(half);
        palindrome.append(middle);
        palindrome.append(half.reverse());

        out.println(palindrome.toString());
        out.close();
    }
}
