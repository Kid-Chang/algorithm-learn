#include <iostream>

using namespace std;

// 별 찍기 - 7 

// 조건
//  

// 입력 
// 1~100까지의 정수

// 출력
// 마름모(소위) 모양이 되도록 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int line;
    cin >> line;
   
   for(int row = 0; row < line-1; row ++){
       // 빈칸
       for(int space = 0; space < line-row-1 ; space++){
           cout << " ";
       }
       // 별
       for(int star = 0; star < 2*row+1; star++){
           cout << "*";
       }

       cout << "\n";
   }
   
   for(int row = line-1; row >= 0; row--){
       // 빈칸
       for(int space = 0; space < line-row-1 ; space++){
           cout << " ";
       }
       // 별
       for(int star = 0; star < 2*row+1; star++){
           cout << "*";
       }

       cout << "\n";
   }
       

    return 0;
}