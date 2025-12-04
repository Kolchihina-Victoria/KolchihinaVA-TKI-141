#pragma once
// AuthorBook.h - Заголовочный файл класса AuthorBook
// Назначение: Определяет класс для книг с одним автором
// Наследует: Класс Book
// Особенность: Реализует чисто виртуальные методы базового класса

#include "Book.h"  // Базовый класс
#include <string>
#include <vector>

// Класс для представления книги с одним автором
// Наследует все поля и методы от Book
class AuthorBook : public Book {
private:
    // Дополнительное поле, специфичное для этого класса
    std::string author;  // Единственный автор книги
    
public:
    // Конструктор с дополнительным параметром - автором
    AuthorBook(const std::string& title, const std::string& author, 
               const std::string& theme, const std::string& publisher, 
               const std::string& location, int year);
    
    // Специфичный геттер для получения автора
    std::string getAuthor() const;
    
    // Реализация чисто виртуального метода из базового класса
    // Возвращает вектор с одним элементом - автором книги
    std::vector<std::string> getAuthors() const override;
    
    // Переопределение виртуального метода для вывода информации
    // Добавляет информацию об авторе к базовому выводу
    void printInfo() const override;
};
