#!/usr/bin/env node
// "use strict";

// biome-ignore lint/style/useNodejsImportProtocol: <explanation>
const readline = require("readline"); // wtf?

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
const lines = [];
rl.on("line", (input) => lines.push(input));
rl.on("close", () => solve());

function solve() {
  let l = 0;
  let t = +lines[l++];
  while (t--) {
    handle();
  }

  function handle() {
    let [n, k] = lines[l++].trim().split(" ").map(Number);
    const a = lines[l++].trim().split(" ").map(Number);

    a.sort((x, y) => x - y);

    const cnt = [];
    for (let i = 0; i < n; i++) {
      let counter = 1;
      while (i + 1 < n && a[i] === a[i + 1]) {
        counter++;
        i++;
      }
      cnt.push(counter);
    }

    cnt.sort((x, y) => y - x);

    while (cnt.length) {
      // 什么老古董？？？
      // if (cnt.at(-1) <= k) {
      //   k -= cnt.at(-1);
      if (cnt[cnt.length - 1] <= k) {
        k -= cnt[cnt.length - 1];
        cnt.pop();
      } else {
        break;
      }
    }
    console.log(Math.max(cnt.length, 1));
  }
}
