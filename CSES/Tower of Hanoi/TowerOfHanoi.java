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
    
    public static void hanoi(int n, int src, int dst, List<List<Integer>> moves) {
        if (n == 1) {
            moves.add(Arrays.asList(src, dst));
            return;
        }
        int aux = 6 - src - dst;
        hanoi(n-1, src, aux, moves);
        moves.add(Arrays.asList(src, dst));
        hanoi(n-1, aux, dst, moves);
        return;
    }
 
    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);

        int n = Integer.parseInt(fs.next());
        
        List<List<Integer>> moves = new ArrayList<>();
        hanoi(n, 1, 3, moves);

        out.println(moves.size());
        for (List<Integer> move : moves) {
            int src = move.get(0);
            int dst = move.get(1);
            out.println(src + " " + dst);
        }
        out.close();
    }
}
