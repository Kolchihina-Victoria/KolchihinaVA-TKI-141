#include "AuthorBook.h"
#include <iostream>

// Конструктор с указателем на автора
AuthorBook::AuthorBook(const std::string& title, const std::shared_ptr<Author>& author,
                       const std::string& theme, const std::string& publisher, 
                       const std::string& location, int year)
    : Book(title, theme, publisher, location, year),  // Вызов конструктора Book
      author(author) {}

// Конструктор с созданием нового автора
AuthorBook::AuthorBook(const std::string& title, const std::string& authorName,
                       const std::string& theme, const std::string& publisher, 
                       const std::string& location, int year)
    : Book(title, theme, publisher, location, year),
      author(std::make_shared<Author>(0, authorName)) {}  // Создаем автора с временным ID

// Получение автора
std::shared_ptr<Author> AuthorBook::getAuthor() const {
    return author;
}

// Реализация абстрактного метода getAuthors()
std::vector<std::shared_ptr<Author>> AuthorBook::getAuthors() const {
    return {author};  // Вектор с одним элементом - автором
}

// Реализация метода для получения имен авторов
std::vector<std::string> AuthorBook::getAuthorNames() const {
    if (author) {
        return {author->getName()};
    }
    return {};
}

// Переопределенный метод вывода информации
void AuthorBook::printInfo() const {
    Book::printInfo();  // Вывод общей информации
    std::cout << "Автор: ";
    if (author) {
        std::cout << author->getName();
    }
    std::cout << std::endl;
    std::cout << "-" << std::endl;
}
