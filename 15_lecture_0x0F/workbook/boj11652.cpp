#include <bits/stdc++.h>

using namespace std;

// 문제제목

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
long long arr[100001];
int max_count=0;
long long max_value;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int count =0;
    for(int i=0;i<n;i++){

        if(i==0 || arr[i]==arr[i-1]){
            count++;
        }
        else{
            // 카운트 저장
            if(max_count < count){
                max_count = count;
                max_value = arr[i-1];
            }
            count=1;
        }
        
    }
    if(count > max_count) max_value = arr[n-1];
    cout << max_value;
   
    return 0;
}