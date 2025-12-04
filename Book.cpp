#include "Book.h"
#include <iostream>

// Реализация конструктора с инициализацией полей через список инициализации
Book::Book(const std::string& title, const std::string& theme, 
           const std::string& publisher, const std::string& location, int year)
    : title(title),          // Инициализация названия
      theme(theme),          // Инициализация тематики
      publisher(publisher),  // Инициализация издательства
      location(location),    // Инициализация местоположения
      year(year) {}          // Инициализация года

// Реализация геттеров
std::string Book::getTitle() const { return title; }
std::string Book::getTheme() const { return theme; }
std::string Book::getPublisher() const { return publisher; }
std::string Book::getLocation() const { return location; }
int Book::getYear() const { return year; }

// Реализация метода вывода информации
void Book::printInfo() const {
    std::cout << "Название: " << title << std::endl;
    std::cout << "Тематика: " << theme << std::endl;
    std::cout << "Издательство: " << publisher << std::endl;
    std::cout << "Местонахождение: " << location << std::endl;
    std::cout << "Год издания: " << year << std::endl;
}
