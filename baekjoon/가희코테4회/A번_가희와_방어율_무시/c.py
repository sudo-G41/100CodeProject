from sys import stdin
input = stdin.readline

def A(a,b):
    print(1 if (a-(a*b/100))<100 else 0)

if __name__ == "__main__":
    while s := input().strip().split():
        a,b = map(int,s)
        A(a,b)