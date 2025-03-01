# A. Alice's matrix problem

已知
$$
F_{i,j}=a(F_{i-1,j}+F_{i,j-1})
$$
给定 $a,F_{1,i},F_{i,1}$，求 $F_{n,n}\bmod (10^9+7)$。

$1\le a,n\le 10^5,1\le F_{1,i},F_{i,1}\le 10^5$

[CERC2015 F. Frightful Formula](https://codeforces.com/gym/101480/attachments/download/5837/20152016-acmicpc-central-europe-regional-contest-cerc-15-en.pdf) 弱化。

Code：HeRaNO

# B. Alice's flowers

求字符串的回文子串数模 $10^8+7$。

回文自动机或者 Manacher 板子题。

Code：Decision

$1\le n\le 2\times 10^6$

# C. Alice's country

一棵树，点的颜色为 $0$ 或 $1$。若树上一条路径经过 $0$ 点和 $1$ 点个数相等，就称这条路径是幸运的。点集的幸运值是集合内任意两城市形成的幸运路径条数。给出一个点的排列，取一连续段作为一个点集，剩下的构成另一个点集。希望第一个点集的幸运值大于第二个点集的。求有多少种连续段可以选择。

$1\le n\le 10^5$

[BZOJ 3320](https://vjudge.net/problem/BZOJ-3320)，原题根本没多少人过，而且网上没题解，合理怀疑出题人就嗯搬了数据。

# D. Alice's boatherds

连名字和输出都不改，是屑。

[POJ 2114](http://poj.org/problem?id=2114) 完全一致。

Code：HeRaNO

# E. Alice's game

就把 $3$ 的倍数改成了 $4$ 的倍数，是屑。

[聪聪可可](https://www.luogu.com.cn/problem/P2634)完全一致。

Code：HeRaNO

# F. Alice's number

求
$$
(\sin x+\sin y+\sin z)\times[x+y+z=n]\times[x\ge 1]\times[y\ge 1]\times[z\ge 1]
$$
的最大值。其中 $x,y,z$ 均为整数。

$1\le n\le 5\times 10^6$

[玲珑杯 Round 17. Sin your life](https://web.archive.org/web/20171104052222/https://www.ifrog.cc/acm/problem/1137)

Code：HeRaNO

# G. Alice's Card

$n$ 张卡片排成一排，背面朝上。每秒可以选择一张卡片和所有与其距离不超过 $k$ 的卡，把它们翻过来。选择第 $i$ 张卡的代价是 $C_i$，求让所有卡片都正面朝上的最小代价。

$1\le n\le 10^4,1\le k\le 10^3,1\le C_i\le 10^9$

[HackerRank - Turn Off the Lights](https://www.hackerrank.com/contests/101hack42/challenges/turn-off-the-lights)

Code：HeRaNO

# H. Alice's sequence

定义序列 $A$ 的伤心值为：
$$
\sum_{i=0}^{n-1}\sum_{j=i}^{n-1} |A_i-A_j|
$$
定义序列 $A$ 的开心值为：
$$
\sum_{i=0}^{n-1}A_i
$$
构造长度为 $l$ 且字典序最小的序列 $A$，使得开心值为 $n$，伤心值为 $m$。

$1\le l\le 50,0\le n,m\le 2\times 10^3$

[HackerRank - Array Construction](https://www.hackerrank.com/contests/university-codesprint/challenges/array-construction)

# I. Alice's book

给定 $m$ 个数，问 $[1,n]$ 中有多少数是奇数个给定数的倍数。

$1\le n\le 10^9,1\le m\le 25$

玲珑杯 Round 17. 震惊，99%+的中国人都会算错的问题

Code：HeRaNO

# J. Alice's segment tree

两类操作：

- 查询数列下标在 $[l,r]$ 区间中第一个大于等于 $v$ 的元素位置，不存在输出 $-1$；
- 区间加。

$1\le T\le 100,1\le n,q\le 10^5$

线段树板子

Code：yuanlinxiao

# K. Alice's friends

多次询问对于 $i<j$，有多少 $a_i+a_j\ge k$。

$1\le n,q\le 10^5,0\le a_i\le 10^5,0\le k\le 2\times 10^5$

SB FFT 卡我 39 发。

[HDU 4609](http://acm.hdu.edu.cn/showproblem.php?pid=4609)

Code：HeRaNO

# L. Alice's Big Set

原来的箱子里有 $n$ 个数，每次可以选两个数拿出来，然后把这两个数和它们的和放回箱子。求 $k$ 次操作后箱子里所有数和的最大值模 $10^7+7$。

$1\le n\le 10^5,0\le a_i\le 10^5,1\le k\le 10^9$

[HDU 5171](https://acm.hdu.edu.cn/showproblem.php?pid=5171)

Code：yuanlinxiao

# M. Alice's candy

名字都不改，是屑。

[BZOJ 4548](https://vjudge.net/problem/BZOJ-4548) 完全一致。

Code：HeRaNO

# N. Alice's startcraft game

一棵树，边权都是 $1$。每个点上都有快乐石，现在修一些仓库，修一个仓库花费是 $k$。如果两点之间距离是 $i$，则把快乐石运到仓库的花费是 $D_i$，求把快乐石全部运回仓库的情况下的最小花费。

$0\le D_{i-1}\le D_i\le 10^5,1\le n\le 200,1\le k\le 10^5$

[BZOJ 4711](https://vjudge.net/problem/BZOJ-4711) 完全一致。

# O. Alice's distence tree

一棵树，边权给定，求前 $m$ 长的路径长度。数据随机。

$1\le n\le 5\times 10^4,1\le m\le 3\times 10^5$

[BZOJ 3784](https://vjudge.net/problem/BZOJ-3784) 搬权限题，是屑，而且完全一致。

Code：Decision

# P. Alice's disaster

一棵树，多次询问，每次给出 $[L,R]$，表示编号范围在 $[L,R]$ 的点是安全的，再给一个 $x$，求点 $x$ 到安全的点最近距离。

$1\le n,q\le 10^5$

原题来自 [LibreOJ #6145](https://loj.ac/p/6145)，是屑。
