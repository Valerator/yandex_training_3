// Даны две последовательности, требуется найти и вывести их наибольшую общую подпоследовательность.

// Формат ввода
// В первой строке входных данных содержится число N – длина первой последовательности (1 ≤ N ≤ 1000). Во второй строке заданы члены первой 
// последовательности (через пробел) – целые числа, не превосходящие 10000 по модулю.

// В третьей строке записано число M – длина второй последовательности (1 ≤ M ≤ 1000). В четвертой строке задаются члены второй последовательности 
// (через пробел) – целые числа, не превосходящие 10000 по модулю.

// Формат вывода
// Требуется вывести наибольшую общую подпоследовательность данных последовательностей, через пробел.

#include <iostream>
#include <algorithm>
#include <vector>
 
std::vector<int> LCS(std::vector<int>& seq1, std::vector<int>& seq2) {
    size_t width = seq1.size() + 1;
    size_t height = seq2.size() + 1;
    std::vector<size_t> mx(width * height);
    std::fill(mx.begin(), mx.end(), 0);
    for (size_t i = 1; i < width; ++i) {
        for (size_t j = 1; j < height; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                mx[i * height + j] = mx[(i - 1) * height + j - 1] + 1;
            }
            else {
                mx[i * height + j] = std::max(mx[(i - 1) * height + j], mx[i * height + j - 1]);
            }
        }
    }
    std::vector<int> ret;
    size_t i = seq1.size();
    size_t j = seq2.size();
 
    while (i != 0 && j != 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            ret.push_back(seq1[i - 1]);
            --i; --j;
        }
        else if (mx[i * (seq2.size() + 1) + j - 1] > mx[(i - 1) * (seq2.size() + 1) + j]) {
            --j;
        }
        else {
            --i;
        }
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}
 
void show(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << ' ';  
    }
    std::cout << '\n';
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> vec_1(N);
    for(int i = 0; i < N; i++) {
        std::cin >> vec_1[i];
    }
    int M;
    std::cin >> M;
    std::vector<int> vec_2(M);
    for(int i = 0; i < M; i++) {
        std::cin >> vec_2[i];
    }
    std::vector<int> vec_3;
    vec_3 = LCS(vec_1, vec_2);
    show(vec_3);
}
