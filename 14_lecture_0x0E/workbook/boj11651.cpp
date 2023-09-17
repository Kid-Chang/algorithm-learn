#include <bits/stdc++.h>

using namespace std;

// 수 정렬하기 5

// 조건
// 좌표를 x좌표가 증가하는 순으로, 
// x좌표가 같으면 "y좌표가 증가하는 순서"로 정렬한 다음 출력하는 프로그램을 작성하시오.
// merge sort를 써야함. 왜? Stable Sort 가 필요하니까.

// 입력 
// 

// 출력
// 

int n;
int arr[200002][2];
int tmp[200002][2];


void merge(int st,int en){
    int mid = (st+en) / 2;
    
    int l_idx=st, r_idx=mid; // r_idx가 mid인 이유는, merge하는 값이 커질 수록,
    // st와 mid에 가장 작은 값이 들어가 있기때문에.
    for(int i= st; i < en;i++){
        if(r_idx == en) {
            tmp[i][0] = arr[l_idx][0];
            tmp[i][1] = arr[l_idx][1];
            l_idx++;
        }
        else if(l_idx == mid) {
            tmp[i][0] = arr[r_idx][0];
            tmp[i][1] = arr[r_idx][1];
            r_idx++;
        }
        else if(arr[l_idx][1] == arr[r_idx][1]) {
            if(arr[l_idx][0] > arr[r_idx][0]){
                tmp[i][0] = arr[r_idx][0];
                tmp[i][1] = arr[r_idx][1];
                r_idx++;
            }else{
                tmp[i][0] = arr[l_idx][0];
                tmp[i][1] = arr[l_idx][1];
                l_idx++;
            }
        }
        else if(arr[l_idx][1] < arr[r_idx][1]) {
            tmp[i][0] = arr[l_idx][0];
            tmp[i][1] = arr[l_idx][1];
            l_idx++;
        }
        else {
            tmp[i][0] = arr[r_idx][0];
            tmp[i][1] = arr[r_idx][1];
            r_idx++;
        }
    }
    
    for(int i=st;i<en;i++){
        arr[i][0] = tmp[i][0];
        arr[i][1] = tmp[i][1];
    }

}

void merge_sort(int st, int en){
    if (en - st == 1) return;
    int mid = (st+en) / 2;
    
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // merge sort 구현하기
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i][0] >> arr[i][1];
    
    merge_sort(0,n);

    for(int i=0;i<n;i++) cout << arr[i][0] << " " << arr[i][1] << "\n";

   
    return 0;
}