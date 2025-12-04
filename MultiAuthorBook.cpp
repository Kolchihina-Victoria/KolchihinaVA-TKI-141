//  Содержит определения методов класса MultiAuthorBook

#include "MultiAuthorBook.h"
#include <iostream>

// Конструктор: инициализирует базовый класс и вектор авторов
MultiAuthorBook::MultiAuthorBook(const std::string& title, 
                                 const std::vector<std::string>& authors, 
                                 const std::string& theme, const std::string& publisher, 
                                 const std::string& location, int year)
    : Book(title, theme, publisher, location, year),  // Базовый конструктор
      authors(authors) {}                             // Инициализация вектора авторов

// Возвращает вектор авторов книги
std::vector<std::string> MultiAuthorBook::getAuthors() const {
    return authors;  // Просто возвращаем копию вектора
}

// Переопределенный метод вывода информации
void MultiAuthorBook::printInfo() const {
    Book::printInfo();  // Сначала выводим общую информацию
    
    std::cout << "Авторы: ";
    // Итерируем по всем авторам и выводим их через запятую
    for (size_t i = 0; i < authors.size(); ++i) {
        std::cout << authors[i];
        if (i < authors.size() - 1) std::cout << ", ";  // Запятая кроме последнего
    }
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
}
