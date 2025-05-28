#include <iostream>
#include "../Library/IntVector.h"
/**
 @brief Функция main
 @return 1 в случае успеха, иначе - 0
*/
int main() {
    IntVector vec = { 1, 2, 3 };
    vec << 4 << 5;

    std::cout << "Vector: " << vec.to_string() << std::endl;

    int removed;
    vec >> removed;
    std::cout << "Removed: " << removed << std::endl;

    std::cout << "Index of 2: " << vec.find(2) << std::endl;

    std::cout << "Element at index 0: " << vec[0] << std::endl;

    return 0;
}
