#include <iostream>

using namespace std;

// 별 찍기 - 8

// 조건
//  

// 입력 
// 1~100까지의 정수

// 출력
// 모래시계 모양이 빈값, 그 외의 부분이 별이 되도록 출력한다.

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int line;
    cin >> line;
   
   for(int row = 0; row < line; row ++){
      
       // 별
       for(int star = 0; star < row+1; star++){
           cout << "*";
       }
       // 빈칸
       for(int space = 0; space < 2*line-2*(row+1) ; space++){
           cout << " ";
       }
       // 별
       for(int star = 0; star < row+1; star++){
           cout << "*";
       }
       cout << "\n";
   }
   for(int row = line; row > 0; row --){
      
       // 별
       for(int star = 0; star < row-1; star++){
           cout << "*";
       }
       // 빈칸
       for(int space = 0; space < 2*line-2*(row-1) ; space++){
           cout << " ";
       }
       // 별
       for(int star = 0; star < row-1; star++){
           cout << "*";
       }
       cout << "\n";
   }
   

    return 0;
}