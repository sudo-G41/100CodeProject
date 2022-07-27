# Programmers[Lv3 베스트앨범](https://programmers.co.kr/learn/courses/30/lessons/42579)
## 문제
 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
1. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
1. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.

## 제한사항 
* genres[i]는 고유번호가 i인 노래의 장르입니다.
* plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
* genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
* 장르 종류는 100개 미만입니다.
* 장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
* 모든 장르는 재생된 횟수가 다릅니다.

## 내 풀이
 C++의 map과 set은 해쉬를 이용하는 것은 아니지만 red-black트리를 이용하여 안정적인 이진트리를 형성하여 탐색시 $O(NlogN)$을 보장해준다. 물론 해쉬를 기준으로 하는 map과 set을 설정 할 수 있지만 제한사항을 보면 많은 것도 아니며 red-black를 사용하여 heap과 같이 정렬이 된다는 장점이 있어서 이 문제를 풀때 red-black를 이용한 기본 map과 set를 사용하였다.
 
 문제를 풀기 위해 2개의 맵과 1개의 셋을 사용되었는데 각각

 * genresPlayId = key : 장르, value : 재생시간을 키로가지고 노래 고유번호를 값으로 가지는 또다른 맵
 * genresAllPlay = key : 총 재생시간, value : 장르
 * playGenres = 총 재생시간을 기준으로 장르가 정렬된 셋

 이렇게 사용되었다.

 처음에 genres와 plays를 같이 순회하면서 genresPlayId와 genresAllPlay에 맞게 입력을 하고 입력이 끝나면 playGenres에 다시 입력하여 1번 조건을 맞추어 준다.

 그 뒤 playGenres를 따라가면서 해당 장르에서 1~2개를 꺼내와서 앨범에 넣어주는데 이때, 꺼낼때 가장 많이 재생된 노래의 가장 작은 고유번호를 넣어주고 그 뒤 가장 많이 재생된 노래가 여러개면 그 다음 고유번호를 넣어주고, 아니면 다음으로 많이 재생된 노래중 가장 작은 고유번호를 넣어준다. 둘다 아니면 이 장르는 1개의 노래만 앨범에 들어가는 것이다.

 즉

 1. 총 재생횟수가 많은 장르의 가장 많이 재생된 노래를 앨범에 넣는다.
 1. 같은 장르내에 먼저 들어간 노래와 재생횟수가 같은 노래가 있는지 확인하고 있으면 그 다음 번호의 노래를 앨범에 넣어준다.
 1. 같은 장르내에 먼저 들어간 노래와 재생횟수가 같은 노래가 없다면 다음으로 많이 재생된 노래를 찾아서 넣어준다.
 1. 다음으로 많이 재생된 노래도 없다는 것은 이 장르는 노래가 한곡 밖에 없다는 이야기이므로 처음 1곡으로 끝내고 다음으로 총 재생횟수가 많은 장르를 선택하여 1번부터 반복한다.

 와 같은 구조로 반복하여 앨범을 완성시킨다.

## 구현([전체 코드 파일](/programmers/42579%EB%B2%A0%EC%8A%A4%ED%8A%B8%EC%95%A8%EB%B2%94/c.cc))
``` cpp
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,map<int,set<int>>> genresPlayId;
    map<string,int> genresAllPlay;
    set<pair<int,string>> playGenres;

    for(int idx=0; idx<genres.size(); idx++){
        genresPlayId[genres[idx]][plays[idx]].insert(idx);
        genresAllPlay[genres[idx]]+=plays[idx];
    }

    for(auto it=genresAllPlay.begin(); it!=genresAllPlay.end();it++){
        playGenres.insert({it->second, it->first});
    }

    for(auto pg=playGenres.rbegin(); pg!=playGenres.rend(); pg++){
        auto gp = genresPlayId[pg->second];
        auto gpi = gp.rbegin();
        auto no = gpi->second.begin();
        answer.push_back(*no);
        if(gpi->second.size()>1){
            no++;
            answer.push_back(*no);
        }
        else if(gp.size()>1){
            gpi++;
            auto no = gpi->second.begin();
            answer.push_back(*no);
        }
    }

    return answer;
}
```

## 잡담
아 처음에 1곡만 있으면 1곡만 넣는거 몰라서 틀리고

장르 내에서 최대 재생횟수가 같은 여러 노래가 있는 경우 생각 안해서 틀리고

마지막으로 총 재생횟수인거 몰라서 틀리고....

아니.... 나 왜이러냐... 국어부터 다시 배워와라...