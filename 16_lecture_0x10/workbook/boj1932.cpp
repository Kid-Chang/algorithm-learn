 #include <bits/stdc++.h>

using namespace std;

// 정수 삼각형

// 조건
// 

// 입력 
// 

// 출력
// 

int n;
int triangle[505][505];
int sum_triangle[505][505];


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            cin >> triangle[i][j];
        }
    }

    sum_triangle[1][0] = triangle[1][0];
    
    // 계산하기
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            
            // 맨 앞
            if(j==0){
                sum_triangle[i][0] = sum_triangle[i-1][0]+triangle[i][j];
                continue;
            }
            // 맨 끝
            if(j==i-1){
                sum_triangle[i][j] = sum_triangle[i-1][j-1]+triangle[i][j];
                continue;
            }
            sum_triangle[i][j] = max(sum_triangle[i-1][j-1]+triangle[i][j], sum_triangle[i-1][j]+triangle[i][j]);
        }
    }
    
    cout << *max_element(sum_triangle[n], sum_triangle[n]+n);
    
    return 0;
}