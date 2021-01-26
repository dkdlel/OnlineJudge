//
//  1012(유기농배추).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/25.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector< vector<int> >vec;
vector< vector<int> >visited;

void Init(int N, int M, int K){
    vec.clear(); visited.clear();
    vec.resize(N+2, vector<int>(M+2));
    visited.resize(N+2, vector<int>(M+2));
    for(int i = 0 ; i < K ; i++){
        int x, y; fcin >> y >> x;
        vec[x+1][y+1] = 1;
    }
}

void BFS(int rootX, int rootY){
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
            if(vec[nextX][nextY] && !visited[nextX][nextY]){
                q.push({nextX, nextY});
                visited[nextX][nextY] = 1;
            }
        }
    }
}

int main(){
    
    int testcase; fcin >> testcase;
    
    while(testcase--){
        int ans = 0;
        int N,M,K; fcin >> M >> N >> K;
        Init(N,M,K);
        for(int i = 1 ; i <= N ; i++){
            for(int j = 1 ; j <= M ; j++){
                if(vec[i][j] && !visited[i][j]) { // 방문할 위치
                    BFS(i,j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
