#include <bits/stdc++.h>

using namespace std;

// N과 M (5)

// 조건
// 

// 입력 
// n m

// 출력
// 

int n, m; 
int arr[10000], input_value[10000];
bool isused[10000];

void tracking(int cur){
    if(cur == m){
        for(int j=0;j<m;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i=0; i<n; i++){
        if(!isused[input_value[i]]){
            isused[input_value[i]] = true;
            arr[cur] = input_value[i];
            tracking(cur+1);
            isused[input_value[i]] = false;
            
        }    
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i=0; i<n;i++)
        cin >> input_value[i];
    sort(input_value, input_value+n);
    
    tracking(0);

    
    return 0;
}