#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 방 번호

// 조건
// 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
// 다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
// (6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

// 입력 
// 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수

// 출력
// 첫째 줄에 필요한 세트의 개수를 출력

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string roomNumbers;
    int numberSet[10]={};
    
    cin >> roomNumbers;
    
    // 1~9까지 의 배열을 한개 만들고, 숫자가 나올때마다, +1씩 늘려준다.
    // 단, 6이나 9가 나왔을 때에는 두 값을 모두 확인하고, 값이 작은 곳을 늘려준다.
    // 끝으로, 배열을 탐색해 가장 큰 값을 찾아 이를 출력한다..

    for(char roomNumber: roomNumbers){
        // - '0' 해줘야함.

        if(roomNumber-'0' == 9 || roomNumber-'0' == 6){
            // 6이나 9인 경우
            if(numberSet[6] > numberSet[9]){
                numberSet[9]++;
            }else{
                // 같은 경우 굳이 따로 분기처리 필요없음.
                numberSet[6]++;
            }
                
        }else{
            // 그외의 경우
            numberSet[roomNumber-'0']++;
        }
    }
    
    int max=0;
    for(int i=0; i<10; i++){
        if(numberSet[i] > max){
            max = numberSet[i];
        }
    }
    
    cout << max;

   
   return 0;
}