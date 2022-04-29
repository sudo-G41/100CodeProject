# diary_exe2 : memo.o calender.o main.o 
# 	gcc -o diary_exe2 memo.o calender.o main.o

# memo2.o : memo.c
# 	gcc -o memo2.o memo.c

# calender2.o : calender.c
# 	gcc -o calender2.o calender.c

# main2.o : main.c
# 	gcc -o main2.o main.c

# clean :
# 	rm *.o diary_exe2

# CC = gcc
# CFLAGS = -W -Wall
# TARGET = diary_exe3

# $(TARGET) : memo3.o calender3.o main3.o
# 	$(CC) $(CFLAGS) -o $(TARGET) memo3.o calender3.o main3.o

# memo3.o : memo.c
# 	$(CC) $(CFLAGS) -c -o memo3.o memo.c

# calender3.o : calender.c
# 	$(CC) $(CFLAGS) -c -o calender3.o calender.c

# main3.o : main.c
# 	$(CC) $(CFLAGS) -c -o main3.o main.c

# clean :
# 	rm *.o diary_exe3

CC = gcc
CFLAGS = -W -Wall
TARGET = diary_exe4
OBJS = memo4.o calender4.o main4.o #또는 OBJECTS = memo4.o calender4.o main4.o ... 솔직히 아무 상관 없는거 아니야?

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

#내장 기능에 의해 OBJS에 있는 파일 못찾으면 같은 이름의 c파일 찾아서 object파일로 바꿔줌
#OBJS들의 의존성 추가 memo4.o : memo4.c memo.h <= 안해도 되긴 하지만 헤더파일이 변경되면 오류 발생 가능해서 해두는게 좋음
calender4.o : diary.h calender4.c

clean :
	rm *.o diary_exe4