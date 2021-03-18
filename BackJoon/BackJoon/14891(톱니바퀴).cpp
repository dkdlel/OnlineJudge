//
//  14891(톱니바퀴).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/18.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
#define N 0
#define S 1
#define CW 1
#define CCW -1

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

deque<int> dq[4];
int K, num, dir, ans = 0, score = 1; // num : 회전시킨 톱니바퀴의 번호, dir : 방향

void Rotate(int num, int dir){
    if(dir == CW){
        dq[num].push_front(dq[num].back()); // 맨뒤꺼를 맨앞으로
        dq[num].pop_back();
    }else{
        dq[num].push_back(dq[num].front()); // 맨앞꺼를 맨뒤로
        dq[num].pop_front();
    }
}

void Left(int num, int dir, int flag){
    if(num < 0 || num >= 4 || flag) return; // 범위를 초과하거나 방향전환이 필요없는경우
    
    if(dq[num][2] != dq[num+1][6]){ // 현재 톱니바뀌랑 앞(+1)의 톱니바뀌 비교
        Left(num-1, -1*dir, 0);
        Rotate(num, dir);
    }else flag = 1; // 같은경우 뒤로는 돌릴 필요가 없음
}

void Right(int num, int dir, int flag){
    if(num < 0 || num >= 4 || flag) return;
    
    if(dq[num][6] != dq[num-1][2]){ // 현재 톱니바뀌랑 뒤(-1)의 톱니바뀌 비교
        Right(num+1, -1*dir, 0);
        Rotate(num,dir);
    }else flag = 1;
}

int main(){
    
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 8 ; j++) {
            char ch; fcin >> ch;
            dq[i].push_back(ch-'0');
        }
    }
    fcin >> K;
    for(int i = 0 ; i < K ; i++){
        fcin >> num >> dir;
        // 문제는 톱니바퀴가 1부터 시작, 코드는 0부터 시작
        Left(num-2, -1*dir, 0);
        Right(num, -1*dir, 0);
        Rotate(num-1, dir);
    }
    for(int i = 0 ; i < 4 ; i++){
        if(dq[i][0] == S) ans += score;
        score *= 2;
    }
    cout << ans << '\n';
    return 0;
}
