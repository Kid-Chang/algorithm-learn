# STL vector
vector는 배열과 거의 동일한 기능을 수행하는 자료구조

배열과 마찬가지로 원소가 메모리에 연속하게 저장되어 있기 때문에 **O(1)** 에 인덱스를 가지고 각 원소로 접근할 수 있습니다. 

**vector**는 배열과 달리 **크기를 자유자재로 늘이거나 줄일 수 있다**는 장점이 있습니다.

자세한건 [0x02_vector_example.cpp](./0x02_vector_example.cpp) 참고.

## deep copy 관련 주의사항
또 vector에서 =를 사용하면 deep copy가 발생합니다. 16번째 줄에서 v4는 {1, 2, 4}가 되었고 이후 v4를 바꿔도 v3에는 영향을 주지 않습니다.


## STL의 iterator 
따로 공부 필요


## vector 원소 순회
### 1. range-based for loop 이용
 list, map, set 등에서도 모두 사용가능

```cpp
for(int e : v1)
    stdcout << e << " ";
```
> **int e : v1**이라고 하면 복사된 값이 e에 들어가고 <br>
**int& e : v1**이라고 하면 원본이 e에 들어갑니다. 

그렇기 때문에 int e : v1라고 쓴 for문 내에서 e를 바꿔도 v1에는 영향이 가지 않지만, int& e : v1이라고 쓴 for문 내에서는 e를 바꾸면 원본인 v1에서 **실제 해당 원소의 값이 바뀌게** 됩니다.


### 2. not bad
```cpp
for(int i = 0; i < v1.size();; i++)
    cout << v1[i] << " ";
```

### 3. 틀린 방법
```cpp
for(int i = 0; i <= v1.size()-1; i++)
    cout << v1[i] << " ";
```

> 기본적으로 vector의 size 메소드는 시스템에 따라 unsigned int 혹은 unsigned long long을 반환합니다. 그렇기 때문에 32비트 컴퓨터 기준 3번같이 쓰면 v1이 **빈 vector일 때** v1.size() - 1이 unsigned int 0에서 int 1을 빼는 식이 되고, unsigned int와 int를 연산하면 unsigned int로 자동 형변환이 발생하기 때문에 (unsigned int)0 - (int)1은 **-1이 아니라 4294967295이 되어버립니다.** 4294967295이라는 이상한 값은 unsigned int overflow로 인해 생기게 된 값입니다.
<br>
그래서 아무것도 출력을 하지 않고 종료되는 것이 아닌, v1[0], v1[1], v1[2], ...  이렇게 i가 계속 커지다가 어느 순간 **런타임에러가 발생**하게 될 것입니다.

***결론은, 사이즈 구할때 -1 을 굳이굳이 쓰지말자!***