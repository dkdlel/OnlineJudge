const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, NUM, OPER] = fs.readFileSync(filepath).toString().trim().split('\n');
N = parseInt(N);
NUM = NUM.split(/\s+/).map(Number);
OPER = OPER.split(/\s+/).map(Number);
let max = -987654321;
let min = 987654321;

function calc(num, oper_idx, ans) {
    switch (oper_idx) {
        case 0:
            ans += num;
            break;
        case 1:
            ans -= num;
            break;
        case 2:
            ans *= num;
            break;
        case 3:
            ans = ans < 0
                ? Math.floor((ans * -1) / num) * -1
                : ans = Math.floor(ans / num);
            break;
    }
    return ans;
}

function dfs(idx, ans, OPER) {

    if (idx === N) {
        max = Math.max(ans, max);
        min = Math.min(ans, min);
        return;
    }

    for (let i = 0; i < 4; i++) {
        if (OPER[i] > 0) {
            let newOper = JSON.parse(JSON.stringify(OPER));
            newOper[i]--;
            dfs(idx + 1, calc(NUM[idx], i, ans), newOper);
        }
    }
}

dfs(1, NUM[0], OPER);

console.log(max + '\n' + min);