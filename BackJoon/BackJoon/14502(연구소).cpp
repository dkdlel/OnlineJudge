//
//  14502(연구소).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/03.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};

int dx[4] = { -1, 1, 0, 0 }; // 상 하 좌 우
int dy[4] = { 0 , 0 , -1, 1};
int N,M, ans = 0;
int arr[9][9], visited[9][9] = {0};

void SpreadVirus(){
    queue<position> q;
    int copy[9][9];
    // find virus
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            copy[i][j] = visited[i][j];
            if(arr[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    
    // spread virus
    while(!q.empty()){
        int curX = q.front().x; int curY = q.front().y; q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + dx[i]; int nextY = curY + dy[i];
            // 범위 내에 있고 안전영역인 경우
            if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !copy[nextX][nextY]){
                copy[nextX][nextY] = 1;
                q.push({nextX, nextY});
            }
        }
    }
    
    // find safeZone
    int cnt = 0; // safeZone
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(!copy[i][j]) cnt++;
        }
    }
    ans = ans < cnt ? cnt : ans;
}

void MakeWall(int wallCnt){
    
    if(wallCnt == 3){
        SpreadVirus();
        return;
    }
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                MakeWall(wallCnt+1);
                visited[i][j] = 0;
            }
        }
    }
}

int main(){
    // input
    fcin >> N >> M;
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            int num; fcin >> num;
            arr[i][j] = num;
            if(num) visited[i][j] = 1;
        }
    }
    
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(!visited[i][j]){
                visited[i][j] = 1;
                MakeWall(1);
                visited[i][j] = 0;
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}
