const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);

let ans = 0;

for (let i = 0; i < N - 2; i++) {
    for (let j = i + 1; j < N - 1; j++) {
        for (let k = j + 1; k < N; k++) {
            let sum = f_input[i] + f_input[j] + f_input[k];
            if (sum > M) continue;
            else if (sum > ans) ans = sum;
        }
    }
}

console.log(ans);