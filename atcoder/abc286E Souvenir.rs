use std::io::stdin;

fn main() {
    let mut buf = stdin().lines();
    let n: usize = buf.next().unwrap().unwrap().parse().unwrap();
    let a: Vec<usize> = buf
        .next()
        .unwrap()
        .unwrap()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut g: Vec<Vec<char>> = Vec::with_capacity(n);
    for _ in 0..n {
        g.push(buf.next().unwrap().unwrap().chars().collect());
    }

    let q: usize = buf.next().unwrap().unwrap().parse().unwrap();

    let mut qq: Vec<(usize, usize)> = Vec::with_capacity(q);
    for _ in 0..q {
        let parts = buf
            .next()
            .unwrap()
            .unwrap()
            .split_whitespace()
            .map(|x| x.parse::<usize>().unwrap())
            .collect::<Vec<usize>>();

        qq.push((parts[0] - 1, parts[1] - 1));
    }

    let mut dis: Vec<Vec<usize>> = vec![vec![1_000_000_000; n]; n];
    let mut val: Vec<Vec<usize>> = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            if i == j {
                dis[i][j] = 0;
                val[i][j] = a[i];
            } else if g[i][j] == 'Y' {
                dis[i][j] = 1;
                val[i][j] = a[i] + a[j];
            }
        }
    }

    for k in 0..n {
        for i in 0..n {
            for j in 0..n {
                match dis[i][j].cmp(&(dis[i][k] + dis[k][j])) {
                    std::cmp::Ordering::Greater => {
                        dis[i][j] = dis[i][k] + dis[k][j];
                        val[i][j] = val[i][k] + val[k][j] - a[k];
                    }
                    std::cmp::Ordering::Equal => {
                        val[i][j] = std::cmp::max(val[i][j], val[i][k] + val[k][j] - a[k]);
                    }
                    std::cmp::Ordering::Less => {}
                }
            }
        }
    }

    for (u, v) in qq {
        if dis[u][v] == 1_000_000_000 {
            println!("Impossible");
        } else {
            println!("{} {}", dis[u][v], val[u][v]);
        }
    }
}

// 2025-03-27
// https://atcoder.jp/contests/abc286/tasks/abc286_e
