#include <bits/stdc++.h>

using namespace std;

// N과 M (6)
// 틀렸던 이유: isused를 10으로 설정해서. isused에 실제 input값을 넣을려면 10000 이상이여야함.


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
    
    for(int i=start; i<n; i++){
        if(!isused[input_value[i]]){
            isused[input_value[i]] = true;
            arr[cur] = input_value[i];
            tracking(cur+1, i);
            isused[input_value[i]] = false;    
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