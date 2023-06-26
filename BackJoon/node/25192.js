const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, ...f_input] = fs.readFileSync(filepath).toString().trim().split(/\s+/);

const arr = new Set();
let ans = 0;

f_input.forEach((input) => {
    if(input === 'ENTER'){
        ans += arr.size;
        arr.clear();
    }else{
        arr.add(input);
    }
});

console.log(ans += arr.size);