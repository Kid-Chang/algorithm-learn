#include <bits/stdc++.h>

using namespace std;

// 수 정렬하기 5

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int arr[1000001];
int tmp[1000001];


void merge(int st,int en){
    int mid = (st+en) / 2;
    
    int l_idx=st, r_idx=mid; // r_idx가 mid인 이유는, merge하는 값이 커질 수록,
    // st와 mid에 가장 작은 값이 들어가 있기때문에.
    for(int i= st; i < en;i++){
        if(r_idx == en) tmp[i] = arr[l_idx++];
        else if(l_idx == mid) tmp[i] = arr[r_idx++];
        else if(arr[l_idx] < arr[r_idx]) tmp[i] = arr[l_idx++];
        else tmp[i] = arr[r_idx++];
    }
    
    for(int i=st;i<en;i++){
        arr[i] = tmp[i];
    }

}

void merge_sort(int st, int en){
    if (en - st == 1) return; // st~(en-1)까지 정렬하는 것이기에, 
    // 이게 리턴되면, merge(0,2) 와 같이 숫자 2 차이가 나는 merge가 실행되는데, 
    // 이러면 0번~1번 인덱스까지의 값을 비교해서 정렬하니까.
    int mid = (st+en) / 2;
    
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // merge sort 구현하기
    
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    merge_sort(0,n);
    
    for(int i=0;i<n;i++) cout << arr[i] << "\n";

   
    return 0;
}