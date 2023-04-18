// Васин жесткий диск состоит из M секторов. Вася последовательно устанавливал на него различные операционные системы следующим методом: он создавал новый 
// раздел диска из последовательных секторов, начиная с сектора номер ai и до сектора bi включительно, и устанавливал на него очередную систему. При этом, 
// если очередной раздел хотя бы по одному сектору пересекается с каким-то ранее созданным разделом, то ранее созданный раздел «затирается», и операционная 
// система, которая на него была установлена, больше не может быть загружена.

// Напишите программу, которая по информации о том, какие разделы на диске создавал Вася, определит, сколько в итоге работоспособных операционных систем
// установлено и работает в настоящий момент на Васином компьютере.

// Формат ввода
// Сначала вводятся натуральное число M — количество секторов на жестком диске (1 ≤ M ≤ 109) и целое число N — количество разделов, которое последовательно 
// создавал Вася (0 ≤ N ≤ 1000).

// Далее идут N пар чисел ai и bi, задающих номера начального и конечного секторов раздела (1 ≤ ai ≤ bi ≤ M).

// Формат вывода
// Выведите одно число — количество работающих операционных систем на Васином компьютере.


#include <iostream>
#include <vector>

int main() {
    unsigned M, K;
    std::cin >> M >> K;
    uint64_t ans = 0;
    std::vector<std::pair<uint64_t, uint64_t>> vec;
    for(size_t i = 0; i < K; i++) {
        uint64_t a, b;
        std::cin >> a >> b;
        std::pair<uint64_t, uint64_t> p(a, b);
        for(size_t j = 0; j < vec.size(); j++) {
            if((a <= vec[j].first && b >= vec[j].first) || (a <= vec[j].second && b >= vec[j].second) || 
                (a >= vec[j].first && a <= vec[j].second) || (b <= vec[j].second && b >= vec[j].first)) {
                vec[j].first = 0;
                vec[j].second = 0;
            }
        }
        vec.push_back(p);
    }
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i].first && vec[i].second)
            ans++;
    }
    std::cout << ans;
    return 0;
}
