// Рассмотрим последовательность, состоящую из круглых, квадратных и фигурных скобок. Программа дожна определить, является ли данная скобочная
// последовательность правильной. Пустая последовательность явлется правильной. Если A – правильная, то последовательности (A), [A], {A} – правильные. Если 
// A и B – правильные последовательности, то последовательность AB – правильная.

// Формат ввода
// В единственной строке записана скобочная последовательность, содержащая не более 100000 скобок.

// Формат вывода
// Если данная последовательность правильная, то программа должна вывести строку yes, иначе строку no.


#include <iostream>
#include <string>
#include <stack>

bool foo(std::string &s, std::stack<char> &st) {
    for(size_t i = 0; i < s.size(); i++) {
        if(st.empty() && (s[i] == '(' || s[i] == '{' || s[i] == '[')) {
            st.push(s[i]);
        } else if(st.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
            return false;
        } else if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else if(s[i] == ')' && st.top() == '(') {
            st.pop();
        } else if(s[i] == '}' && st.top() == '{') {
            st.pop();
        } else if(s[i] == ']' && st.top() == '[') {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}


int main() {
    std::string s;
    std::cin >> s;
    std::stack<char> st;
    if(foo(s, st) == false) {
        std::cout << "no";
    } else {
        std::cout << "yes";
    }
}
