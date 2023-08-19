#include <bits/stdc++.h>

using namespace std;

// 숨바꼭질 3
// 도저히 bfs로는 못풀겠어서, 덱을 이용함.

// 조건

// 입력 

// 출력

#define X first
#define Y second

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int dist[200001];
deque<int> DQ;
int subin_position, brother_position;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> subin_position >> brother_position;
    fill(dist,dist+200000,-1);
    dist[subin_position] = 0;
    DQ.push_front(subin_position);
    // 만약 동생의 위치가 잡히면 거기서 끝.
    
    while(!DQ.empty()){
        int cur = DQ.front(); DQ.pop_front();
        
        if( 2*cur < 200000 && dist[2*cur] == -1){
            // 순간이동에는 0초가 걸리므로, +1 하는게 아닌 그대로의 값을 준다.
            dist[2*cur] = dist[cur]; 
            DQ.push_front(2*cur);
        }
        
        for(int nxt : {cur-1, cur+1}){
            if(nxt < 0 or nxt >= 200000 or dist[nxt] != -1) continue;
            dist[nxt] = dist[cur]+1;
            DQ.push_back(nxt);      
        }
    }
    
    cout << dist[brother_position];
    
   
    return 0;
}