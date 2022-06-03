#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> VVI;
typedef vector<int> VI;

vector<vector<int>> solution(int n);
void hanohi(VVI& h, int n, int l, int m, int r);
void printVVI(VVI v);

int main(){
	VVI v;
	v = solution(2);
	printVVI(v);
	v = solution(3);
	printVVI(v);
	v = solution(4);
	printVVI(v);
}

void hanohi(VVI& h, int n, int l, int m, int r){
    if(n == 1){
        h.push_back(VI({l,r}));
        return;
    }
    hanohi(h,n-1,l,r,m);
    h.push_back(VI({l,r}));
    hanohi(h,n-1,m,l,r);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanohi(answer, n, 1, 2, 3);
    return answer;
}

void printVVI(VVI v){
	// for(int i=0;i<v.size();i++){
	// 	cout<< '('<< v[i][0]<< ' '<< v[i][1]<<')';
	// }
	// cout<<'\n';
	for(auto it=v.begin();it!=v.end();it++){
		for(auto v = it->begin(); v!=it->end(); v++){
			cout<<*v<<' ';
		}
		cout<<',';
	}
	cout<<'\n';
}