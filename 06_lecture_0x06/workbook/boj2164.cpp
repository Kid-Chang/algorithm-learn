#include <bits/stdc++.h>

using namespace std;

// 카드2

// 조건
// 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 
// 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
// 동작순서는 아래와 같다.
// 우선, 제일 위에 있는 카드를 바닥에 버린다. 
// 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.


// 입력 
// 첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
// 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다.

// 출력
// 출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count;
    cin >> count;
    queue<int> Q;
    
    for(int i=1;i<=count;i++){
        Q.push(i);
    }
    
    while(Q.size()!=1){
        Q.pop();
        Q.push(Q.front());
        Q.pop();
    }
    
    cout << Q.front();
   return 0;
}