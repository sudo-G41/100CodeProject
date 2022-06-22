#include<iostream>
#include<string>
#include<set>
#include<sstream>

void sortString(std::string s);
std::multiset<std::string> split(std::string str, char Delimiter=' ');

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string A;
    std::getline(std::cin,A,'\n');
    sortString(A);
    std::getline(std::cin,A,'\n');
    sortString(A);
    return 0;
}

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