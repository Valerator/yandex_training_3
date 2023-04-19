// Дан неориентированный граф, возможно, с петлями и кратными ребрами. Необходимо построить компоненту связности, содержащую первую вершину.

// Формат ввода
// В первой строке записаны два целых числа N (1 ≤ N ≤ 10^3) и M (0 ≤ M ≤ 5 * 10^5) — количество вершин и ребер в графе. В последующих M строках перечислены 
// ребра — пары чисел, определяющие номера вершин, которые соединяют ребра.

// Формат вывода
// В первую строку выходного файла выведите число K — количество вершин в компоненте связности. Во вторую строку выведите K целых чисел — вершины компоненты
// связности, перечисленные в порядке возрастания номеров.

#include <iostream>
#include <vector>
#include <algorithm>

bool used[500000];
std::vector<int> comp;

void filling(std::vector<std::vector<int>> &vec, int M) {
    for(size_t i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
}

void dfs(int vertex, const std::vector<std::vector<int>> &edges) {
    used[vertex] = true;
	comp.push_back(vertex);
	for (size_t i = 0; i < edges[vertex].size(); ++i) {
		int to = edges[vertex][i];
		if (! used[to])
			dfs(to, edges);
	}
}

void find_comps(int N, const std::vector<std::vector<int>> &edges) {
			dfs(1, edges);
            std::cout << comp.size() << std::endl;
            sort(comp.begin(), comp.end());
			for(size_t j = 0; j < comp.size(); ++j)
				std::cout << comp[j] << " ";
			std::cout << std::endl;
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> edges(N + 1);
    filling(edges, M);
    bool used[N + 1];
    find_comps(N, edges);
}
