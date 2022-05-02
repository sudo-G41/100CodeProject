CC = gcc
CFLAGS = -W -Wall
TARGET = Main
OBJS = graph.o graphArr.o main.o #또는 OBJECTS = memo4.o calender4.o main4.o ... 솔직히 아무 상관 없는거 아니야?

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#내장 기능에 의해 OBJS에 있는 파일 못찾으면 같은 이름의 c파일 찾아서 object파일로 바꿔줌
#OBJS들의 의존성 추가 memo4.o : memo4.c memo.h <= 안해도 되긴 하지만 헤더파일이 변경되면 오류 발생 가능해서 해두는게 좋음
graph.o : graph.h graph.c
graphArr.o : graphArr.h graphArr.c

clean :
	rm *.o Main
