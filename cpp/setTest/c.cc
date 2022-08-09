#include<iostream>
#include<set>

using namespace std;

int main(){
        set<int> s;
        s.insert(10);
        auto it = s.begin();
        cout<<*it<<'\n';

		/* where is it pointer */
        s.insert(7);
        cout<<*it<<' '<<*(s.begin())<<'\n';
        s.insert(11);
        cout<<*it<<' '<<*(s.begin())<<'\n';
        s.insert(9);
        cout<<*it<<' '<<*(s.begin())<<'\n';
        s.insert(1);
        cout<<*it<<' '<<*(s.begin())<<'\n';

		/* it + or - */
		cout<<"set in 1, 7, 9, 10, 11\n";
        cout<<"it value "<< *it<<'\n';
		it++;
		cout<<"it++ value "<< *it<<'\n';
		it--;
		cout<<"it-- value "<< *it<<'\n';
		it--;
		cout<<"it-- value "<< *it<<'\n';
		it--;
		cout<<"it-- value "<< *it<<'\n';
		s.insert(8);
		it++;
		cout<<"insert 8 aafter it++ value "<< *it<<'\n';

		/* erase */
		s.erase(10);
		cout<<"erase 10 aafter it value "<< *it<<'\n';
		it++;
		cout<<"it++ value "<< *it<<'\n';
		it--;
		cout<<"it-- value "<< *it<<'\n';
		s.erase(9);
		it++;
		cout<<"eraes 9 after it++ value "<< *it<<'\n';
        return 0;
}
