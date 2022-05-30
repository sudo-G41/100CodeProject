from sys import stdin
input = stdin.readline

def A(l:int,r:int,k:int)->None:
        if k==2:
                if r<3:
                        print(0)
                else:
                        l = 3 if l<3 else l
                        print(r-l+1)
        elif k==3:
                #L[l mod 3][counting]
                L = [[0,1,1],[0,0,0],[0,0,1]]
                if r<6:
                        print(0)
                else:
                        l = 6 if l<6 else l
                        tmp = (r-l+1)
                        print(tmp//3 + L[l%3][tmp%3])
        elif k==4:
                if r<10:
                        print(0)
                else:
                        l = 10 if l<10 else l
                        r1 = (r-4)//6
                        r2 = (r-8)//6
                        r3 = (r-12)//6 if r>17 else 0
                        l1 = (l-4)//6 - (1 if (l-4)%6==0 else 0)
                        l2 = (l-8)//6 - (1 if (l-8)%6==0 else 0)
                        l3 = (l-12)//6 - (1 if (l-12)%6==0 else 0) if l>17 else 0
                        print(r1+r2+r3-l1-l2-l3)
        elif k==5:
                if r<15:
                        print(0)
                else:
                        l = 15 if l<15 else l
                        tmpR = r//5
                        tmpL = l//5
                        print(tmpR-tmpL+(1 if l%5==0 else 0))

if __name__ == "__main__":
        l,r,k = input(),input(),input()
        while l:
                l,r,k = list(map(int,(l,r,k)))
                A(l,r,k)
                l,r,k = input(),input(),input()