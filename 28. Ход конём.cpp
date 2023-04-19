// Дана прямоугольная доска N × M (N строк и M столбцов). В левом верхнем углу находится шахматный конь, которого необходимо переместить в правый нижний угол
// доски. В данной задаче конь может перемещаться на две клетки вниз и одну клетку вправо или на одну клетку вниз и две клетки вправо.

// Необходимо определить, сколько существует различных маршрутов, ведущих из левого верхнего в правый нижний угол.

// Формат ввода
// Входной файл содержит два натуральных числа N и M , .

// Формат вывода
// В выходной файл выведите единственное число — количество способов добраться конём до правого нижнего угла доски.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp(n+1, vector<long long>(m+1));

    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            dp[i][j] = dp[i-1][j-2] + dp[i-2][j-1];
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}
