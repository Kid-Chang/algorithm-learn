# 문제를 풀면서 체크해야할 목록


## BFS
- [ ] 방향을 다루는 문제에서 `dir %= 4;` 와 같은 코드를 통해 가능한 감시방향에 범위를 제대로 지정해줬는가?
- 작성하지 않으면 틀리기도 하거나와, 시간초과가 나는 경우가 생김. ex) boj15683

## 정렬
- stable sort는 한번 정렬할 때 첫번째 조건이 동일할 경우에 어떻게 정렬할지를 분기처리하는 것,    
    merge_sort(0,n,0);
    merge_sort(0,n,1); 이런식으로 정렬하는게 아님. 이러면 순서가 깨진다.

- pair를 정렬할 때, sort() STL을 사용하면 .first -> .second 순으로 정렬하게 된다. 이 트릭을 이용하면 입력값을 .second 먼저 받게해서, 정렬 순위를 다르게 만들 수 도 있다.

- vector에서 중복을 제거하기위해 `arr.erase(unique(arr.begin(), arr.end()), arr.end());` 와 같은 형태의 코드를 이용하려면, vector의 길이가 정의되있어야한다. `vector<string> arr(n);` 이런꼴로.

- const를 쓰지않으면 오류가 생기는 경우가 있음. (왜일까...)
```
bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
}
```
와 같은 꼴로 작성하면 컴파일 에러가 발생하고,
```
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}
```
와 같은 꼴로 작성하면 정상작동 한다.

- 만약 조건문이 a<b 일때 카운트 한다 등의 경우이면, 정렬을 먼저 한 후, a>b 인 경우에는 break 하도록 하면 시간초과를 줄일 수 있다. boj7795 참고.

## DP
- 문제에서 간혹 가다가 d[i] = d[i-1] + d[i-2]라고만 써놓고 제일 마지막에 d[i] % mod 를 출력하는 식으로 짜는 분이 있습니다. 그렇게 되면 계산 중간에 int overflow가 생겨서 틀리게 되니 
계산 중간 중간에 계속 10007로 나눈 나머지만을 가져가도록 해야합니다. ex)boj11659

- Prefix sum을 문제를 푸는 과정에서 시간복잡도를 줄이는 기법 중 하나로 써먹는 경우도 종종 있어서 이 기법을 기억해두시면 좋겠습니다. ex) boj11659

- 피보나치 수는 46항에 도달하면 2971215073가 되어 int의 범위를 초과한다. 꼭 피보나치 수를 구할 때는 문제의 범위를 확실하게 봐야한다. ex)boj2193