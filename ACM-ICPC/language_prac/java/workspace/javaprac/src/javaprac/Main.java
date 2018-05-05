package javaprac;

import java.util.*;

public class Main {

    public static Scanner in = new Scanner(System.in);

    public static int cini() {
        return in.nextInt();
    }

    public static void main(String[] args) {
        int n, c;
        n = cini(); c = cini();
        int [] arr = new int [n];
        for (int i = 0; i < n; ++i) arr[i] = cini();
        int cmp = arr[0];
        int [] dt = new int[n];
        int cnt = 0;
        for (int i = 0; i < n; ++i) { 
            if (cmp == arr[i]) {
                dt[cnt]++;
            } else {
                cmp = arr[i];
                dt[++cnt] = 1;
            }
        }
        cnt++;
        int [][] dp = new int [c + 1][3];
        for (int i = 0; i < n; ++i) {
            for (int j = c; j >= 0; --j) {
            }
        }
        
    }
    private static int max(int i, int j) {
        return i > j ? i : j;
    }
}
