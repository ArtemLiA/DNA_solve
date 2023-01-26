#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

int main() {
    //Вводим строки
    std::string s1;
    std::string s2;
    std::cin >> s1;
    std::cin >> s2;
    if (s1.length() == 0 || s2.length() == 0){
        std::cout << 0;
        return 0;
    }
    std::map<char, unsigned long int> codes;
    //"Коды" для символов
    codes.insert({'A', 1050 * 1050 * 1050});
    codes.insert({'C', 1050 * 1050});
    codes.insert({'G', 1050});
    codes.insert({'T', 1});
    //векторы с значениями
    std::vector<unsigned long long> v1;
    std::vector<unsigned long long> v2;
    //Заполнение массивов
    for (size_t i = 0; i < s1.length(); i++){
        if (i == 0) {
            v1.push_back(codes[s1[0]]);
            continue;
        }
        v1.push_back(v1.at(i-1) + codes[s1[i]]);
    }
    for (size_t i = 0; i < s2.length(); i++){
        if (i == 0) {
            v2.push_back(codes[s2[0]]);
            continue;
        }
        v2.push_back(v2.at(i-1) + codes[s2[i]]);
    }
    size_t pos1 = -1;
    size_t pos2 = -1;
    size_t relation = 0;
    /* Делаем проход по подстрокам если для них числа будут равны, то значит
     * мы нашли анаграммы длины len. При этом поскольку перебор значений
     * len идёт от большего к меньшему, то при нахождении анаграммы
     * можно сразу прекращать выполнение циклов. */
    for (size_t len = std::min(s1.length(), s2.length()); len > 0; len--){
        for (size_t j = 0; j + len - 1 < s1.length(); j++){
            for (size_t k = 0; k + len - 1 < s2.length(); k++){
                if (v1.at(j + len - 1) - v1.at(j) + codes[s1[j]] == v2.at(k + len - 1) - v2.at(k) + codes[s2[k]]){
                    pos1 = j;
                    pos2 = k;
                    relation = len;
                    break;
                }
            }
            if (relation != 0){ //"Проброс" выхода из циклов
                break;
            }
        }
        if (relation != 0){ //"Проброс" выхода из циклов
            break;
        }
    }
    std::cout << relation << std::endl;
    if (relation != 0){
        std::cout << pos1 + 1 << " " << pos2 + 1 << std::endl;
    }
    return 0;
}
