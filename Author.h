#pragma once
// Author.h - Заголовочный файл класса Author
// Назначение: Определяет класс автора с уникальным идентификатором

#include <string>
#include <memory>
#include <iostream>
#include <vector>

// Форвард-декларация для избежания циклических зависимостей
class Book;

class Author {
private:
    int id;                // Уникальный идентификатор автора
    std::string name;      // Имя автора
    std::string biography; // Биография (опционально)
    std::vector<std::shared_ptr<Book>> books;  // Вектор книг автора

public:
    // Конструкторы
    Author(int id, const std::string& name);
    Author(int id, const std::string& name, const std::string& biography);

    // Геттеры
    int getId() const;
    std::string getName() const;
    std::string getBiography() const;

    // Сеттер для биографии
    void setBiography(const std::string& biography);

    // Методы для работы с книгами автора
    void addBook(const std::shared_ptr<Book>& book);
    std::vector<std::shared_ptr<Book>> getBooks() const;
    bool hasBooks() const;
    void printAllBooks() const;

    // Метод вывода информации
    void printInfo() const;

    // Оператор сравнения для использования в контейнерах
    bool operator==(const Author& other) const;

    // Метод для сравнения по имени (частичное совпадение)
    bool hasName(const std::string& name) const;
};
