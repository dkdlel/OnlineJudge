const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [min, max] = fs.readFileSync(filepath).toString().trim().split(/\s+/).map(Number);
let arr = [];
let cnt = 0;

for (let i = 2; i * i <= max; i++) {
    let num = Math.floor(min / (i * i));
    if (min % (i * i)) num++;

    while (i * i * num <= max) {
        if (!arr[i * i * num]) {
            arr[i * i * num] = true;
            cnt++;
        }
        num++;
    }
}

console.log(max - min + 1 - cnt);