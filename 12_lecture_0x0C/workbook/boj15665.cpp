#include <bits/stdc++.h>

using namespace std;

// N과 M (11)

// 조건
// 

// 입력 
// 

// 출력
// 

int arr[10];
int n, m;
int input_value[10];
bool isused[100005];

void tracking(int cur, int start){
    if(cur == m){
        for(int i=0; i<m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    int tmp = 0; // 중복 확인용

    for(int i=start; i<n; i++){
        // for문 돌면서, 즉 
        if(tmp != input_value[i]){ 
            // 여기서 i는 i번째 값(arr[i]를 사용했나? 임)
            // 원랜 isused[input_value[i]]를 이용했으나, 
            // 사실 i번째 값 v가 아닌 i번째 라는 사실로도 사용유뮤가 판단이 가능하므로, isused[i]를 이용. 
 
            arr[cur] = input_value[i];
            tmp = arr[cur];
            // tmp는 만약 3번째 자리 값을 정한다 했을 때, for문이 돌아가면서 확인하기때문에 전역으로 선언하지 않음.
            tracking(cur+1, 0);

        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n; i++)
        cin >> input_value[i];
    
    sort(input_value, input_value+n);
    
    tracking(0, 0);

   
    return 0;
}