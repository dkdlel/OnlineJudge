//
//  3190(뱀).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/15.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <deque>
#include <queue>
using namespace std;
#define MAX 101
#define APPLE 1

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct position{
    int x, y;
};

int arr[MAX][MAX], visited[MAX][MAX], dir[MAX];
int N, K, L; // N : 보드의 크기, K : 사과의 개수, L : 뱀의 방향전환 개수
// 우 하 좌 상
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0, -1, 0};
queue<position> q;
deque<position> dq;

void Input(){
    fcin >> N >> K;
    for(int i = 0 ; i < K ; i++){
        int x, y; fcin >> x >> y;
        arr[x][y] = APPLE;
    }
    fcin >> L;
    for(int i = 0 ; i < L ; i++){
        int x; char ch; fcin >> x >> ch;
        ch == 'D' ? q.push({x, 1}) : q.push({x, -1});
    }
}

void Sol(){
    dq.push_back({1, 1}); // 시작 (1,1)
    visited[1][1] = 1;
    int dir = 0, time = 0;
    int rtime = q.front().x, rdir = q.front().y; // 회전시간, 회전방향
    q.pop();

    while(1){
        time++;
        int nextX = dq.front().x + dx[dir];
        int nextY = dq.front().y + dy[dir];

        if((nextX < 1 || nextX > N || nextY < 1 || nextY > N) || visited[nextX][nextY]) break; // 범위 초과 및 자기자신 밟기

        if(arr[nextX][nextY]){ // 사과 있음
            arr[nextX][nextY] = 0;
            dq.push_front({nextX, nextY});
            visited[nextX][nextY] = 1;
        } else{
            int curX = dq.back().x, curY = dq.back().y;
            dq.pop_back();
            visited[curX][curY] = 0;
            dq.push_front({nextX, nextY});
            visited[nextX][nextY] = 1;
        }

        if(time == rtime){ // 방향 전환
//            dir += rdir;
//            dir = dir < 0 ? 3 : (dir % 4);
            dir = (dir+rdir+4) % 4;
            rtime = q.front().x; rdir = q.front().y;
            q.pop();
        }
    }

    cout << time << '\n';
}

int main(){

    Input();
    Sol();

    return 0;
}
