const fs = require("fs");
const filepath = process.platform === "linux" ? "/dev/stdin" : "./input.txt";

const [f_input, ...edges] = fs.readFileSync(filepath).toString().trim().split('\n');
const [N, M, V] = f_input.split(' ').map(Number);

const graph = Array.from(Array(N + 1), () => Array());
let visited = new Array(N + 1).fill(0);

edges.forEach((ele) => {
    let [a, b] = ele.split(' ').map(Number);
    graph[a].push(b);
    graph[b].push(a);
});

graph.map(ele => ele.sort((a,b) => a - b));

let dfs = bfs = '';
function DFS(node) {

    if (visited[node]) return;

    visited[node] = 1;
    dfs += node + ' ';
    for (let i = 0; i < graph[node].length; i++) {
        let next = graph[node][i];
        if (!visited[next]) {
            DFS(next);
        }
    }
}
function BFS(node){
    
    let queue = [node];
    visited[node] = 1;

    while(queue.length){

        let cur_node = queue.shift();
        bfs += cur_node + ' ';

        for(let i = 0 ; i < graph[cur_node].length ; i++){
            let next = graph[cur_node][i];
            if(!visited[next]){
                visited[next] = 1;
                queue.push(next);
            }
        }
    }
}

DFS(V);
visited.fill(0);
BFS(V);

console.log(`${dfs}\n${bfs}`);
