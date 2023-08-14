#include <bits/stdc++.h>

using namespace std;

// 숨바꼭질 

// 조건
// 

// 입력 
// 

// 출력
// 


int dist[200001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int subin_position, brother_position;
    cin >> subin_position >> brother_position;
    fill(dist,dist+200000,-1);
    dist[subin_position] = 0;
    queue<int> Q;
    Q.push(subin_position);
    // 만약 동생의 위치가 잡히면 거기서 끝.
    
    
    while(dist[brother_position] == -1){
        int cur = Q.front(); Q.pop();
        
        //  range-based for 이라는 것도 있다.
        for(int nx : {cur-1, cur+1, 2*cur}){
            
            if(nx < 0 || nx > 200000) continue;
            if(dist[nx] != -1){
                if(dist[cur] +1 <  dist[nx]){
                    dist[nx]=dist[cur]+1;
                    Q.push(nx);
                }
            } else{
                dist[nx] = dist[cur] +1;
                Q.push(nx);
            }
        }
          
       
    
    }
    

    
    cout << dist[brother_position];
    
   
    return 0;
}