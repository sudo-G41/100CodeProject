#include <string>
#include <vector>
#include<set>
#include<map>

#include<iostream>

using namespace std;

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