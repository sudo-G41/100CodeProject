def input_maker():
    N = 300000
    count = 0
    with open("input.txt", "w") as f:
        f.write("")

    for _ in range(3):
        for _ in range(5):
            with open("input.txt", "a") as f:
                l = [str(i)+"\n" for i in range(N)]
                f.write("".join(l))
                count += len(l)

        for _ in range(5):
            with open("input.txt", "a") as f:
                l = [str(i+(i%100000)/100000)+"\n" for i in range(N)]
                f.write("".join(l))
                count += len(l)

        for _ in range(5):
            with open("input.txt", "a") as f:
                strList = ["The quick brown fox jumps over the lazy dog\n", "다람쥐 헌 쳇바퀴에 타고파\n", "いろはにほへど ちりぬるを わがよたれぞ つねならむ うゐのおくやま けふこえて あさきゆめみじ ゑひもせず\n", "닭 잡아서 치킨파티 함\n"]
                for i in range(N):
                    f.write(strList[(i%len(strList))])
                    count += 1

    print("counting :", count)

def input_line_count():
    count = 0
    with open("input.txt", "r") as f:
        while f.readline():
            count +=1
    print("counting :", count)

if __name__ == "__main__":
    if int(input("1번 만들기, 그외 라인수 카운트")) == 1:
        input_maker()
    else:
        input_line_count()