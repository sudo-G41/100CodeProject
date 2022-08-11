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

## 고찰 2
### 내용
multiset에 중복되는 원소가 들어가면 어떻게 되는가

set는 중복을 허용하지 않는다. 그래서 중복되는 원소가 들어오면 사라지는건지 아님 안 들어가는지는 모르지만(이것도 나중에 확인하면 좋겠다...)multiset는 중복을 허용하는데 그럼 1, 2, 3이렇게 있었을때 2번을 추가한다고 하면 그 2번은 1과 2사이에 들어갈 것인가 아니면 2와 3사이에 들어갈 것인가. 그거를 확인해보자.

### 실험 코드
``` cpp
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
    return 0;
}
```
### 결과
![그림2](./multiset%20%EC%A4%91%EB%B3%B5%EB%90%9C%20%EC%9B%90%EC%86%8C%EB%8A%94%20%EC%96%B4%EB%94%94%EB%A1%9C%20%EA%B0%80%EB%8A%94%EA%B0%80.png)

맨 처음 삽입된 10번을 가리키고 있는 iterator가 ++된 값은 10 --된 값은 9가 되는 것을 볼 수 있다.  
즉 기존에 있던 원소와 중복되면 그 원소의 뒤에 들어온다는 것을 알 수 있다.  
그럼 2개가 중복된 상태에서는? 이라면 맨 마지막을 보면 10->10이 되는 것을 볼 수 있는데 이는 중복된 원소의 맨 마지막으로 이동 한다는 것을 나타낸다 볼 수 있다.  
왜 이런 현상이 이러나느냐는 set를 선언할때 comp를 주어 오름차순으로 할지 내림차순으로 할지 구조체나 클래스는 어떤 기준으로 정렬할지 정할 수 있는데 아마 여기서 이 bool값을 주는 것에 의해서 저런 현상이 발생하는 것으로 추측된다.  
즉 bool값이라 작은가? 크거나 같은가 이런 느낌으로 또는 작거나 같은가? 큰가 이런식으로 둘중 하나만 되지 3개 다 비교할 수 있지는 않으니 기본현태는 같다랑 큰쪽이랑 묶이는 것이 아닌가 생각된다.