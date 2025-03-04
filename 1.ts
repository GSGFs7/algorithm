#!/usr/bin/env ts-node

// const fs = require('node:fs');
// const data = fs.readFileSync("/dev/stdin");
// const result = data
//   .toString("ascii")
//   .trim()
//   .split(" ")
//   .map((x) => Number.parseInt(x))
//   .reduce((a, b) => a + b, 0);
// console.log(result);
// process.exit();

function merge(intervals: number[][]): number[][] {
  intervals.sort((a, b) => (a.at(0) ?? 0) - (b.at(0) ?? 0));

  const ans = [];
  for (const now of intervals) {
    if (!ans.length) {
      ans.push(now);
      continue;
    }

    if ((ans.at(-1)?.at(1) ?? 0) >= (now.at(0) ?? 0)) {
      ans[ans.length - 1][1] = Math.max(ans[ans.length - 1][1], now[1]);
    } else {
      ans.push(now);
    }
  }

  return ans;
}

console.log(
  merge([
    [1, 3],
    [2, 6],
    [8, 10],
    [15, 18],
  ])
);
