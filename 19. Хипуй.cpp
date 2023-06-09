// В этой задаче вам необходимо самостоятельно (не используя соответствующие классы и функции стандартной библиотеки) организовать структуру данных Heap для 
// хранения целых чисел, над которой определены следующие операции: a) Insert(k) – добавить в Heap число k ; b) Extract достать из Heap наибольшее число 
// (удалив его при этом).

// Формат ввода
// В первой строке содержится количество команд N (1 ≤ N ≤ 100000), далее следуют N команд, каждая в своей строке. Команда может иметь формат: “0 <число>” 
// или “1”, обозначающий, соответственно, операции Insert(<число>) и Extract. Гарантируется, что при выполнении команды Extract в структуре находится по 
// крайней мере один элемент.

// Формат вывода
// Для каждой команды извлечения необходимо отдельной строкой вывести число, полученное при выполнении команды Extract.

#include <iostream>
#include <queue>

class Heap {
private:

    std::priority_queue<int> _h;

public:

    Heap() {}

    void insert(int k) {
        _h.push(k);
    }

    void extract() {
        std::cout << _h.top() << std::endl;
        _h.pop();
    }

};


void foo(const unsigned N) {
    Heap h;
    for(int i = 0; i < N; i++) {
        bool a;
        std::cin >> a;
        if(a) {
            h.extract();
        } else {
            int b;
            std::cin >> b;
            h.insert(b);
        }
    }
}

int main() {
    unsigned N;
    std::cin >> N;
    foo(N);
}

