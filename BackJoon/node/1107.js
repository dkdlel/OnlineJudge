const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, M, ...broken_arr] = fs.readFileSync(filepath).toString().trim().split(/\s+/);

const max_N = 1000001;
const max_num = 987654321;

let channel = [];

for (let i = 0; i < max_N; i++) {
    let tmp = i.toString().split('');
    let dup = tmp.filter((num) => broken_arr.includes(num));
    channel[i] = dup.length ? false : true;
}

let large_num;
let small_num;

for (let i = N; i < max_N; i++) {
    if (channel[i]) {
        large_num = i;
        break;
    }
}

for (let i = N; i >= 0; i--) {
    if (channel[i]) {
        small_num = i;
        break;
    }
}

let large = large_num === undefined ? max_num : large_num - N + large_num.toString().length;
let small = small_num === undefined ? max_num : N - small_num + small_num.toString().length;
let up_down = N < 100 ? 100 - N : N - 100;

console.log(Math.min(large, small, up_down));