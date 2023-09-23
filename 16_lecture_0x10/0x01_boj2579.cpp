#include <bits/stdc++.h>

using namespace std;

// 계단 오르기

// 조건
// 

// 입력 
// 둘째 줄부터 한 줄에 하나씩 제일 아래에 놓인 계단부터 순서대로 각 계단에 쓰여 있는 점수가 주어진다

// 출력
// 첫째 줄에 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값을 출력한다.


int stair_num;
int arr[301][2]; // 현재까지 j개의 계단을 연속해서 밟고 i번째 계단에 올라섰을 때 점수 합의 최댓값, 단, i번째 계단은 반드시 밟아야함.
// j가 1일때는 i번째 계단이 연속해서 밟는 계단의 첫번째 계단이기에, i-1번째 계단은 밟지 않고 i-2번째 계단은 밟았다.
int score[301];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> stair_num;
    
    
    for(int i=1;i<=stair_num;i++){
        cin >> score[i];
    }
    
    arr[1][1]= score[1];
    
    
    for(int i=2;i<=stair_num;i++){
        arr[i][1] = max(arr[i-2][1], arr[i-2][2]) + score[i];
        arr[i][2] = arr[i-1][1] + score[i];
    }
    
    cout << max(arr[stair_num][1], arr[stair_num][2]);
    
    return 0;
}