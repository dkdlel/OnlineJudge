const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

let [N, ...f_input] = fs.readFileSync(filepath).toString().trim().split('\n');

const setter = new Set();
setter.add('ChongChong');

f_input.forEach((input) => {
    const [A, B] = input.split(/\s+/);
    if(setter.has(A) || setter.has(B)){
        setter.add(A);
        setter.add(B);
    }
});

console.log(setter.size);