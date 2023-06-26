const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, ...f_input] = fs.readFileSync(filepath).toString().trim().split("\n");
const max_num = Math.max(...f_input);

let arr = [];
let prime_arr = [];

for (let i = 2; i <= max_num; i++) {
    if (arr[i] === true) continue;

    prime_arr.push(i);

    for (let j = i * 2; j <= max_num; j += i) {
        arr[j] = true;
    }
}

let ans = "";

f_input.map((N) => {
    let cnt = 0;
    let half = N / 2;

    for (let i = 0; i < prime_arr.length; i++) {
        if (parseInt(prime_arr[i]) > parseInt(half)) break;
        else if (!arr[N - prime_arr[i]]) cnt++;
    }
    ans += cnt + '\n';
});

console.log(ans);