#include <iostream>
#include "Vector.h"

int main() {
    // Демонстрация работы с Vector
    Vector myVector = {10, 20, 30, 40, 50};
    std::cout << "Vector: " << myVector.toString() << std::endl;

    myVector << 60;
    std::cout << "After adding 60: " << myVector.toString() << std::endl;

    myVector.insert(2, 25);
    std::cout << "After inserting 25 at index 2: " << myVector.toString() << std::endl;

    myVector.remove(3);
    std::cout << "After removing element at index 3: " << myVector.toString() << std::endl;

    std::cout << "Search for 40: " << myVector.search(40) << std::endl;
    std::cout << "Is empty? " << myVector.isEmpty() << std::endl;

    Vector anotherVector;
    anotherVector = myVector;
    std::cout << "Copied Vector: " << anotherVector.toString() << std::endl;
      anotherVector >> 1;  //remove last element
     std::cout << "After removing element last: " << anotherVector.toString() << std::endl;


    return 0;
}
