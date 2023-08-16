#include <bits/stdc++.h>

using namespace std;

// 홀수

// 조건


// 입력


// 출력



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    bool exist_odd_number =false;
    int input_number, odd_number_sum=0, odd_number_min=101;
    int count = 7;
    while(count--){
        cin >> input_number;
        if(input_number%2==1){
            exist_odd_number=true;
            odd_number_sum+=input_number;
            odd_number_min=min(input_number,odd_number_min);
        }
    }
    if(exist_odd_number) cout << odd_number_sum << "\n" << odd_number_min;
    else cout << -1;

    return 0;
}