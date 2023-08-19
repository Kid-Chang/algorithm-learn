// 다시 풀어봐야함.
// 이터레이터와 find 함수, .begin()과 .front()의 용도적 차이를 다시 이해하고 풀어보셈.


#include <bits/stdc++.h>

using namespace std;

// 회전하는 큐

// 조건
// N개의 원소를 포함하고 있는 양방향 순환 큐, 몇 개의 원소를 뽑아내려고 한다.
// 첫 번째 원소를 뽑아낸다. 만약 1,2,3 으로 이뤄졌을 때 1을 뽑아내면 2,3이 된다.
// 왼쪽으로 한 칸 이동시킨다.
// 오른쪽으로 한 칸 이동시킨다.
// 지정된 원소를 "주어진 순서대로" 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

// 입력 
// 첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. 
// N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 
// 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 문제의 정답을 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    
    cin >> N >> M;
    deque<int> DQ;
    int ans=0;
    
    for(int i = 1; i <= N; i++){
        DQ.push_back(i);
    }
    
    
    while(M--){
        int wantValue;
        cin >> wantValue;
        
        // 이터레이터: 포인터와 비슷함.
        
        // index: t의 위치
        int index = find(DQ.begin(), DQ.end(), wantValue) - DQ.begin(); 
        while(DQ.front()!=wantValue){
            if(index < DQ.size() - index){
                // 오른쪽으로 이동
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }else{
                // 왼쪽으로 이동
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        }
        
        // 선택된 값 제거
        DQ.pop_front(); 
    }
    cout << ans << "\n";
   return 0;
}