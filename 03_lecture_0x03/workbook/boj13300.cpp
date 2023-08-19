#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// 방 배정

// 조건
// 남학생은 남학생끼리, 여학생은 여학생끼리 배정 && 한 방에는 같은 학년의 학생들을 배정
// 최대 인원 수 K가 주어졌을 때, 조건에 맞게 모든 학생을 배정하기 위해 필요한 방의 최소 개수를 구하는 프로그램


// 입력 
// 첫 번째 줄에는 수학여행에 참가하는 학생 수를 나타내는 정수 N과
// 한 방에 배정할 수 있는 최대 인원 수 K
// N 개의 각 줄에는 학생의 성별 S와 학년 YY(1 ≤ Y ≤ 6)
// S는 0, 1중 하나로서 여학생인 경우에 0, 남학생인 경우에 1로 나타낸다. 


// 출력
// 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    
    int totalStudent, maxPerRoom, totalRoom=0;
    
    cin >> totalStudent >> maxPerRoom;
    
    // 성별과 학년에 따른 배열 (0 제외)
    int gradeForGirl[7]={}, gradeForBoy[7]={};
    
    //int studentSex[totalStudent]={}, studentGrade[totalStudent]={};
    
    for(int i=0;i<totalStudent;i++){
        int studentSex, studentGrade;
        cin >> studentSex >> studentGrade;
        
        if(studentSex==0){
            gradeForGirl[studentGrade]++;
        }else{
            gradeForBoy[studentGrade]++;
        }
    //    cin >> studentSex[i] >> studentGrade[i];
    }
    
    for(int students: gradeForGirl){
        // 몫 구하기
        totalRoom += students / maxPerRoom;
        // 나머지 구하기
        if(students % maxPerRoom !=0 )
            totalRoom++;
    }
    
        for(int students: gradeForBoy){
        // 몫 구하기
        totalRoom += students / maxPerRoom;
        // 나머지 구하기
        if(students % maxPerRoom !=0 )
            totalRoom++;
    }
    
    cout << totalRoom;

   
   return 0;
}
