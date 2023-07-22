#include <iostream>

using namespace std;

// 조건
// 배 0 등 1
// 도(배1,등3) 개(배2,등2) 걸(배3,등1) 윷(배4) 모(등4)

// 입력 
// 4개 3세트

// 출력
// 도는 A, 개는 B, 걸은 C, 윷은 D, 모는 E로 출력

int main()
{
    
    for(int n =0; n < 3 ; n++){
        int a,b,c,d,front=0, back=0;
        
        cin >> a >> b >> c >> d;
        if(a==0){
            front++;
        }else{
            back++;
        }
         if(b==0){
            front++;
        }else{
            back++;
        }
         if(c==0){
            front++;
        }else{
            back++;
        }
         if(d==0){
            front++;
        }else{
            back++;
        }
        
        if(front==1 && back ==3){
            cout << "A" << '\n';
        }
        else if(front==2 && back ==2){
            cout << "B" << '\n';
        }
        else if(front==3 && back ==1){
            cout << "C" << '\n';
        }
        else if(front==4 && back ==0){
            cout << "D" << '\n';
        }    
        else if(front==0 && back ==4){
            cout << "E" << '\n';
        }    
    }

    return 0;
}