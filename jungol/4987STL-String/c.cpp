#include<iostream>
#include<string>

std::string input(std::string A, std::string B);

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string A,B;
    std::cin>>A>>B;
    std::cout<<input(A,B);
    return 0;
}

std::string input(std::string A, std::string B){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string s,result;
    result = "";
    while(s!=A){
        std::cin>>s;
        if(s==A){
            break;
        }
        if(s.size()==3){
            result+=s;
        }
        else if(s.size()>=B.size()+3){
            if(s.find(B)==3){
                result+=s;
            }
        }
    }
    return result;
}
