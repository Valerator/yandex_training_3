// Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки abcaabdddettq равна 3)

// Сделайте данную вам строку как можно более красивой, если вы можете сделать не более k операций замены символа.

// Формат ввода
// В первой строке записано одно целое число k (0 ≤ k ≤ 109)

// Во второй строке дана непустая строчка S (|S| ≤ 2 ⋅ 105). Строчка S состоит только из маленьких латинских букв.

// Формат вывода
// Выведите одно число — максимально возможную красоту строчки, которую можно получить.

#include <iostream>
#include <string>
#include <cmath>

unsigned find_len(std::string &s, unsigned n, unsigned k, char c) {
    unsigned maxlen = 1;
    unsigned cnt = 0;
    unsigned l = 0, r = 0;
      
    while (r < n) {
      
        if (s[r] != c)
            ++cnt;
  
        while (cnt > k) {
            if (s[l] != c)
                --cnt;
            ++l;
        }
        maxlen = std::max(maxlen, r - l + 1);
        ++r;
    }
    return maxlen;
}

unsigned answer(std::string &s, unsigned n, unsigned k) {
    unsigned maxlen = 1;
    for (int i = 0; i < 26; ++i) {
        maxlen = std::max(maxlen, find_len(s, n, k, i + 'a'));
    }
    return maxlen;
}

int main() {
    unsigned k;
    std::cin >> k;
    std::string x;
    std::cin >> x;
    unsigned n = x.size();
    std::cout << answer(x, n, k);
}
