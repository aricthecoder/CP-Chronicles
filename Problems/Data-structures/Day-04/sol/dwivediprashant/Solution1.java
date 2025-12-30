/*
Problem Summary:
- Given a partially known regular bracket sequence.
- Odd positions are missing ('_'), even positions are fixed.
- Restore missing brackets to form a valid RBS with minimum total cost.
- Cost = sum of distances between matched bracket pairs.

Key Ideas:
- Valid RBS requires balance never goes negative.
- To minimize cost, close brackets as early as possible.
- Only open a bracket when forced.

Greedy Strategy:
- Traverse left to right.
- Maintain current balance and a stack of '(' positions.
- At '_' positions:
  • If balance == 0 → must place '('
  • Else → place ')'
- At fixed positions:
  • Follow given '(' or ')'

Cost Calculation:
- On encountering ')', pop matching '(' from stack.
- Add (currentIndex - openIndex) to total cost.

Complexity:
- Time: O(n) per test case
- Space: O(n)

Problem submission link:----------------------------------------------------------------------------------
https://codeforces.com/contest/1997/submission/355801157
*/

import java.io.*;
import java.util.*;

public class Solution1 {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();
            char[] s = fs.next().toCharArray();

            int balance = 0;
            long cost = 0;
            Deque<Integer> stack = new ArrayDeque<>();

            for (int i = 0; i < n; i++) {
                if ((i & 1) == 0) {
                    if (balance == 0) {
                        stack.push(i);
                        balance++;
                    } else {
                        balance--;
                        int openPos = stack.pop();
                        cost += i - openPos;
                    }
                } else {
                    if (s[i] == '(') {
                        stack.push(i);
                        balance++;
                    } else {
                        balance--;
                        int openPos = stack.pop();
                        cost += i - openPos;
                    }
                }
            }

            out.append(cost).append('\n');
        }

        System.out.print(out);
    }

    static class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ');
            boolean neg = false;
            if (c == '-') {
                neg = true;
                c = read();
            }
            int val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return neg ? -val : val;
        }

        String next() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= ' ');
            StringBuilder sb = new StringBuilder();
            while (c > ' ') {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }
    }
}
