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

if __name__=="__main__":
    game_board = [[0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0], [1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0], [1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1], [0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0], [0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1], [0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0], [0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0], [1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0], [0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0], [0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1], [0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0]]
    table = [[1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1], [1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1], [1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0], [0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0], [1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0], [1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1], [1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1], [0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1], [1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1], [1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1], [1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1]]
    for i in game_board:
        print(i)
    print("======")
        
    for i in table:
        print(i)
    print("======")

    print(solution(game_board, table))