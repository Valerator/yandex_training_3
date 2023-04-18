// На клетчатой плоскости закрашено K клеток. Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все
// закрашенные клетки.

// Формат ввода
// Во входном файле, на первой строке, находится число K (1 ≤ K ≤ 100). На следующих K строках находятся пары чисел Xi и Yi – координаты закрашенных клеток 
// (|Xi|, |Yi| ≤ 109).

// Формат вывода
// Выведите в выходной файл координаты левого нижнего и правого верхнего углов прямоугольника.

#include <iostream>

void foo(const unsigned int K, unsigned int &min_1, unsigned int &min_2, unsigned int &max_1, unsigned int &max_2) {
    for(size_t i = 0; i < K; i++) {
        unsigned int a, b;
        std::cin >> a >> b;
        if(i == 0) {
            min_1 = a, max_1 = a;
            min_2 = b, max_2 = b;
        } else {
            if(a < min_1)
                min_1 = a;
            if(a > max_1)
                max_1 = a;
            if(b < min_2)
                min_2 = b;
            if(b > max_2)
                max_2 = b;
        }
    }
}

int main() {
    unsigned int K;
    std::cin >> K;
    unsigned int min_1, min_2, max_1, max_2;
    foo(K, min_1, min_2, max_1, max_2);
    std::cout << min_1 << " " << min_2 << " " << max_1 << " " << max_2 << std::endl;
}
