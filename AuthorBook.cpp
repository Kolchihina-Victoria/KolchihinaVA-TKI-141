// AuthorBook.cpp - Реализация методов класса AuthorBook
// Назначение: Содержит определения методов класса AuthorBook

#include "AuthorBook.h"
#include <iostream>

// Конструктор: сначала вызывает конструктор базового класса,
// затем инициализирует собственное поле author
AuthorBook::AuthorBook(const std::string& title, const std::string& author, 
                       const std::string& theme, const std::string& publisher, 
                       const std::string& location, int year)
    : Book(title, theme, publisher, location, year),  // Вызов конструктора Book
      author(author) {}                               // Инициализация author

// Возвращает автора книги
std::string AuthorBook::getAuthor() const {
    return author;
}

// Реализация абстрактного метода getAuthors()
// Возвращает вектор строк с одним элементом
std::vector<std::string> AuthorBook::getAuthors() const {
    return {author};  // Создание вектора с одним элементом
}

// Переопределенный метод вывода информации
// Сначала вызывает метод базового класса, затем добавляет свою информацию
void AuthorBook::printInfo() const {
    Book::printInfo();  // Вывод общей информации
    std::cout << "Автор: " << author << std::endl;  // Добавление информации об авторе
    std::cout << "-------------------" << std::endl;  // Разделитель для читаемости
}
