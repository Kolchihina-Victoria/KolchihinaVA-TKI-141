#include "MultiAuthorBook.h"
#include <iostream>

// Конструктор с вектором авторов
MultiAuthorBook::MultiAuthorBook(const std::string& title, 
                                 const std::vector<std::shared_ptr<Author>>& authors,
                                 const std::string& theme, const std::string& publisher, 
                                 const std::string& location, int year)
    : Book(title, theme, publisher, location, year),  // Базовый конструктор
      authors(authors) {}                             // Инициализация вектора авторов

// Конструктор с именами авторов
MultiAuthorBook::MultiAuthorBook(const std::string& title, 
                                 const std::vector<std::string>& authorNames,
                                 const std::string& theme, const std::string& publisher, 
                                 const std::string& location, int year)
    : Book(title, theme, publisher, location, year) {
    
    // Создаем авторов из имен
    for (const auto& name : authorNames) {
        authors.push_back(std::make_shared<Author>(0, name));  // Временный ID
    }
}

// Возвращает вектор авторов книги
std::vector<std::shared_ptr<Author>> MultiAuthorBook::getAuthors() const {
    return authors;
}

// Возвращает имена авторов
std::vector<std::string> MultiAuthorBook::getAuthorNames() const {
    std::vector<std::string> names;
    for (const auto& author : authors) {
        if (author) {
            names.push_back(author->getName());
        }
    }
    return names;
}

// Переопределенный метод вывода информации
void MultiAuthorBook::printInfo() const {
    Book::printInfo();  // Сначала выводим общую информацию

    std::cout << "Авторы: ";
    // Итерируем по всем авторам и выводим их через запятую
    for (size_t i = 0; i < authors.size(); ++i) {
        if (authors[i]) {
            std::cout << authors[i]->getName();
            if (i < authors.size() - 1) std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "" << std::endl;
}
