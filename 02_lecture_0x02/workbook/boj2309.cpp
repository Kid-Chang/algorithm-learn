#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 일곱 난쟁이

// 조건
// 일곱 난쟁이의 키의 합이 100이 됨
// 일곱이 아닌 아홉 난쟁이가 있음.
// 

// 입력 
// 아홉 난쟁이의 키가 입력된다.

// 출력
// 합이 100이 되는 일곱 난쟁이의 키를 행바꿈으로 나열한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
   int kid[9];
   
   for(int i = 0; i<9;i++){
       cin >> kid[i];
   }
   
   // 7명만 합하는 조합 만들어보기.
   // 어떻게? 1~9까지, 1~9까지 이중 for문, 같은숫자가 나오는경우 제외하고
   // 그 두 숫자를 제외한 값들을 더하도록 for문.
   int n, m, sum;
   int exceptA, exceptB;
   for (n=0; n < 9; n++){
       for(m=n+1; m < 9 ; m++){
           int sum =0, count =0;
            //   cout << n  << ", "<< m << "\n";
            // 이렇게하면 제외할 두개의 숫자가 나옴.
            // 이 숫자들을 제외하고 모두 더하는 for문 구성

            for (int i=0; i<9; i++){
                // n, m 제외 다합하기
                if(i!=n && i!=m){
                    sum += kid[i];
                    count ++;
                    // cout << i << "번째 값인" <<kid[i]<< "을 넣어서 합: " <<sum <<" count: " <<count << "\n";
                }
                
                if(sum == 100 && count == 7){
                    exceptA = n;
                    exceptB = m;
                    break;
                }
                
            }
            if(sum == 100){
                break;
            }
           
       }
       if(sum == 100){
            break;
        }
   }
  int realKid[7];
  // exceptA, exceptB 빼고 새로운 배열 만들기
  int j=0;
   for (int i = 0; i < 9; i++){
       if(i!=exceptA && i!=exceptB){
           realKid[j++] = kid[i];
       }
   }
   
   // 만든 배열을 오름차순 정렬하기
   sort(realKid,realKid+7);
   
   for(int i = 0; i < 7; i++) cout << realKid[i] << "\n";
   
   return 0;
}