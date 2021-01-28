//
//  7562(나이트의 이동).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/28.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 301
#define INF 987654321

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};
vector< vector<int> > vec;
vector< vector<int> > visited;

// 12시 기준 시계방향
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int len; // 체스 한변의 길이
position start, dest;

void Init(){
    fcin >> len;
    vec.clear(); visited.clear();
    vec.resize(len+1,vector<int>(len+1));
    visited.resize(len+1,vector<int>(len+1, INF));
    
    fcin >> start.x >> start.y >> dest.x >> dest.y;
}

int BFS(){
    queue<position> q;
    q.push({start.x, start.y});
    visited[start.x][start.y] = 0;
    
    while(!q.empty()){
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        if(curX == dest.x && curY == dest.y) return visited[curX][curY];
        for(int i = 0 ; i < 8 ; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            
            if(nextX < 0 || nextX >= len || nextY < 0 || nextY >= len) continue;
            if(visited[nextX][nextY] == INF){
                q.push({nextX, nextY});
                visited[nextX][nextY] = min(visited[curX][curY] + 1, visited[nextX][nextY]);
            }
        }
    }
    
    return 0;
}

int main(){
    
    int testcase; fcin >> testcase;
    
    while(testcase--){
        Init();
        cout << BFS() << '\n';
    }
    
    return 0;
}
