# Competitive Programming Repository 🏆

A comprehensive collection of competitive programming solutions and algorithms, primarily focused on C++ implementations for various online judges and contests.

## 📁 Repository Structure

### **Online Judges & Contests**
- **🟦 Codeforces** - Solutions from various rounds (Educational, Global, Div2, etc.)
- **🟨 AtCoder** - Beginner, Regular, and Grand contest solutions
- **🟩 Beecrowd** - Brazilian online judge problems
- **🟪 CodeChef** - Starters and other contest solutions
- **🟫 CSES** - Problem Set solutions
- **🔵 UVa** - Classical problems from UVa Online Judge
- **🟠 Kattis** - Problem solutions
- **⭐ USACO** - Bronze, Silver, and Gold division problems

### **Brazilian Competitions**
- **🇧🇷 OBI** - Olimpíada Brasileira de Informática
- **🏫 Seletiva USP** - USP individual selection problems
- **🎯 Desafios de Programação** - Programming challenges
- **💡 Fundação Estudar** - Contest problems

### **International Competitions**
- **🌍 ICPC** - International Collegiate Programming Contest
- **🏆 CCC** - Canadian Computing Competition
- **🥇 Meta Hacker Cup** - Meta programming contest

### **Algorithm Library**
- **📚 kactl/** - KTH Algorithm Competition Template Library with custom implementations

## 🛠️ Algorithm Library

The `kactl/content/` folder contains optimized implementations of fundamental algorithms:

| Data Structure/Algorithm | File | Description |
|--------------------------|------|-------------|
| Segment Tree | `segtree.hpp` | Range query and update |
| Lazy Segment Tree | `lazySegtree.hpp` | Range updates with lazy propagation |
| Fenwick Tree | `fenwickTree.hpp` | Binary Indexed Tree for prefix sums |
| Binary Search Tree | `binarySearchTree.hpp` | Custom BST implementation |
| Dijkstra's Algorithm | `dijkstra.hpp` | Shortest path algorithm |
| LCA | `lca.hpp` | Lowest Common Ancestor |
| Modular Operations | `modOperations.hpp` | Modular arithmetic utilities |

## 🚀 Getting Started

### Template
The repository includes a standard competitive programming template (`template.cpp`):

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define f first
#define s second

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    return 0;
}
```

### Compilation
```bash
g++ -std=c++17 -O2 -Wall -Wextra -o solution solution.cpp
```