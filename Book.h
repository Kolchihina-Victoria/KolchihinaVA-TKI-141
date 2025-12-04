#pragma once
// Book.h - Заголовочный файл базового класса Book
// Назначение: Определяет интерфейс базового класса для всех книг в библиотеке
// Содержит: Объявление абстрактного класса Book с чисто виртуальными методами
// Зависимости: Стандартные библиотеки string, memory, vector

#include <string>
#include <memory>
#include <vector>

// Базовый абстрактный класс для всех типов книг
// Наследники: AuthorBook (книга с одним автором), MultiAuthorBook (книга с несколькими авторами)
class Book {
protected:
    // Защищенные поля, доступные наследникам
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
    
    // Геттеры для доступа к полям (инкапсуляция)
    std::string getTitle() const;
    std::string getTheme() const;
    std::string getPublisher() const;
    std::string getLocation() const;
    int getYear() const;
    
    // Виртуальный метод для вывода информации о книге
    // Может быть переопределен наследниками для добавления специфичной информации
    virtual void printInfo() const;
    
    // Чисто виртуальный метод (абстрактный)
    // Наследники ОБЯЗАНЫ реализовать этот метод
    // Возвращает список авторов книги
    virtual std::vector<std::string> getAuthors() const = 0;
};