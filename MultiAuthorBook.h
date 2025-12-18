#pragma once

// Назначение: Определяет класс для книг с несколькими авторами

#include "Book.h"
#include "Author.h"
#include <string>
#include <vector>
#include <memory>

// Класс для представления книги с несколькими авторами
// Наследует все поля и методы от Book
class MultiAuthorBook : public Book {
private:
    std::vector<std::shared_ptr<Author>> authors;  // Вектор указателей на авторов

public:
    // Конструктор принимает вектор авторов
    MultiAuthorBook(const std::string& title, const std::vector<std::shared_ptr<Author>>& authors,
                    const std::string& theme, const std::string& publisher, 
                    const std::string& location, int year);
    
    // Конструктор с именами авторов (для обратной совместимости)
    MultiAuthorBook(const std::string& title, const std::vector<std::string>& authorNames,
                    const std::string& theme, const std::string& publisher, 
                    const std::string& location, int year);

    // Реализация чисто виртуального метода из базового класса
    std::vector<std::shared_ptr<Author>> getAuthors() const override;
    
    // Реализация метода для получения имен авторов
    std::vector<std::string> getAuthorNames() const override;
    
    // Переопределение виртуального метода для вывода информации
    void printInfo() const override;
};
