//
//  7576(토마토).cpp
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
#define MAX 1002

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int arr[MAX][MAX];
int visited[MAX][MAX];
int N, M;
queue<position> q;

int BFS(){
    int result = 0;
    while(!q.empty()){
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextY<0 || nextY>=M || nextX<0 || nextX>=N) continue;
            if(arr[nextX][nextY] != -1 && !visited[nextX][nextY]){
                q.push({nextX, nextY});
                visited[nextX][nextY] = visited[curX][curY] + 1;
                if(result < visited[nextX][nextY]) result = visited[nextX][nextY];
            }
        }
    }
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < M ; j++) if(visited[i][j] == 0) return -1; // 예외
    
    return result ? result - 1 : result;
}

int main(){

    fcin >> M >> N;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            int n; fcin >> n;
            arr[i][j] = n;
            if(n == -1) visited[i][j] = -1;
            if(n == 1) {q.push({i,j}); visited[i][j] = 1;}
        }
    }

    cout << BFS() << '\n';

    return 0;
}
