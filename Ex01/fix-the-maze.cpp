#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

#define NO 300
#define MAX_NO(t) (2*t*(2*t+1))
#define ROWS (4*n)
#define COLUMNS (2*(2*n+1))

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int n;
bool g[4 * NO + 2][4 * NO + 2];

void bfs(int x, int y) {
    queue<pair<int, int> > Q;
    Q.push(make_pair(x, y));
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for(int d = 0; d < 4; d++) {
            int x = u.first + dx[d], y = u.second + dy[d];
            if ((x >= 0 && x < ROWS) && (y >= 0 && y < COLUMNS) && !g[x][y]){
                Q.push(make_pair(x, y));
                g[x][y] = true;
            }
        }
    }
}

int main() {
    char b;
    int pairLine, bi, bj;
    while (cin >> n) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                g[i][j] = false;
            }
        }

        for (int i = 0; i < 2 * n - 1; i++) {
            for (int j = 0; j < n; j++) {
                cin >> b;
                pairLine = i % 2;
                bi = 2*i+1;
                bj = 2*(2*j + pairLine) + 1;
                if (b == 'H') {
                    g[bi][bj-1] = true;
                    g[bi][bj] = true;
                    g[bi][bj+1] = true;
                    g[bi][bj+2] = true;
                } 
                
                else {
                    g[bi-1][bj] = true;
                    g[bi][bj] = true;
                    g[bi+1][bj] = true;
                    g[bi+2][bj] = true;
                }
            }
        }
        int CFC = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (!g[i][j]) {
                    bfs(i, j);
                    CFC++;
                }
            }
        }
        cout << CFC-1 << endl;
    }

    return 0;
}