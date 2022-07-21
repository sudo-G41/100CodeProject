from sys import stdin
input = stdin.readline

def solution():
    w, h = map(int, input().strip().split())
    place = [[0 for _ in range(w+2)]]
    for _ in range(h):
        place.append([0]+list(map(int, input().strip().split()))+[0])
    place.append([0 for _ in range(w+2)])
    building = [[True for _ in range(w+2)] for _ in range(h+2)]

    q=[[0,0]]
    check_x = [
        [-1, 0, 1, 0, -1, -1],
        [0, 1, 1, 1, 0, -1]
    ]
    check_y = [-1, -1, +0, +1, +1, +0]
    wall = 0
    while q:
        _x, _y = q.pop(0)
        for idx in range(len(check_y)):
            x, y = _x+check_x[_y%2][idx], _y+check_y[idx]
            if 0>x or x>len(building[0])-1:
                continue
            if 0>y or y>len(building)-1:
                continue
            if place[y][x] == 1:
                wall += 1
            elif building[y][x]:
                q.append([x,y])
                building[y][x] = False

    return wall

if __name__ == "__main__":
    print(solution())