#include<iostream>
#include<vector>

int solution(int n, std::vector<int> &function);

int main(int argc, char** argv){
    int T;
    scanf("%d",&T);
    for(int t = 0; t<T; t++){
        int n;
        scanf("%d",&n);
        std::vector<int> function(n+1, 0);
        function[1] = 1;
        function[2] = 2;
        function[3] = 4;
        printf("%d\n", solution(n, function));
    }
}

int solution(int n, std::vector<int> &function){
    if(n<4)
        return function[n];
    
    if(function[n])
        return function[n];
    
    return function[n] = (solution(n-1, function)+solution(n-2, function)+solution(n-3, function));
}