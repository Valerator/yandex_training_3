// Дан неориентированный граф. Требуется определить, есть ли в нем цикл, и, если есть, вывести его.

// Формат ввода
// В первой строке дано одно число n — количество вершин в графе ( 1 ≤ n ≤ 500 ). Далее в n строках задан сам граф матрицей смежности.

// Формат вывода
// Если в иcходном графе нет цикла, то выведите «NO». Иначе, в первой строке выведите «YES», во второй строке выведите число k — количество вершин в цикле, 
// а в третьей строке выведите k различных чисел — номера вершин, которые принадлежат циклу в порядке обхода (обход можно начинать с любой вершины цикла). 
// Если циклов несколько, то выведите любой.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 505;

int adj[N][N]; // Матрица смежности
bool visited[N]; // Массив посещенных вершин
int parent[N]; // Массив родителей для восстановления цикла

bool dfs(int u, int& start, int& end) {
    visited[u] = true;
    for (int v = 0; v < N; ++v) {
        if (adj[u][v]) {
            if (!visited[v]) {
                parent[v] = u;
                if (dfs(v, start, end)) {
                    return true;
                }
            } else if (v != parent[u]) { // Найден цикл
                start = v;
                end = u;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    // Чтение матрицы смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }

    // Поиск цикла в графе
    bool found_cycle = false;
    int cycle_start = -1, cycle_end = -1;
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            parent[u] = -1;
            found_cycle |= dfs(u, cycle_start, cycle_end);
            if (found_cycle) {
                break;
            }
        }
    }

    if (found_cycle) {
        // Восстановление цикла
        vector<int> cycle;
        for (int u = cycle_end; u != cycle_start; u = parent[u]) {
            cycle.push_back(u);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        // Вывод цикла
        cout << "YES" << endl;
        cout << cycle.size() << endl;
        for (int u : cycle) {
            cout << u + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

