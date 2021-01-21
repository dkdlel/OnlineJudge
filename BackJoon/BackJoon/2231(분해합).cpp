//
//  2231(분해합).cpp
//  BackJoon
//
//  Created by  JeJn on 2021/01/21.
//  Copyright © 2021  JeJn. All rights reserved.
//

#include<iostream>
using namespace std;

int main() {

    int num;
    bool flag = false;
    cin >> num;

    
    for (int i = 1; i < num; i++) {
        int sum = i;
        int tmp = i;
        while (1) {
            sum += tmp % 10;
            tmp /= 10;
            if (tmp >= 0 && tmp <= 9) {
                sum += tmp;
                break;
            }
        }
        if (sum == num) {
            flag = true;
            cout << i << '\n';
            break;
        }
    }
    if (!flag) cout << 0 << '\n';
    return 0;
}
