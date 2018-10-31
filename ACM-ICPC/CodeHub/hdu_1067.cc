#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>

struct node {
  int map[4][8];
  int stp;
  int* operator[](int idx) { return map[idx]; }
  bool operator==(const node& o) const {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (map[i][j] != o.map[i][j]) return false;
      }
    }
    return true;
  }
};

// namespace std {
//   template<>
//   struct hash<node> {
//     std::size_t operator()(const node& now) const {
//       auto ret = 0;
//       for (int i = 0; i < 4; ++i) {
//         for (int j = 0; j < 8; ++j) {
//           ret += (i + 1) * (j + 1) * now.map[i][j];
//         }
//       }
//       return ret + now.stp;
//     }
//   };
// }

struct Mhash {
  size_t operator()(const node& now) const {
    auto ret = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 8; ++j) {
        ret += (i + 1) * (j + 1) * now.map[i][j];
      }
    }
    return ret + now.stp;
  }
};

const int aim[4][8] = {
    {11, 12, 13, 14, 15, 16, 17, 0},
    {21, 22, 23, 24, 25, 26, 27, 0},
    {31, 32, 33, 34, 35, 36, 37, 0},
    {41, 42, 43, 44, 45, 46, 47, 0},
};

bool completeQ(node& now) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (now[i][j] != aim[i][j]) return false;
    }
  }
  return true;
}

int bfs(node& beg) {
  beg.stp = 0;
  std::queue<node> q;
  std::unordered_map<node, bool, Mhash> vis;
  vis.clear();
  q.push(beg);
  vis[beg] = 1;
  node now, nxt;
  while (!q.empty()) {
    now = q.front();
    q.pop();
    if (completeQ(now)) return now.stp;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 8; ++j) {
        if (now[i][j] == 0 && now[i][j - 1] % 10 != 7) {
          for (int k = 0; k < 4; ++k) {
            for (int l = 0; l < 8; ++l) {
              if (now[k][l] % 10 - 1 == now[i][j - 1] % 10 &&
                  now[k][l] / 10 == now[i][j - 1] / 10) {
                nxt = now;
                nxt[i][j] = nxt[k][l];
                nxt[k][l] = 0;
                nxt.stp = now.stp + 1;
                if (vis[nxt]) continue;
                q.push(nxt);
                vis[nxt] = 1;
              }
            }
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    node beg;
    for (int i = 0; i < 4; ++i) {
      for (int j = 1; j < 8; ++j) {
        std::cin >> beg[i][j];
        switch (beg[i][j]) {
          case 11:
            beg[0][0] = 11;
            beg[i][j] = 0;
            break;
          case 21:
            beg[1][0] = 21;
            beg[i][j] = 0;
            break;
          case 31:
            beg[2][0] = 31;
            beg[i][j] = 0;
            break;
          case 41:
            beg[3][0] = 41;
            beg[i][j] = 0;
            break;
        }
      }
    }
    std::cout << bfs(beg) << std::endl;
  }
}
