from sys import stdin
import sys
input = stdin.readline
sys.setrecursionlimit(4000001)

def solution():
    def find(d,c):
        if d[c] == c:
            return c
        else:
            d[c] = find(d, d[c])
            return d[c]

    N,M,K = map(int, input().strip().split())
    deck = [i+1 for i in range(N+1)]
    for card in map(int, input().strip().split()):
        deck[card] = card

    print(deck)

    for fraud in map(int, input().strip().split()):
        card = find(deck, fraud+1)
        print(card)
        deck[card] = card+1

solution()
