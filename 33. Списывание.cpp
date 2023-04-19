// Во время контрольной работы профессор Флойд заметил, что некоторые студенты обмениваются записками. Сначала он хотел поставить им всем двойки, но в тот 
// день профессор был добрым, а потому решил разделить студентов на две группы: списывающих и дающих списывать, и поставить двойки только первым.

// У профессора записаны все пары студентов, обменявшихся записками. Требуется определить, сможет ли он разделить студентов на две группы так, чтобы любой 
// обмен записками осуществлялся от студента одной группы студенту другой группы.

// Формат ввода
// В первой строке находятся два числа N и M — количество студентов и количество пар студентов, обменивающихся записками (1 ≤ N ≤ 102, 0 ≤ M ≤ N(N−1)/2).

// Далее в M строках расположены описания пар студентов: два числа, соответствующие номерам студентов, обменивающихся записками (нумерация студентов идёт с 1). Каждая пара студентов перечислена не более одного раза.

// Формат вывода
// Необходимо вывести ответ на задачу профессора Флойда. Если возможно разделить студентов на две группы - выведите YES; иначе выведите NO.

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

void dfs(int vertex, const std::vector<std::vector<int>> &edges, std::vector<bool> &color, bool col) {
    used[vertex] = true;
    color[vertex] = col;
	comp.push_back(vertex);
	for (size_t i = 0; i < edges[vertex].size(); ++i) {
		int to = edges[vertex][i];
		if(used[to] && color[to] == color[vertex]) {
            std::cout << "NO" << std::endl;
            exit(0);
        }
        if(!used[to]) {
            dfs(to, edges, color, !col);
        }
	}
}

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::vector<int>> edges(N + 1);
    filling(edges, M);
    std::vector<bool> color(N + 1);
    for(int i = 0; i < N; ++i) {
        if(!used[i]) {
            dfs(i, edges, color, true);
        }
    }
    std::cout << "YES" << std::endl;
}
