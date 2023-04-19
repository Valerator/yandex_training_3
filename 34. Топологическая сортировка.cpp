// Дан ориентированный граф. Необходимо построить топологическую сортировку.

// Формат ввода
// В первой строке входного файла два натуральных числа N и M (1 ≤ N, M ≤ 100 000) — количество вершин и рёбер в графе соответственно. Далее в M 
// строках перечислены рёбра графа. Каждое ребро задаётся парой чисел — номерами начальной и конечной вершин соответственно.

// Формат вывода
// Выведите любую топологическую сортировку графа в виде последовательности номеров вершин (перестановка чисел от 1 до N). Если топологическую сортировку 
// графа построить невозможно, выведите -1.

#include <bits/stdc++.h>

using namespace std;
 
class Graph {

    int V;
 
    list<int>* adj;
 
public:
    Graph(int V);
 
    void addEdge(int u, int v);
 
    void topologicalSort();
};
 
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}
 
void Graph::topologicalSort() {
    
    vector<int> in_degree(V, 0);
 
    for (int u = 0; u < V; u++) {
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
            in_degree[*itr]++;
    }
 
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (in_degree[i] == 0)
            q.push(i);
 
    int cnt = 0;
 
    vector<int> top_order;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);
 
        list<int>::iterator itr;
        for (itr = adj[u].begin();
             itr != adj[u].end(); itr++)
 
            if (--in_degree[*itr] == 0)
                q.push(*itr);
 
        cnt++;
    }
 
    if (cnt != V) {
        cout << -1 << std::endl;
        return;
    }
 
    for (int i = 0; i < top_order.size(); i++)
        cout << top_order[i] + 1 << " ";
    cout << endl;
}
  
int main() {
    int N, M;
    std::cin >> N >> M;
    Graph g(N);
    for(int i = 0; i < M; ++i) {
        int x, y;
        std::cin >> x >> y;
        g.addEdge(x - 1, y - 1);
    }
  
    g.topologicalSort();
  
    return 0;
}
