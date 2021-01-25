//
//  2667(단지번호붙이기).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/25.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

struct info{
    int type, visited;
};

struct position{
    int x, y;
};
// 상 우 하 좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

info arr[28][28]; // 26 + 상하좌우 한칸 여유
vector <int> ans;
queue<position> q;

void Init(int t){
    ans.clear();
    for(int i = 1 ; i <= t ; i++){
        for(int j = 1 ; j <= t ; j++){
            char n; fcin >> n;
            arr[i][j].type = n - '0';
        }
    }
}

int BFS(int rootX, int rootY){
    int cnt = 1;
    arr[rootX][rootY].visited = 1;
    q.push({rootX, rootY});
    
    while(!q.empty()){
        int curX = q.front().x;
        int curY = q.front().y;
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(arr[nextX][nextY].type && !arr[nextX][nextY].visited){
                q.push({nextX, nextY});
                arr[nextX][nextY].visited = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    
    int t; fcin >> t;
    Init(t);
    for(int i = 1 ; i <= t ; i++){
        for(int j = 1 ; j <= t; j++){
            if(arr[i][j].type && !arr[i][j].visited){
                ans.push_back(BFS(i,j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0 ; i < ans.size() ; i++){
        cout << ans[i] << '\n';
    }
    
    return 0;
}
