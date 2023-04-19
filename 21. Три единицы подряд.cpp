По данному числу N определите количество последовательностей из нулей и единиц длины N, в которых никакие три единицы не стоят рядом.

Формат ввода
Во входном файле написано натуральное число N, не превосходящее 35.

Формат вывода
Выведите количество искомых последовательностей. Гарантируется, что ответ не превосходит 2^(31-1).

  
#include <iostream>

long long int dp[35];

int main() {
    dp[0] = 2;
    dp[1] = 4;
    dp[2] = 7;
    for (int i = 3; i < 35; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    int n;
    std::cin >> n;
    std::cout << dp[n - 1];

}
