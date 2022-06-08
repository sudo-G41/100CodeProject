from sys import stdin
input = stdin.readline

hour, mint = map(int,input().strip().split(":"))
papulatus_pattern = list(map(int,input().strip().split()))
L = int(input().strip())
idx_set = set()
for qwer in range(L):
    sT, user_event = input().strip().split()
    if float(sT)>60:
        break
    if len(idx_set)==6:
        break

    if user_event =="^":
        papulatus_pattern[hour//2] = 0
        idx_set.add(hour//2)
    elif user_event[-1] == "N":
        mint += int(user_event[:-3])
        hour = (hour+mint//60)%12
        mint %= 60
    else:
        hour += int(user_event[:-4])
        hour %= 12

dk = sum(papulatus_pattern)

print(dk if dk<100 else 100)