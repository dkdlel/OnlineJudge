//
//  13460(구슬 탈출2).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/08.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#define RED 1
#define BLUE 0
#define INF 987654321

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

char arr[11][11];
int N, M;
int redX, redY, blueX, blueY;
int ans = INF;

//int dx[4] = {-1, 0, 1, 0};
//int dy[4] = {0, 1, 0, -1};

// 우 좌 하 상
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Init(){
    fcin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            fcin >> arr[i][j];
            if(arr[i][j] == 'R'){
                redX = i; redY = j;
                arr[i][j] = '.';
            }else if(arr[i][j] == 'B'){
                blueX = i; blueY = j;
                arr[i][j] = '.';
            }
        }
    }
}

int Reverse(int dir){
    if (dir == 0) return 1;
    else if (dir == 1) return 0;
    else if (dir == 2) return 3;
    else if (dir == 3) return 2;
    return -1;
}

//int nextRX, nextRY, nextBX, nextBY;

//void Move(int x, int y, int dir, bool &flag, int ball){
//    if(ball){ // red
//        nextRX = x + dx[dir]; nextRY = y + dy[dir];
//        while(1){ // move Red Ball
//            if(arr[nextRX][nextRY] == 'O'){ // Hole in
//                flag = true;
//                break;
//            }
//            else if(arr[nextRX][nextRY] == '#') break;
//            nextRX += dx[dir]; nextRY += dy[dir];
//        }
//        nextRX -= dx[dir]; nextRY -= dy[dir];
//    }else{ // blue
//        nextBX = x + dx[dir]; nextBY = y + dy[dir];
//        while(1){ // move Blue ball
//            if(arr[nextBX][nextBY] == 'O'){
//                flag = true;
//                break;
//            }
//            else if(arr[nextBX][nextBY] == '#') break;
//            nextBX += dx[dir]; nextBY += dy[dir];
//        }
//        nextBX -= dx[dir]; nextBY -= dy[dir];
//    }
//}

void Search(int rX, int rY, int bX, int bY, int cur, int dir){
    if(cur > 10) return;
    bool flag1 = false, flag2 = false;
    
//    Move(rX,rY,dir,flag1,RED);
//    Move(bX,bY,dir,flag2,BLUE);
    int nextRX = rX + dx[dir]; int nextRY = rY + dy[dir];
    while(1){ // move Red Ball
        if(arr[nextRX][nextRY] == 'O'){ // Hole in
            flag1 = true;
            break;
        }
        else if(arr[nextRX][nextRY] == '#') break;
        nextRX += dx[dir]; nextRY += dy[dir];
    }
    nextRX -= dx[dir]; nextRY -= dy[dir];
    
    int nextBX = bX + dx[dir]; int nextBY = bY + dy[dir];
    while(1){ // move Blue ball
        if(arr[nextBX][nextBY] == 'O'){
            flag2 = true;
            break;
        }
        else if(arr[nextBX][nextBY] == '#') break;
        nextBX += dx[dir]; nextBY += dy[dir];
    }
    nextBX -= dx[dir]; nextBY -= dy[dir];
    
    if(flag2) return; // 파란공이 들어간 경우
    else if(flag1){ // 빨간공이 들어간 경우
        ans = ans > cur ? cur : ans;
        return;
    }
    // 두 공의 위치가 같은지 확인
    if(nextRX == nextBX && nextRY == nextBY){ // 공이 겹친 경우 많이 움직인 공을 한단계 전으로 이동
        int moveR = abs(rX - nextRX) + abs(rY - nextRY);
        int moveB = abs(bX - nextBX) + abs(bY - nextBY);
        if (moveR > moveB){
            nextRX -= dx[dir];
            nextRY -= dy[dir];
        }else{
            nextBX -= dx[dir];
            nextBY -= dy[dir];
        }
    }
    
    for(int i = 0 ; i < 4 ; i++){
        if(i == dir || i == Reverse(dir)) continue;
        Search(nextRX, nextRY, nextBX, nextBY, cur+1, i);
    }
}

int main(){

    Init();
    for(int i = 0 ; i < 4 ; i++){
        int rX = redX, rY = redY, bX = blueX, bY = blueY;
        Search(rX, rY, bX, bY, 1, i);
    }
    ans == INF || ans > 10 ? cout << -1 << '\n' : cout << ans << '\n';
    return 0;
}
