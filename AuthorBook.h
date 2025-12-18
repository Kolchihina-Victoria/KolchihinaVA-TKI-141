#pragma once
// AuthorBook.h - Заголовочный файл класса AuthorBook
// Назначение: Определяет класс для книг с одним автором

#include "Book.h"
#include "Author.h"
#include <string>
#include <vector>
#include <memory>

// Класс для представления книги с одним автором
// Наследует все поля и методы от Book
class AuthorBook : public Book {
private:
    std::shared_ptr<Author> author;  // Указатель на автора

public:
    // Конструктор с указателем на автора
    AuthorBook(const std::string& title, const std::shared_ptr<Author>& author,
               const std::string& theme, const std::string& publisher, 
               const std::string& location, int year);
    
    // Конструктор с созданием нового автора (для обратной совместимости)
    AuthorBook(const std::string& title, const std::string& authorName,
               const std::string& theme, const std::string& publisher, 
               const std::string& location, int year);

    // Получение автора
    std::shared_ptr<Author> getAuthor() const;
    
    // Реализация чисто виртуального метода из базового класса
    std::vector<std::shared_ptr<Author>> getAuthors() const override;
    
    // Реализация метода для получения имен авторов
    std::vector<std::string> getAuthorNames() const override;
    
    // Переопределение виртуального метода для вывода информации
    void printInfo() const override;
};
