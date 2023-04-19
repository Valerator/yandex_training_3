// На клеточном поле, размером NxM (2 ≤ N, M ≤ 250) сидит Q (0 ≤ Q ≤ 10000) блох в различных клетках. "Прием пищи" блохами возможен только в кормушке - 
// одна из клеток поля, заранее известная. Блохи перемещаются по полю странным образом, а именно, прыжками, совпадающими с ходом обыкновенного шахматного 
// коня. Длина пути каждой блохи до кормушки определяется как количество прыжков. Определить минимальное значение суммы длин путей блох до кормушки или, 
// если собраться блохам у кормушки невозможно, то сообщить об этом. Сбор невозможен, если хотя бы одна из блох не может попасть к кормушке.

// Формат ввода
// В первой строке входного файла находится 5 чисел, разделенных пробелом: N, M, S, T, Q. N, M - размеры доски (отсчет начинается с 1); S, T - координаты 
// клетки - кормушки (номер строки и столбца соответственно), Q - количество блох на доске. И далее Q строк по два числа - координаты каждой блохи.

// Формат вывода
// Содержит одно число - минимальное значение суммы длин путей или -1, если сбор невозможен.


#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int INF = 1e9;
const int MAXN = 255;
const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};

int n, m, s, t, q;
int d[MAXN][MAXN];
bool used[MAXN][MAXN];
vector<pair<int, int>> blohs;

bool is_valid(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

void bfs(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    memset(d, -1, sizeof(d));
    memset(used, 0, sizeof(used));
    d[sx][sy] = 0;
    used[sx][sy] = true;
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if (is_valid(nx, ny) && !used[nx][ny]) {
                used[nx][ny] = true;
                d[nx][ny] = d[v.first][v.second] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main() {
    cin >> n >> m >> s >> t >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        blohs.push_back(make_pair(x, y));
    }
    bfs(s, t);
    int ans = 0;
    for (int i = 0; i < q; i++) {
        int x = blohs[i].first;
        int y = blohs[i].second;
        if (d[x][y] == -1) {
            cout << "-1" << endl;
            return 0;
        }
        ans += d[x][y];
    }
    cout << ans << endl;
    return 0;
}

