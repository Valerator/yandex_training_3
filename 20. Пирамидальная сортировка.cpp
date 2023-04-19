// Отсортируйте данный массив. Используйте пирамидальную сортировку.

// Формат ввода
// Первая строка входных данных содержит количество элементов в массиве N, N ≤ 105. Далее задаются N целых чисел, не превосходящих по абсолютной величине 109.

// Формат вывода
// Выведите эти числа в порядке неубывания.

#include <iostream>
#include <vector>
 
class PriorityQueue {
private:
    int LEFT(int i) {
        return (2 * i + 1);
    }
 
    int RIGHT(int i) {
        return (2 * i + 2);
    }
 
    void heapify(std::vector<int> &vec, int i, int size) {
        int left = LEFT(i);
        int right = RIGHT(i);
 
        int largest = i;

        if (left < size && vec[left] > vec[i]) {
            largest = left;
        }
 
        if (right < size && vec[right] > vec[largest]) {
            largest = right;
        }
 
        if (largest != i) {
            std::swap(vec[i], vec[largest]);
            heapify(vec, largest, size);
        }
    }
 
public:
 
    PriorityQueue(std::vector<int> &vec, int n) {
        int i = (n - 2) / 2;
        while (i >= 0) {
            heapify(vec, i--, n);
        }
    }
 
    int pop(std::vector<int> &vec, int size) {
        if (size <= 0) {
            return -1;
        }
        int top = vec[0];
        vec[0] = vec[size-1];
        heapify(vec, 0, size - 1);
 
        return top;
    }
};
 
void heapsort(std::vector<int> &vec, int n) {
    PriorityQueue pq(vec, n);
    while(n > 0) {
        vec[n - 1] = pq.pop(vec, n);
        n--;
    }
}

void filling(std::vector<int> &vec, const unsigned N) {
    for(size_t i = 0; i < N; i++) {
        std::cin >> vec[i];
    }
}

void print_vec(const std::vector<int> &vec) {
    for(auto element: vec)
        std::cout << element << " ";
}
 
int main() {
    unsigned N;
    std::cin >> N;
    std::vector<int> vec(N);
    filling(vec, N);
    heapsort(vec, N);
    print_vec(vec);
}
