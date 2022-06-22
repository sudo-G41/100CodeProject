# Jungol[STL - String 2 (stringstream)](http://www.jungol.co.kr/bbs/board.php?bo_table=pbank&wr_id=4720&sca=2050)
## 문제
    두 줄의 문장을 입력받아 각각 정렬시켜 출력하시오.

## 입력형식 
    두 줄의 문자열이 공백을 포함하여 입력된다. 이 때, 각 줄의 길이는 1이상 100이하이다.

## 출력형식
    첫 번째 줄은 첫 번째 입력받은 문자열의 단어들을 사전순으로 정렬하여 출력하시오.
    두 번째 줄은 두 번째 입력받은 문자열의 단어들을 사전순으로 정렬하여 출력하시오.​​

## 내 풀이
 java나 python은 split이 있지만 C++은 없다. 그래서 구현해서 써야 하는데 보통은 list구조인 vector로 반환하지만 나는 C++의 set의 구조적 특성을 이용하기 위해 set로 반환하였다.
 우선은 c++의 set는 중복을 허락하지 않는 집합으로 Red-Black Tree구조를 가지고 있어서 O($N log N$)속도로 원소를 탐색하는 점도 있지만 순서대로 정렬해 준다는 점도 있다. 즉 사전순서대로 자동으로 정렬되므로 set에 넣기만 하면 정렬이 끝나있다.

 하지만 같은 단어가 들어오면 set는 중복을 허락하지 않기 때문에 여기서 multiset이란 것이 등잔한다. multiset은 중복을 허락하는 set라 보면 된다. 그래서 split함수를 만들때 vector에 넣는 것이 아닌 multiset에 넣어서 반환하고 그것을 그대로 순서대로 출력해 주면 된다.

## 구현([전체 코드 파일](/jungol/5096%3ASTL-String2(stringstream)/c.cc))
``` cpp
void sortString(std::string s){
    std::ios::sync_with_stdio(false);
    std::multiset<std::string> dict = split(s);
    for(auto it = dict.begin();it!=dict.end();it++){
        std::cout<<*it<<' ';
    }
    std::cout<<'\n';
}

std::multiset<std::string> split(std::string str, char Delimiter){
    std::istringstream iss(str);
    std::string buffer;
 
    std::multiset<std::string> result;
 
    while (std::getline(iss, buffer, Delimiter)) {
        result.insert(buffer);
    }
 
    return result;
}
```

## 잡담
 아 정올 오랜만에 하니 재미있다. 근데 정올 왜 시작했냐하면 우리 교수님이 방학특강 하실 때 애들 정올로다가 가르치셔서 아 혹시 하고 가보니 애들 풀고있는거 같았다.

 그래서 그 사이에 내 이름 살짝 넣고 싶어서 해봤다.. ㅋㅋㅋ

 그리고 왜 c++은 split이 없는 것이지..??? 왜지...?? 뭐지???? 흠.....