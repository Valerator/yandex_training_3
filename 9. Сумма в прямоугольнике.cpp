// Вам необходимо ответить на запросы узнать сумму всех элементов числовой матрицы N×M в прямоугольнике с левым верхним углом (x1, y1) и правым нижним 
// (x2, y2)

// Формат ввода
// В первой строке находится числа N, M размеры матрицы (1 ≤ N, M ≤ 1000) и K — количество запросов (1 ≤ K ≤ 100000). Каждая из следующих N строк содержит
// по M чисел`— элементы соответствующей строки матрицы (по модулю не превосходят 1000). Последующие K строк содержат по 4 целых числа, разделенных пробелом
// x1 y1 x2 y2 — запрос на сумму элементов матрице в прямоугольнике (1 ≤ x1 ≤ x2 ≤ N, 1 ≤ y1 ≤ y2 ≤ M)

// Формат вывода
// Для каждого запроса на отдельной строке выведите его результат — сумму всех чисел в элементов матрице в прямоугольнике (x1, y1), (x2, y2)


#include <iostream>
#include <vector>
 
std::vector<std::vector<int>> preprocess(std::vector<std::vector<int>> const &mat) {

    unsigned M = mat.size();
    unsigned N = mat[0].size();
 
    std::vector<std::vector<int>> sum(M, std::vector<int>(N));
 
    sum[0][0] = mat[0][0];

    for(int j = 1; j < N; j++) {
        sum[0][j] = mat[0][j] + sum[0][j - 1];
    }
 
    for (int i = 1; i < M; i++) {
        sum[i][0] = mat[i][0] + sum[i - 1][0];
    }
 
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    return sum;
}
 
int findSubmatrixSum(std::vector<std::vector<int>> const &mat, int p, int q, int r, int s, std::vector<std::vector<int>> &sum) {
    if (mat.size() == 0) {
        return 0;
    }
 
    int total = sum[r][s];
 
    if (q - 1 >= 0) {
        total -= sum[r][q - 1];
    }
 
    if (p - 1 >= 0) {
        total -= sum[p - 1][s];
    }
 
    if (p - 1 >= 0 && q - 1 >= 0) {
        total += sum[p - 1][q - 1];
    }
 
    return total;
}

void filling(unsigned N, std::vector<int> &vec) {
    for(int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }
}
 
int main() {

    unsigned M, N;
    std::cin >> N >> M;
    unsigned K;
    std::cin >> K;
    std::vector<std::vector<int>> mat(N);
    
    for(int i = 0; i < N; i++) {
        std::vector<int> str(M);
        filling(M, str);
        mat[i] = str;
    }

    std::vector<std::vector<int>> sum = preprocess(mat);

    for(int i = 0; i < K; i++) {
        unsigned x_1, y_1, x_2, y_2;
        std::cin >> x_1 >> y_1 >> x_2 >> y_2;
        std::cout << findSubmatrixSum(mat, x_1 - 1, y_1 - 1, x_2 - 1, y_2 - 1, sum);
        std::cout << std::endl;

    }
 
    return 0;
}
