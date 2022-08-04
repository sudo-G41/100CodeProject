# Programmers[Lv 3 퍼즐 조각 채우기](https://programmers.co.kr/learn/courses/30/lessons/84021)
## 문제
 테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈 공간에 적절히 올려놓으려 합니다. 게임 보드와 테이블은 모두 각 칸이 1x1 크기인 정사각 격자 모양입니다. 이때, 다음 규칙에 따라 테이블 위에 놓인 퍼즐 조각을 게임 보드의 빈칸에 채우면 됩니다.

    조각은 한 번에 하나씩 채워 넣습니다.
    조각을 회전시킬 수 있습니다.
    조각을 뒤집을 수는 없습니다.
    게임 보드에 새로 채워 넣은 퍼즐 조각과 인접한 칸이 비어있으면 안 됩니다.

현재 게임 보드의 상태 game_board, 테이블 위에 놓인 퍼즐 조각의 상태 table이 매개변수로 주어집니다. 규칙에 맞게 최대한 많은 퍼즐 조각을 채워 넣을 경우, 총 몇 칸을 채울 수 있는지 return 하도록 solution 함수를 완성해주세요.

## 제한사항 

* 3 ≤ game_board의 행 길이 ≤ 50
* game_board의 각 열 길이 = game_board의 행 길이
    * 즉, 게임 보드는 정사각 격자 모양입니다.
    * game_board의 모든 원소는 0 또는 1입니다.
    * 0은 빈칸, 1은 이미 채워진 칸을 나타냅니다.
    * 퍼즐 조각이 놓일 빈칸은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
* table의 행 길이 = game_board의 행 길이
* table의 각 열 길이 = table의 행 길이
    * 즉, 테이블은 game_board와 같은 크기의 정사각 격자 모양입니다.
    * table의 모든 원소는 0 또는 1입니다.
    * 0은 빈칸, 1은 조각이 놓인 칸을 나타냅니다.
    * 퍼즐 조각은 1 x 1 크기 정사각형이 최소 1개에서 최대 6개까지 연결된 형태로만 주어집니다.
* game_board에는 반드시 하나 이상의 빈칸이 있습니다.
* table에는 반드시 하나 이상의 블록이 놓여 있습니다.


## 내 풀이
 테이블을 조각내고 게임보드를 조각내서 비교하는 문제다.  
 솔루션에서 우선 테이블을 searchPiece라는 함수로 조각내면서 돌린 모양과 각 조각의 크기를 저장한다. 이때 [1,1,1,1] 같이 0도와 180도 회전한 모양이 서로 같은 경우 0도와 90도로 회전한 조각만 가지도록 한다.  
 그 후 게임보드를 조각내어 해당 조각의 크기와 같은 조각들을 비교하여 같은 모양을 가지는 조각과 그의 회전모양의 조각을 빼내고 해당 크기를 계속 더하는 식으로 얼마나 채울 수 있는지 출력한다.  

### 조각내기
 테이블과 게임보드를 어떻게 조각내는 방법은 테이블(게임보드)를 0,0부터 ( $N,N$ )까지 순차적으로 탐색하면서 조각에 해당하는 숫자가 나오면(테이블은 1, 게임보드는 0) bfs를 통해 연결된 좌표들을 저장하면서 좌표들중 가장 작은 x,y와 가장 큰 x,y를 찾아서 퍼즐조각의 크기를 정한다.  
 그 후 정해진 크기에 맞게 만든 2차원 배열에 x,y좌표 - 가장 작은 x,y를 뺀 값에 퍼즐조각을 그려주어 퍼즐을 만든다.  
### 회전하기
 테이블에서 만들어진 조각은 회전도 시켜야 하는데 회전은 아래 그림을 보자  
 ![그림1](./%EA%B7%B8%EB%A6%BC1.png)  
 사실 그림은 왼쪽에서 반시계방향으로 돌려서 오른쪽 표를 만든것이지만 오른쪽 입장으로는 자신을 시계방향으로 돌려 왼쪽 표를 만든 그림이다.  
 사족은 그만하고 오른쪽의 표 안에 적힌 숫자는 왼쪽 표의 원소들이 반시계방향으로 돌아서 어디와 매칭되는지 적은 좌표들이다.  
 즉 오른쪽의 0,0은 왼쪽의 0,0좌표에 있는 값이 반시계방향으로 돌면 위치하는 곳을 나타낸다.  
 이때 오른쪽은 왼쪽 표를 봤을때 왼쪽의 y가 오른쪽의 x값에 위치하는 것을 볼 수 있다.  
 시계방향으로 돌릴 때 왼쪽의 y줄에는 오른쪽의 x줄에 있는 것을 넣으면 된다는 것을 알 수 있다. 왼쪽의 y를 찾았으니 왼쪽의 x에 무엇이 들어가야 하는지 확인해보자.(반시계방향은 오른쪽의 x에 해당하는 줄을 왼쪽의 y에 해당하는 줄에서 가져오면 된다.)  
 그럼 왼쪽의 y와 오른쪽의 x가 관계있으니 왼쪽의 x는 y와 관계 있는 것이 아닐까 하고 둘을 비교해보자. 3x3 표를 보면 x가 0인 애들은 반시계 방향으로 돌리면 y의 맨 밑인 2에 들어가고 1은 그대로 1, 2는 0에 안착하는 것을 볼 수 있다. 사이즈를 좀더 키워보면 서로 반대되는 위치(x가 0~9라면 y는 9~0이라는 이야기)에 해당 하는 것을 볼 수 있는데 이는 x = max(y or x)-y로 표현이 가능하므로 둘의 관계는 x = max(y or x)-y가 될 것이다.(아래 코드에서 -1이 더 붙는 이유는 사이즈는 인덱스의 최대값보다 1 크기 때문에 1을 빼준 것이다.)  
 이를 좀더 표현해보면 왼쪽의 x,y는 오른쪽의 max(y)-y,x 관계라는 것이다.  
 이 점을 이용해 시계방향이든 반시계방향이든 한쪽으로만 3번 돌리면 처음의 모양을 포함한 4가지의 모양이 나온다.  

## 구현([전체 코드 파일](/programmers/84021%ED%8D%BC%EC%A6%90%EC%A1%B0%EA%B0%81%EC%B1%84%EC%9A%B0%EA%B8%B0/c.py))
``` python
def solution(game_board, table):
    answer = 0
    size_table = {}
    for y in range(len(table)):
        for x in range(len(table)):
            if(table[y][x]==1):
                pieces = searchPiece(table,x,y)
                if(pieces["c"] not in size_table):
                    size_table[pieces["c"]] = []
                size_table[pieces["c"]].append(pieces)

    for y in range(len(game_board)):
        for x in range(len(game_board)):
            if(game_board[y][x]==0):
                board = searchPiece(game_board,x,y,0,1,False)
                answer += rm_piece(board, size_table)
                
    return answer

def searchPiece(table, _x, _y, flag_in=1, flag_out=0, flag_turn = True):
    move = [
        [0, 0, 1,-1],
        [1,-1, 0, 0]
    ]
    minX = minY = 51
    maxX = maxY = 0
    q = [(_x,_y)]
    table[_y][_x] = flag_out
    piece = []
    count_piece = 1
    while(q):
        x,y = q.pop(0)
        piece.append((x,y))
        minX = min(minX, x)
        minY = min(minY, y)
        maxX = max(maxX, x)
        maxY = max(maxY, y)
        for i in range(len(move[0])):
            X = move[0][i]+x
            Y = move[1][i]+y
            if(-1<X<len(table) and -1<Y<len(table)):
                if(table[Y][X] == flag_in):
                    table[Y][X] = flag_out
                    q.append((X,Y))
                    count_piece += 1
    return {"p":makePiece(piece, maxX, minX, maxY, minY, flag_turn), "c":count_piece}

def makePiece(piece, maxX, minX, maxY, minY, flag_turn):
    sizeX,sizeY = maxX-minX+1, maxY-minY+1
    tmp = [[0 for _ in range(sizeX)] for _ in range(sizeY)]
    for x,y in piece:
        tmp[y-minY][x-minX] = 1
    if(not flag_turn):
        return tmp
    pieces = [tmp]
    for _ in range(3):
        tmp = turn(tmp)
        if(tmp == pieces[0]):
            break
        pieces.append(tmp)
    return pieces

def turn(piece):
    tmp = [[0 for _ in range(len(piece))] for _ in range(len(piece[0]))]
    for x in range(len(tmp[0])):
        for y in range(len(tmp)):
            tmp[y][x] = piece[x][len(tmp)-y-1]
    return tmp

def rm_piece(board, size_table):
    if(board["c"] in size_table):
        for idx,pieces in enumerate(size_table[board["c"]]):
            for piece in pieces["p"]:
                if(piece == board["p"]):
                    size_table[board["c"]].pop(idx)
                    return board["c"]
    return 0
```

## 잡담
뭔가 갑자기 이 문제 풀다가 함수의 재사용?을 보장?하고 싶어서 뭔가 몬가 하게 짜봤다. 그렇다...  
그리고 dict에 넣어서 같은 모양의 퍼즐이 여러개 있으면 한번만 비교하고 개수를 -1하는 식으로 하면 속도 좀더 빨라지겠지만 귀찮다... 여기까지만 하자...