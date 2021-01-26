//
//  2178(미로 탐색).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/26.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;
#define MAX 102

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[MAX][MAX];
int visited[MAX][MAX];
int N, M;

void Init(){
    
    fcin >> N >> M;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            char ch; fcin >> ch;
            arr[i][j] = ch - '0';
        }
    }
}

int BFS(int rootX, int rootY){
    queue<position> q;
    visited[rootX][rootY] = 1;
    q.push({rootX, rootY});
    
    while(!q.empty()){
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(arr[nextX][nextY] && !visited[nextX][nextY]){
                q.push({nextX, nextY});
                visited[nextX][nextY] = visited[curX][curY] + 1;
            }
        }
    }
    
    return visited[N][M];
}

int main(){
    
    Init();
    cout << BFS(1,1) << '\n';
    return 0;
}
