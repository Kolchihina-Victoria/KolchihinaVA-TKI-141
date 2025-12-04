#pragma once
// Book.h - Заголовочный файл базового класса Book
// Назначение: Определяет интерфейс базового класса для всех книг в библиотеке

#include <string>
#include <memory>
#include <vector>
#include "Author.h"  // Добавляем заголовок Author

// Базовый абстрактный класс для всех типов книг
class Book {
protected:
    std::string title;      // Название книги
    std::string theme;      // Тематика/жанр
    std::string publisher;  // Издательство
    std::string location;   // Местонахождение в библиотеке
    int year;               // Год издания

public:
    // Конструктор с параметрами для инициализации всех полей
    Book(const std::string& title, const std::string& theme, 
         const std::string& publisher, const std::string& location, int year);

    // Виртуальный деструктор для правильного удаления наследников
    virtual ~Book() = default;

    // Геттеры для доступа к полям
    std::string getTitle() const;
    std::string getTheme() const;
    std::string getPublisher() const;
    std::string getLocation() const;
    int getYear() const;

    // Виртуальный метод для вывода информации о книге
    virtual void printInfo() const;

    // Чисто виртуальный метод для получения авторов
    virtual std::vector<std::shared_ptr<Author>> getAuthors() const = 0;
    
    // Метод для получения имен авторов (для обратной совместимости)
    virtual std::vector<std::string> getAuthorNames() const = 0;
};
