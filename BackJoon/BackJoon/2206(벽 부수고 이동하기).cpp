//
//  2206(벽 부수고 이동하기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/28.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x,y, block;
};
int arr[MAX][MAX];
int visited[MAX][MAX][2];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;

void Init(){
    
    fcin >> N >> M;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            char ch; fcin >> ch;
            arr[i][j] = ch - '0';
        }
    }
}

int BFS(){
    queue<position> q;
    q.push({0,0,1}); // 1,1 에서 시작 / N, M 도착
    visited[0][0][1] = 1;
    
    while(!q.empty()){
        int curX = q.front().x;
        int curY = q.front().y;
        int block = q.front().block;
        q.pop();
        if(curX == N-1 && curY == M-1) return visited[curX][curY][block];
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX<0 || nextX>=N || nextY<0 || nextY>=M) continue;
            
            if(!arr[nextX][nextY] && !visited[nextX][nextY][block]){ // 벽이 뚫려있고 방문하지 않은 곳
                q.push({nextX, nextY, block});
                visited[nextX][nextY][block] = visited[curX][curY][block] + 1;
            }
            if(arr[nextX][nextY] && block){ // 벽이 있고, 벽을 뚫지 않았으면
                q.push({nextX, nextY, block - 1});
                visited[nextX][nextY][block-1] = visited[curX][curY][block] + 1;
            }
        }
    }
    return -1; // 갈수 없음
}

int main() {
    
    Init();
    cout << BFS() << '\n';
    return 0;
}
