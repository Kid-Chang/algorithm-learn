#include <bits/stdc++.h>

using namespace std;

// 빈도 정렬

// 조건
// 만약, 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 한다. 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 한다.


// 입력 
// 

// 출력
// 
vector<pair<int,int>> v;
int n, c;

bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second > b.second;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> c;
    
    for(int i=0;i<n;i++){
        int val;
        cin >> val;
        

        // for문 돌면서 val의 위치를 찾고 거기의 cnt에 ++
        bool exist= false;
        for(auto &existedValue: v){
            if(existedValue.first == val){
                existedValue.second++;
                exist =true;
            }
        }
        if(!exist){
            v.push_back({val, 1});
        }
    }
    
    stable_sort(v.begin(),v.end(), compare);
   
    for(auto &existedValue: v){
        for(int i=0;i<existedValue.second; i++){
            cout << existedValue.first << " ";
        }
    }


   
    return 0;
}