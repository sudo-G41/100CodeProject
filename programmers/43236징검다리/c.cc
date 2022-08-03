#include <vector>
#include<set>
#include<iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    set<int> sort;
    vector<int> sortAfterRocks;
    sort.insert(0);
    sort.insert(distance);
    for(auto it = rocks.begin(); it!=rocks.end(); it++)
        sort.insert(*it);
    

    for(auto it = sort.begin(); it!=--sort.end();){
        int a,b;
        b = *it;
        it++;
        a=*it;
        sortAfterRocks.push_back(a-b);
    }
    
    int min, max, mid;
    min = sortAfterRocks.front();
    max = distance;
    for(auto it:sortAfterRocks){
        cout<<it<<' ';
    }
    cout<<'\n';
    
    while(max!=min+1){
        mid = (min+max)/2;
        int distanceRocks, idx, count, boom;
        count = mid;
        distanceRocks = idx = boom = 0;
        cout<< min<<','<<mid<<','<<max<<"minmidmax\n";
        while(idx<sortAfterRocks.size()){
            cout<<distanceRocks<<'+'<<sortAfterRocks[idx]<<'\n';
            distanceRocks += sortAfterRocks[idx];
            if(distanceRocks<mid){

            }
            if(distanceRocks+sortAfterRocks[idx]<=mid){
                distanceRocks += sortAfterRocks[idx++];
                boom++;
            }
            else{
                count = count<distanceRocks? count: distanceRocks;
                distanceRocks=sortAfterRocks[idx++];
            }
        }
        (boom>n? max: min) = mid;
        cout<< min<<','<<max<<":"<<boom<<'\n';
    }
    return max;
}

int main(){
    vector<int> v = {2, 14, 11, 21, 17};
    cout<<solution(25, v, 2);
}