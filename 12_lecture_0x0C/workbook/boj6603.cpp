#include <bits/stdc++.h>

using namespace std;

// 로또

// 조건
// 

// 입력 
// 

// 출력
// 

int arr[15];
int n;
int input_value[15];
bool isused[100005];

void tracking(int cur, int start){
    if(cur == 6){
        for(int i=0; i<6;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    

    for(int i=start; i<n; i++){
        if(!isused[i]){ 
            isused[i] = true;
            arr[cur] = input_value[i];
            tracking(cur+1, i);
            isused[i] = false;
        }
        
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    do{
        for(int i=0; i<n; i++)
            cin >> input_value[i];
        sort(input_value, input_value+n);
        
        tracking(0, 0);
        
        cout << "\n";
        cin >> n;
    } while(n != 0);
   
    return 0;
}