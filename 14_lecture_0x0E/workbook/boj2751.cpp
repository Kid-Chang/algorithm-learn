#include <bits/stdc++.h>

using namespace std;

// 수 정렬하기 2

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int arr[1000001];
int tmp[1000001]; // merge 함수에서 리스트 2개를 합친 결과를 임시로 저장하고 있을 변수

void merge(int st, int en){
  int mid = (st+en)/2;
  
  int l_idx=st, r_idx=mid;
  
  // tmp 배열에 순차적으로 저장
  for(int i= st; i < en;i++){
      if(r_idx == en) tmp[i] = arr[l_idx++];
      else if(l_idx == mid) tmp[i] = arr[r_idx++];
      else if(arr[l_idx] < arr[r_idx]) tmp[i] = arr[l_idx++];
      else tmp[i] = arr[r_idx++];
  }
  
  // tmp 배열에서 arr 배열로 값 이동
  for(int i= st; i < en;i++)
      arr[i] = tmp[i];
  
  
}

// arr[st:en]을 정렬하고 싶다.
void merge_sort(int st, int en){
  if(en - st == 1) return; // 길이 1인 경우
  int mid = (st+en)/2;
  merge_sort(st, mid); // arr[st:mid]을 정렬한다.
  merge_sort(mid, en); // arr[mid:en]을 정렬한다.
  merge(st, en); // arr[st:mid]와 arr[mid:en]을 합친다.
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
    merge_sort(0,n);
    
    for(int i=0;i<n;i++){
        cout << arr[i] << "\n";
    }
    
    return 0;
}