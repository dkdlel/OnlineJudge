//
//  1904(01타일).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/29.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 1000001

int main(){
    
    int arr[MAX] = {1,2};
    for(int i = 2 ; i < MAX ; i++) arr[i] = (arr[i-1] + arr[i-2]) % 15746;
    int num; cin >> num; cout << arr[num-1] << '\n';
    
    return 0;
}
