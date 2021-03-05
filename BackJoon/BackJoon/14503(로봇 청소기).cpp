//
//  14503(로봇 청소기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/05.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

// 상 우 하 좌
int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

// 하 좌 상 우
int bx[4] = {1, 0, -1, 0};
int by[4] = {0, -1, 0, 1};

int N, M, r, c, d, ans = 0;
int arr[51][51];

void dfs(){

    if(!arr[r][c]){ // 빈칸
        ans++;
        arr[r][c] = 2; // 벽과 구분하기 위하여
    }
    
    for(int i = d - 1 ; i > d - 5 ; i--){
        int nextDir = i;
        if(nextDir<0) nextDir += 4;
        int nextX = r + dx[nextDir];
        int nextY = c + dy[nextDir];
        
        if(0 <= nextX && nextX < N && 0 <= nextY && nextY < M && !arr[nextX][nextY]){
            r = nextX; c = nextY; d = nextDir;
            dfs();
            return;
        }
    }
    
    if(arr[r+bx[d]][c+by[d]] == 1) return;
    else{
        r += bx[d]; c += by[d];
        dfs();
    }
}

int main(){

    fcin >> N >> M >> r >> c >> d;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            fcin >> arr[i][j];
        }
    }
    dfs();
    cout << ans << '\n';
    return 0;
}
