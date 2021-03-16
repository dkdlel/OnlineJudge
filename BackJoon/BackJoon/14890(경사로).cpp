//
//  14890(경사로).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/03/16.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream fcin("/Users/jejn/Desktop/OnlineJudge/input.txt");

int N, L, ans = 0;
int arr[101][101];

void Init(){
    fcin >> N >> L;
    for(int i = 0 ; i < N ; i++) for(int j = 0 ; j < N ; j++) fcin >> arr[i][j];
}

void Row(){
    for(int i = 0 ; i < N ; i++){
        int slope[101] = {0, }; // 경사로 중복을 방지하기 위한 배열
        int flag = 0; // row가 조건에 만족하는지
        for(int j = 1 ; j < N ; j++){
            if(arr[i][j] == arr[i][j-1]) continue; // 현재의 값과 직전의 값이 같은 경우
            else if(abs(arr[i][j] - arr[i][j-1]) > 1) {flag = 1; break;} // 둘의 차이가 1 이상
            
            if(arr[i][j] > arr[i][j-1]){ // 오르막
                int check = 0; // 세부 조건들이 성립하는지
                int cur = arr[i][j] - 1; // 현재보다 작은값이 유지되는지
                for(int k = j - 1 ; k > j - 1 - L ; k--){ // 현재 위치에서 L만큼 같은 숫자인지 확인
                    if(arr[i][k] != cur || slope[k] || k < 0){ // 같은숫자가 아니거나 이미 경사로를 만들었거나 범위내에 없거나
                        check = 1; break;
                    }
                }
                if(!check){ // 같은 숫자이면서 경사로가 안만들어져있고 범위내에 있는 경우
                    for(int k = j - 1 ; k > j - 1 - L ; k--) slope[k] = 1; // 경사로 만듬
                } else {
                    flag = 1; break;
                };
            }else{ // 내리막
                int check = 0;
                int cur = arr[i][j]; // 현재 값이 유지 되는지
                for(int k = j ; k < j + L; k++){
                    if(arr[i][k] != cur || slope[k] || k >= N){
                        check = 1; break;
                    }
                }
                if(!check){
                    for(int k = j ; k < j + L ; k++) slope[k] = 1;
                } else {
                    flag = 1; break;
                };
            }
        }
        if(flag) continue; // 경사로가 만들어 질수 없는 경우
        else ans++; // 경사로를 만든 경우
    }
}

void Col(){
    for(int i = 0 ; i < N ; i++){
        int slope[101] = {0, }; // 경사로 중복을 방지하기 위한 배열
        int flag = 0; // col이 조건에 만족하는지
        for(int j = 1 ; j < N ; j++){
            if(arr[j][i] == arr[j-1][i]) continue; // 현재의 값과 직전의 값이 같은 경우
            else if(abs(arr[j][i] - arr[j-1][i]) > 1) {flag = 1; break;}; // 둘의 차이가 1 이상
            
            if(arr[j][i] > arr[j-1][i]){ // 오르막
                int check = 0; // 세부 조건들이 성립하는지
                int cur = arr[j][i] - 1; // 현재보다 작은값이 유지되는지
                for(int k = j - 1 ; k > j - 1 - L ; k--){ // 현재 위치에서 L만큼 같은 숫자인지 확인
                    if(arr[k][i] != cur || slope[k] || k < 0){ // 같은숫자가 아니거나 이미 경사로를 만들었거나 범위내에 없거나
                        check = 1; break;
                    }
                }
                if(!check){ // 같은 숫자이면서 경사로가 안만들어져있고 범위내에 있는 경우
                    for(int k = j - 1 ; k > j - 1 - L ; k--) slope[k] = 1; // 경사로 만듬
                } else {
                    flag = 1; break;
                };
            }else{ // 내리막
                int check = 0;
                int cur = arr[j][i]; // 현재 값이 유지되는지
                for(int k = j ; k < j + L; k++){
                    if(arr[k][i] != cur || slope[k] || k >= N){
                        check = 1; break;
                    }
                }
                if(!check){
                    for(int k = j ; k < j + L ; k++) slope[k] = 1;
                } else {
                    flag = 1; break;
                };
            }
        }
        if(flag) continue; // 경사로가 만들어 질수 없는 경우
        else ans++; // 경사로를 만든 경우
    }
}

int main(){
    
    Init();
    Row();
    Col();
    cout << ans << '\n';
    return 0;
}
