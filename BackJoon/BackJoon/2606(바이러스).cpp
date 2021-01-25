//
//  2606(바이러스).cpp
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

vector < vector < int > > vec;
vector <int> visited;
queue <int> q;
int cnt = 0;

void Init(){
    
    vec.clear(); visited.clear();
    int n,m; fcin >> n >> m;
    vec.resize(n + 1); visited.resize(n + 1);
    for(int i = 0 ; i < m ; i++){
        int v1, v2; fcin >> v1 >> v2;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }
}

int BFS(int root) {
    visited[root] = 1;
    q.push(root);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cnt++;
        for(int i = 0 ; i < vec[cur].size() ; i++){
            int next = vec[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    
    return cnt - 1;
}

int main(){
    
    Init();
    cout << BFS(1) << '\n';
    return 0;
}
