// Научитесь пользоваться стандартной структурой данных deque для целых чисел.  Напишите программу, содержащую описание дека и моделирующую работу дека, 
// реализовав все указанные здесь методы. Программа считывает последовательность команд и в зависимости от команды выполняет ту или иную операцию. После 
// выполнения каждой команды программа должна вывести одну строчку.

// Возможные команды для программы:

// push_front n
// Добавить (положить) в начало дека новый элемент. Программа должна вывести ok.

// push_back n
// Добавить (положить) в конец дека новый элемент. Программа должна вывести ok.

// pop_front
// Извлечь из дека первый элемент. Программа должна вывести его значение.

// pop_back
// Извлечь из дека последний элемент. Программа должна вывести его значение.

// front
// Узнать значение первого элемента (не удаляя его). Программа должна вывести его значение.

// back
// Узнать значение последнего элемента (не удаляя его). Программа должна вывести его значение.

// size
// Вывести количество элементов в деке.

// clear
// Очистить дек (удалить из него все элементы) и вывести ok.

// exit
// Программа должна вывести bye и завершить работу.

// Гарантируется, что количество элементов в деке в любой момент не превосходит 100. Перед исполнением операций pop_front, pop_back, front, back программа 
// должна проверять, содержится ли в деке хотя бы один элемент. Если во входных данных встречается операция pop_front, pop_back, front, back, и при этом 
// дек пуст, то программа должна вместо числового значения вывести строку error.

// Формат ввода
// Вводятся команды управления деком, по одной на строке.

// Формат вывода
// Требуется вывести протокол работы дека, по одному сообщению на строке

#include <iostream>
#include <deque>

class Queue{
private:

    std::deque<int> _deq;

public:
    
    Queue() {}

    void push_front(int n) {
        _deq.push_front(n);
        std::cout << "ok" << std::endl;
    }

    void push_back(int n) {
        _deq.push_back(n);
        std::cout << "ok" << std::endl;
    }

    void pop_front() {
        if(_deq.empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _deq.front() << std::endl;
            _deq.pop_front();
        }
    }

    void pop_back() {
        if(_deq.empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _deq.back() << std::endl;
            _deq.pop_back();
        }
    }

    void front() {
        if(_deq.empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _deq.front() << std::endl;
        }
    }

    void back() {
        if(_deq.empty()) {
            std::cout << "error" << std::endl;
        } else {
            std::cout << _deq.back() << std::endl;
        }
    }

    void size() {
        std::cout << _deq.size() << std::endl;;
    }

    void clear() {
        _deq = std::deque<int>();
        std::cout << "ok" << std::endl;
    }

    void exit() {
        std::cout << "bye" << std::endl;
        std::exit(0);
    }
    
};

int main() {
    std::string s;
    Queue st;
    while (std::cin >> s) {
        if(s == "push_back") {
            int x;
            std::cin >> x;
            st.push_back(x);
        }
        if(s == "push_front") {
            int x;
            std::cin >> x;
            st.push_front(x);
        }
        if(s == "pop_front") {
            st.pop_front();
        }
        if(s == "pop_back") {
            st.pop_back();
        }
        if(s == "front") {
            st.front();
        }
        if(s == "back") {
            st.back();
        }
        if(s == "size") {
            st.size();
        }
        if(s == "clear") {
            st.clear();
        }
        if(s == "exit") {
            st.exit();
        }
    }
}
