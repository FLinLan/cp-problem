#!/usr/bin/env python3
import sys
import math
from collections import defaultdict, Counter, deque
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from typing import List, Tuple, Set, Dict

# File I/O setup
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

def inp(): return sys.stdin.readline().strip()
def iinp(): return int(inp())
def linp(): return list(map(int, inp().split()))

def solve():
    # Read input
    n = iinp()  # number of elements
    arr = linp()  # array input
    
    # Your solution here
    answer = 0
    
    # Return answer
    return answer

def main():
    # For single test case
    print(solve())
    
    # For multiple test cases
    # t = iinp()
    # for _ in range(t):
    #     print(solve())

if __name__ == "__main__":
    # For faster I/O
    input = sys.stdin.readline
    sys.setrecursionlimit(1000000)  # For deep recursion
    
    try:
        main()
    finally:
        # Close files
        sys.stdin.close()
        sys.stdout.close()