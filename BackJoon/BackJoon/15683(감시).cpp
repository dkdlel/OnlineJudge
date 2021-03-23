//
//  15683(감시).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/23.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define WALL 6

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int num, x, y;
};

// 상우하좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M, ans = 987654321;
vector<vector<int>> vec, copyVec;
vector<position> camera;

void Init(){
    fcin >> N >> M;
    vec.assign(N,vector<int>(M,0));
    for(int i = 0 ; i < N ; i++) {
        for(int j = 0 ; j < M ; j++) {
            fcin >> vec[i][j];
            if(vec[i][j] != 0 && vec[i][j] != 6) camera.push_back({vec[i][j], i,j});
        }
    }
}

void Fill(int x, int y, int dir){
    while(1){ // 현재 진행방향으로 다 채움
        x += dx[dir]; y += dy[dir];
        if(x < 0 || x >= N || y < 0 || y >= M || vec[x][y] == WALL) // 범위초과 or 벽
            break;
        copyVec[x][y] = 1;
    }
}

int FindBlank(vector<vector<int>> cur){
    int result = 0;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(vec[i][j] >= 1 && vec[i][j] <= 5) continue; // 카메라가 아니거나
            else if(vec[i][j] != WALL && cur[i][j] == 0) result++; // 벽이 아닌데 현재 빈칸인 경우
        }
    }
    return ans < result ? ans : result;
}

void dfs(int idx, vector<vector<int>> prev){
    copyVec.resize(N, vector<int>(M,0));
    if(idx == camera.size()){
        ans = FindBlank(prev);
        return;
    }else{
        int curX = camera[idx].x; int curY = camera[idx].y;
        switch(camera[idx].num){
            case 1: // 상, 하, 좌, 우
                for(int dir = 0 ; dir < 4 ; dir++){
                    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) copyVec[i][j] = prev[i][j];
                    Fill(curX, curY, dir);
                    dfs(idx+1, copyVec);
                }
                break;
            case 2: // 상하, 좌우
                for(int dir = 0 ; dir < 2 ; dir++){
                    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) copyVec[i][j] = prev[i][j];
                    Fill(curX, curY, dir);
                    Fill(curX, curY, dir+2);
                    dfs(idx+1, copyVec);
                }
                break;
            case 3: // 상우, 우하, 하좌, 좌상
                for(int dir = 0 ; dir < 4 ; dir++){
                    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) copyVec[i][j] = prev[i][j];
                    Fill(curX, curY, dir);
                    Fill(curX, curY, (dir+1)%4);
                    dfs(idx+1, copyVec);
                }
                break;
            case 4: // 상우하, 우하좌, 하좌상, 좌상우
                for(int dir = 0 ; dir < 4 ; dir++){
                    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) copyVec[i][j] = prev[i][j];
                    Fill(curX, curY, dir);
                    Fill(curX, curY, (dir+1)%4);
                    Fill(curX, curY, (dir+2)%4);
                    dfs(idx+1, copyVec);
                }
                break;
            case 5: // 상하좌우
                for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) copyVec[i][j] = prev[i][j];
                for(int dir = 0 ; dir < 4 ; dir++) Fill(curX, curY, dir);
                dfs(idx+1, copyVec);
                break;
        }
    }
}

int main(){
    
    Init();
    dfs(0, vec);
    cout << ans << '\n';
    return 0;
}
