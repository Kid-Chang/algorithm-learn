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