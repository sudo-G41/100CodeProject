# set의 iterator에 관한 고찰 
## 고찰 1
``` cpp
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
        return 0;
}
```
위의 코드를 보면 10을 처음으로 넣고 그 위치를 처음으로 잡는다.  
그 뒤 7을 넣고 it과 begin을 확인하고 11,9,1을 넣으면서 확인한다.  
그 뒤 it을 --또는 ++시키면서 중간에 넣기도 하면서 확인한다.  

결과
![그림1](./set%20%ED%85%8C%EC%8A%A4%ED%8A%B8%20%EA%B7%B8%EB%A6%BC%201.png)  
set는 추가가 발생해도 변화가 없다.  
이걸 테스트 한 이유가 벡터는 추가 삭제가 발생하면 포인터에 변화가 생긴다고 알고 있어서 그렇다.  
나중에 vector도 이런식으로 테스트 하는 날이 언젠가 올거 같으니 그때 확인해보자.  
그리고 set에 변화가 없는 이유 나도 잘 모르지만 예상을 해보자면 요놈이 Red-Black트리를 가진다 알고 있는데 그 구현 안에 뭔가가 있어서 그러겠지... 뭐 연결 위치만 바꾼다거나 뭐 그런거....