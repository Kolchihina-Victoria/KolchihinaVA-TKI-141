#pragma once
// Author.h - Заголовочный файл класса Author
// Назначение: Определяет класс автора с уникальным идентификатором

#include <string>
#include <memory>
#include <iostream>

class Author {
private:
    int id;                // Уникальный идентификатор автора
    std::string name;      // Имя автора
    std::string biography; // Биография (опционально)

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
    
    // Метод вывода информации
    void printInfo() const;
    
    // Оператор сравнения для использования в контейнерах
    bool operator==(const Author& other) const;
    
    // Метод для сравнения по имени (частичное совпадение)
    bool hasName(const std::string& name) const;
};