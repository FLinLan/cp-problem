import java.io.*;
import java.util.*;

// javac CreatingStrings.java && java CreatingStrings < input.txt > output.txt
public class CreatingStrings {
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

    public static String convertString(List<Character> list) {
        String ans = "";
        for (Character ch : list) {
            ans += ch;
        }
        return ans;
    }

    public static void backtrack(String s, Set<String> ans, List<Character> path, boolean[] vis) {
        if (path.size() == s.length()) {
            ans.add(convertString(path));
            return;
        }

        for (int i = 0; i < s.length(); i++) {
            if (!vis[i]) {
                vis[i] = true;
                path.add(s.charAt(i));
                backtrack(s, ans, path, vis);
                path.remove(path.size() - 1);
                vis[i] = false;
            }
        }

        return;
    }
    
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        String s = fs.next();

        boolean[] vis = new boolean[s.length()];
        
        Set<String> ans = new TreeSet<>();
        List<Character> path = new ArrayList<>();

        backtrack(s, ans, path, vis);

        out.println(ans.size());
        for (String str : ans) {
            out.println(str);
        }
        out.close();
    }
}
