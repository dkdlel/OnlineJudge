//
//  12100(2048(Easy)).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/02/10.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 21

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int arr[MAX][MAX];
int N, ans = 0;

void FindMax(){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            ans = ans < arr[i][j] ? arr[i][j] : ans;
        }
    }
}

void Copy(int from[][MAX], int to[][MAX]){
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            to[i][j] = from[i][j];
        }
    }
}

void Move(int dir){
    // 진행 방향으로 한번 밀고
    // 같은 숫자 계산하고
    // 한번더 밀고
    switch(dir){
        case 0: // 상
            // 위로 한번 밀고
            for(int i = 0 ; i < N - 1 ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = i + 1 ; k < N ; k++){ // 아래 숫자들 위로
                            if(arr[k][j]) { // 숫자 잇으면 자리 이동
                                arr[i][j] = arr[k][j];
                                arr[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            // 같은 숫자 계산
            for(int i = 0 ; i < N - 1 ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(arr[i][j] == arr[i+1][j]){
                        arr[i][j] += arr[i+1][j];
                        arr[i+1][j] = 0;
                    }
                }
            }
            // 한번 더 밀고
            for(int i = 0 ; i < N - 1 ; i++){
                for(int j = 0 ; j < N ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = i + 1 ; k < N ; k++){ // 아래 숫자들 위로
                            if(arr[k][j]) { // 숫자 잇으면 자리 이동
                                arr[i][j] = arr[k][j];
                                arr[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 1: // 하
            // 아래로 한번 밀고
            for(int i = N - 1 ; i > 0 ; i--){
                for(int j = 0 ; j < N ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = i - 1 ; k >=0 ; k--){ // 위 숫자들 아래로
                            if(arr[k][j]) { // 숫자 잇으면 자리 이동
                                arr[i][j] = arr[k][j];
                                arr[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            // 같은 숫자 계산
            for(int i = N - 1 ; i > 0 ; i--){
                for(int j = 0 ; j < N ; j++){
                    if(arr[i][j] == arr[i-1][j]){
                        arr[i][j] += arr[i-1][j];
                        arr[i-1][j] = 0;
                    }
                }
            }
            // 한번 더 밀고
            for(int i = N - 1 ; i > 0 ; i--){
                for(int j = 0 ; j < N ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = i - 1 ; k >= 0 ; k--){ // 위 숫자들 아래로
                            if(arr[k][j]) { // 숫자 잇으면 자리 이동
                                arr[i][j] = arr[k][j];
                                arr[k][j] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 2: // 좌
            // 왼쪽으로 한번 밀고
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N - 1 ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = j + 1 ; k < N ; k++){ // 오른쪽 숫자들 왼쪽으로
                            if(arr[i][k]){
                                arr[i][j] = arr[i][k];
                                arr[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            // 같은 숫자 계산
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N - 1 ; j++){
                    if(arr[i][j] == arr[i][j+1]){
                        arr[i][j] += arr[i][j+1];
                        arr[i][j+1] = 0;
                    }
                }
            }
            // 한번 더 밀고
            for(int i = 0 ; i < N ; i++){
                for(int j = 0 ; j < N - 1 ; j++){
                    if(!arr[i][j]){ // 현재 자리가 0
                        for(int k = j + 1 ; k < N ; k++){ // 오른쪽 숫자들 왼쪽으로
                            if(arr[i][k]){
                                arr[i][j] = arr[i][k];
                                arr[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 3: // 우
            // 오른쪽으로 한번 밀고
            for(int i = 0 ; i < N ; i++){
                for(int j = N - 1 ; j > 0 ; j--){
                    if(!arr[i][j]){
                        for(int k = j - 1 ; k >= 0 ; k--){
                            if(arr[i][k]){
                                arr[i][j] = arr[i][k];
                                arr[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            // 같은 숫자 계산
            for(int i = 0 ; i < N ; i++){
                for(int j = N - 1 ; j > 0 ; j--){
                    if(arr[i][j] == arr[i][j-1]){
                        arr[i][j] += arr[i][j-1];
                        arr[i][j-1] = 0;
                    }
                }
            }
            // 한번 더 밀고
            for(int i = 0 ; i < N ; i++){
                for(int j = N - 1 ; j > 0 ; j--){
                    if(!arr[i][j]){
                        for(int k = j - 1 ; k >= 0 ; k--){
                            if(arr[i][k]){
                                arr[i][j] = arr[i][k];
                                arr[i][k] = 0;
                                break;
                            }
                        }
                    }
                }
            }
            break;
    }
}

void DFS(int cnt){
    if(cnt == 5){
        FindMax();
        return;
    }

    int cache[MAX][MAX];
    Copy(arr, cache); // 원상복귀를 위한 복사

    for(int i = 0 ; i < 4 ; i++){ // 상 하 좌 우
        Move(i);
        DFS(cnt+1);
        Copy(cache, arr); // 원상 복귀
    }
}

int main(){

    fcin >> N;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            fcin >> arr[i][j];
        }
    }
    DFS(0);

    cout << ans << '\n';
    return 0;
}
