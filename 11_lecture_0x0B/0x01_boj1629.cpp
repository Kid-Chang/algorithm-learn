#include <bits/stdc++.h>

using namespace std;

// 곱셈

// 조건
// 

// 입력 
// 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.


// 출력
// 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

using ll = long long;

// a^b mod m
ll recursion(ll a, ll b, ll m){
    // 재귀가 끝날 때
    if(b==1) return a % m;
    
    
    ll value = recursion(a, b/2, m);
    value = value * value % m;
    
    // 홀수 제곱이면 if b=5, 재귀에서는 2를 기반으로 한 값이 나오므로, 1제곱에 관한 연산을 추가로 해준다.
    if(b%2==1) return value * a % m;
    return value;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    cin >> a >> b >> c;
    
    cout << recursion(a,b,c);
    

   
    return 0;
}