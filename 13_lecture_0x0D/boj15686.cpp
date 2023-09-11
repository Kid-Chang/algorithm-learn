#include <bits/stdc++.h>

using namespace std;

// 치킨 배달

// 조건
// 

// 입력 
// 

// 출력
// 

int N, M, this_min_total=0, total_min=99999;
int board[51][51];
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back({i,j});
            if(board[i][j] == 2) chicken.push_back({i,j});
        }
    }

    vector<int> v(chicken.size(), 0);
    fill(v.begin(), v.begin()+M, 1);

    do{
        
        // 살릴 치킨집 M개를 선택한 상황 (1이 살아남는 치킨집)
        this_min_total=0;
        // 각 집별로 가까운 거리 완전 탐색?
        for(int i=0;i<house.size();i++){
            int min_distance = 99999;
            // i번 집과 살아남은 각 좌표 끼리 비교
            for(int chick=0;chick<chicken.size();chick++){
                if(v[chick] == 1) {
                    int this_min = abs(chicken[chick].first - house[i].first) + abs(chicken[chick].second - house[i].second);
                    min_distance = min(min_distance, this_min);
                }
            }
            this_min_total+=min_distance;
        }

        total_min = min(total_min, this_min_total);
        
    }while(prev_permutation(v.begin(), v.end()));
    
    cout<< total_min;

    
    
    return 0;
}