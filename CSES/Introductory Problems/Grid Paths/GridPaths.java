import java.io.*;
import java.util.*;

// javac GridPaths.java && java GridPaths < input.txt > output.txt
public class GridPaths {
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

    static int uniquePaths(int r, int c, int ROW, int COL, int[][] vis) {
        if (r == 0 && c == 0) return 1;
        if (r < 0 || c < 0 || r >= ROW || c >= COL || vis[r][c] != -1) return 0;
        
        return vis[r][c] = (uniquePaths(r-1, c, ROW, COL, vis) + uniquePaths(r, c-1, ROW, COL, vis) +
                            uniquePaths(r+1, c, ROW, COL, vis) + uniquePaths(r, c+1, ROW, COL, vis)); 
    }
    
    static void solve(FastScanner fs, PrintWriter out) {
        // Solution for each test case goes here
        // Example:
        int m = fs.nextInt();
        int n = fs.nextInt();

        int[][] vis = new int[m][n];
        for (int i = 0; i < vis.length; i++) {
            for (int j = 0; j < vis[i].length; j++) {
                vis[i][j] = -1;
            }
        }
        System.out.println(uniquePaths(m, n, m, n, vis));
    }
}
