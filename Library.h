#pragma once
// Назначение: Определяет класс библиотеки для управления коллекцией книг
// Реализует: Поиск книг по различным критериям
// Использует: Умные указатели для управления памятью

#include "Book.h"  // Базовый класс книг
#include <vector>
#include <memory>   // Для std::shared_ptr
#include <string>

// Класс библиотеки - основной управляющий класс
// Отвечает за хранение и поиск книг
class Library {
private:
    // Основное хранилище книг
    // Используем shared_ptr для безопасного разделения владения
    std::vector<std::shared_ptr<Book>> books;
    
public:
    // Добавление книги в библиотеку
    void addBook(const std::shared_ptr<Book>& book);
    
    // === Методы поиска по различным критериям ===
    
    // Поиск книг по точному совпадению названия
    std::vector<std::shared_ptr<Book>> findBooksByTitle(const std::string& title) const;
    
    // Поиск книг по автору (работает с соавторством)
    std::vector<std::shared_ptr<Book>> findBooksByAuthor(const std::string& author) const;
    
    // Поиск книг по тематике
    std::vector<std::shared_ptr<Book>> findBooksByTheme(const std::string& theme) const;
    
    // Поиск книг по издательству
    std::vector<std::shared_ptr<Book>> findBooksByPublisher(const std::string& publisher) const;
    
    // Поиск местоположения конкретной книги по названию
    std::string findBookLocation(const std::string& title) const;
    
    // Получение константной ссылки на все книги
    // Позволяет итерировать по коллекции без копирования
    const std::vector<std::shared_ptr<Book>>& getAllBooks() const;
};
