#pragma once
// Назначение: Определяет класс для книг с несколькими авторами
// Наследует: Класс Book
// Особенность: Хранит авторов в векторе, поддерживает соавторство

#include "Book.h"
#include <string>
#include <vector>

// Класс для представления книги с несколькими авторами
// Наследует все поля и методы от Book
class MultiAuthorBook : public Book {
private:
    // Поле для хранения нескольких авторов
    std::vector<std::string> authors;  // Вектор авторов
    
public:
    // Конструктор принимает вектор авторов вместо одного автора
    MultiAuthorBook(const std::string& title, const std::vector<std::string>& authors, 
                    const std::string& theme, const std::string& publisher, 
                    const std::string& location, int year);
    
    // Реализация чисто виртуального метода из базового класса
    // Возвращает копию вектора авторов
    std::vector<std::string> getAuthors() const override;
    
    // Переопределение виртуального метода для вывода информации
    // Выводит всех авторов через запятую
    void printInfo() const override;
};
