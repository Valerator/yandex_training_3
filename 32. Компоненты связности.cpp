// Дан неориентированный невзвешенный граф, состоящий из N вершин и M ребер. Необходимо посчитать количество его компонент связности и вывести их.

// Формат ввода
// Во входном файле записано два числа N и M (0 < N ≤ 100000, 0 ≤ M ≤ 100000). В следующих M строках записаны по два числа i и j (1 ≤ i, j ≤ N), которые 
// означают, что вершины i и j соединены ребром.

// Формат вывода
// В первой строчке выходного файла выведите количество компонент связности. Далее выведите сами компоненты связности в следующем формате: в первой строке 
// количество вершин в компоненте, во второй - сами вершины в произвольном порядке.

#include <iostream>
#include <vector>

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
		if (!used[to]){
			dfs(to, edges);
        }
	}
}

void find_comps_count(int N, const std::vector<std::vector<int>> &edges, int &k) {
    for (int i = 1; i <= N; ++i)
		used[i] = false;
	for (int i = 1; i <= N; ++i) {
		if (!used[i]) {
			comp.clear();
            k++;
			dfs(i, edges);
        }
    }
}

void find_comps(int N, const std::vector<std::vector<int>> &edges) {
    for (int i = 1; i <= N; ++i)
		used[i] = false;
	for (int i = 1; i <= N; ++i) {
		if (!used[i]) {
			comp.clear();
			dfs(i, edges);
            std::cout << comp.size() << std::endl;
			for(size_t j = 0; j < comp.size(); ++j)
				std::cout << comp[j] << " ";
			std::cout << std::endl;
        }
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> edges(N + 1);
    filling(edges, M);
    int k = 0;
    find_comps_count(N, edges, k);
    std::cout << k << std::endl;
    find_comps(N, edges);
}
