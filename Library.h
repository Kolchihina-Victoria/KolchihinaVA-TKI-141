#pragma once

// Назначение: Определяет класс библиотеки для управления коллекцией книг

#include "Book.h"
#include "AuthorBook.h"
#include "MultiAuthorBook.h"
#include "Author.h"
#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

class Library {
private:
    // Основное хранилище книг (теперь содержит конкретные типы)
    std::vector<std::shared_ptr<AuthorBook>> authorBooks;
    std::vector<std::shared_ptr<MultiAuthorBook>> multiAuthorBooks;
    
    // Хранилище авторов (для быстрого доступа по ID)
    std::unordered_map<int, std::shared_ptr<Author>> authors;
    
    // Счетчик для генерации уникальных ID авторов
    int nextAuthorId;

public:
    // Конструктор
    Library();
    
    // Методы работы с авторами 
    
    // Добавление нового автора
    std::shared_ptr<Author> addAuthor(const std::string& name);
    std::shared_ptr<Author> addAuthor(const std::string& name, const std::string& biography);
    
    // Поиск автора по ID
    std::shared_ptr<Author> findAuthorById(int id) const;
    
    // Поиск автора по имени (частичное совпадение)
    std::vector<std::shared_ptr<Author>> findAuthorsByName(const std::string& name) const;
    
    // Получение всех авторов
    std::vector<std::shared_ptr<Author>> getAllAuthors() const;
    
    // === Методы работы с книгами ===
    
    // Добавление книги с одним автором
    void addAuthorBook(const std::shared_ptr<AuthorBook>& book);
    
    // Добавление книги с несколькими авторами
    void addMultiAuthorBook(const std::shared_ptr<MultiAuthorBook>& book);
    
    // Создание и добавление книги с одним автором (по ID автора)
    void addAuthorBook(const std::string& title, int authorId,
                      const std::string& theme, const std::string& publisher,
                      const std::string& location, int year);
    
    // Создание и добавление книги с несколькими авторами (по ID авторов)
    void addMultiAuthorBook(const std::string& title, const std::vector<int>& authorIds,
                           const std::string& theme, const std::string& publisher,
                           const std::string& location, int year);
    
    // Методы поиска книг 
    
    // Поиск книг по точному совпадению названия
    std::vector<std::shared_ptr<Book>> findBooksByTitle(const std::string& title) const;
    
    // Поиск книг по автору (по ID автора)
    std::vector<std::shared_ptr<Book>> findBooksByAuthor(int authorId) const;
    
    // Поиск книг по имени автора (частичное совпадение)
    std::vector<std::shared_ptr<Book>> findBooksByAuthorName(const std::string& authorName) const;
    
    // Поиск книг по тематике
    std::vector<std::shared_ptr<Book>> findBooksByTheme(const std::string& theme) const;
    
    // Поиск книг по издательству
    std::vector<std::shared_ptr<Book>> findBooksByPublisher(const std::string& publisher) const;
    
    // Поиск местоположения конкретной книги по названию
    std::string findBookLocation(const std::string& title) const;
    
    // Получение всех книг (как базового типа)
    std::vector<std::shared_ptr<Book>> getAllBooks() const;
    
    // Получение всех книг с одним автором
    const std::vector<std::shared_ptr<AuthorBook>>& getAllAuthorBooks() const;
    
    // Получение всех книг с несколькими авторами
    const std::vector<std::shared_ptr<MultiAuthorBook>>& getAllMultiAuthorBooks() const;
};
