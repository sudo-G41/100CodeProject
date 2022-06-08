from sys import stdin
input = stdin.readline

U,F = map(int,input().strip().split())
group_list = {}
file_list = {}

for _ in range(U):
    user = input().strip().split()
    if user[0] not in group_list:
        group_list[user[0]] = set([user[0]])
    if len(user)>1:
        for group in user[1].split(","):
            if group in group_list:
                group_list[group].add(user[0])
            else:
                group_list[group] = set([user[0]])
                
for _ in range(F):
    file = input().strip().split()
    file_list[file[0]] = {}
    file_list[file[0]]["RWX"] = list(map(int,list(file[1])))
    file_list[file[0]]["OWNER"] = file[2]
    file_list[file[0]]["GROUP"] = file[3]

Q = int(input().strip())

for _ in range(Q):
    name, file, rwx = input().strip().split()
    rwx = 0b100 if rwx=="R" else (0b010 if rwx=="W" else 0b001)
    if name == file_list[file]["OWNER"]:
        print(1 if rwx&file_list[file]["RWX"][0] else 0)
    elif name in group_list[file_list[file]["GROUP"]]:
        print(1 if rwx&file_list[file]["RWX"][1] else 0)
    else:
        print(1 if rwx&file_list[file]["RWX"][2] else 0)