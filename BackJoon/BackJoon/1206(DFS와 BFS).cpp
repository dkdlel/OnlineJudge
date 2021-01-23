//
//  1206(DFS와 BFS).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/22.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

vector< vector<int> > vec;
queue<int> q;
vector<int> visited;

void Init(int N, int M){
    vec.clear(); vec.resize(N + 1);
    for(int i = 0 ; i < M ; i++){
        int v1, v2; fcin >> v1 >> v2;
        vec[v1].push_back(v2);
        vec[v2].push_back(v1);
    }
    for(int i = 0 ; i < N ; i++) sort(vec[i].begin(), vec[i].end());
}

void DFS(int root){
    visited[root] = 1;
    cout << root << ' ';
    
    for(int i = 0 ; i < vec[root].size() ; i++){
        int next = vec[root][i];
        if(!visited[next]){
            DFS(next);
        }
    }
}

void BFS(int root){
    visited[root] = 1;
    q.push(root);
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        cout << cur << ' ';
        for(int i = 0 ; i < vec[cur].size() ; i++){
            int next = vec[cur][i];
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

int main(){
    
    int N, M, V; fcin >> N >> M >> V;
    Init(N, M);
    visited.clear(); visited.resize(N + 1);
    DFS(V); cout << '\n';
    visited.clear(); visited.resize(N + 1);
    BFS(V); cout << '\n';
    return 0;
}
