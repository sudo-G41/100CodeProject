#include<iostream>
#include<set>

using namespace std;

int main(){
    multiset<int> s;
    s.insert(10);
    auto it = s.begin();
    auto it1 = s.begin();
    auto it2 = s.begin();
    s.insert(9);
    s.insert(11);
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<' ';
    }
    cout<<'\n';
    cout<<"it : "<<*it<<"\n";
    it1++;
    cout<<"it++ : "<<*it1<<"\n";
    it2--;
    cout<<"it-- : "<<*it2<<"\n";

    it1 = it2 = it;
    s.insert(10);
    cout<<"insert 10\n";
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<' ';
    }
    cout<<'\n';
    cout<<"it : "<<*it<<"\n";
    it1++;
    cout<<"it++ : "<<*it1<<"\n";
    it2--;
    cout<<"it-- : "<<*it2<<"\n";
    it1 = it2 = it;
    auto nextTen = it;
    it++;

    s.insert(10);
    cout<<"and insert 10\n";
    for(auto i = s.begin(); i!=s.end(); i++){
        cout<<*i<<' ';
    }
    cout<<'\n';
    cout<<"it : "<<*it<<"\n";
    it1++;
    cout<<"it++ : "<<*it1<<"\n";
    it2--;
    cout<<"it-- : "<<*it2<<"\n";
    cout<<"next ten : "<<*nextTen<<"\n";
    nextTen++;
    cout<<"next ten++ : "<<*nextTen<<"\n";

    return 0;
}