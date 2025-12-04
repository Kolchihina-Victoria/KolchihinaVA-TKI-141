#include <iostream>
#include <memory>
#include <vector>
#include "Book.h"
#include "AuthorBook.h"
#include "MultiAuthorBook.h"
#include "Library.h"


int main() {
    // Устанавливаем локаль для поддержки русских символов
    setlocale(LC_ALL, "Russian");
    
    // СОЗДАНИЕ БИБЛИОТЕКИ 
    Library library;
    
    // СОЗДАНИЕ РАЗЛИЧНЫХ ТИПОВ КНИГ 
    // Демонстрация создания книги с одним автором
    auto book1 = std::make_shared<AuthorBook>(
        "Мастер и Маргарита", "Михаил Булгаков", 
        "Роман", "Эксмо", "Стеллаж 1, Полка 3", 1967);
    
    auto book2 = std::make_shared<AuthorBook>(
        "Преступление и наказание", "Федор Достоевский", 
        "Роман", "АСТ", "Стеллаж 2, Полка 1", 1866);
    
    // Демонстрация создания книги с несколькими авторами
    auto book3 = std::make_shared<MultiAuthorBook>(
        "C++ для начинающих", 
        std::vector<std::string>{"Иван Петров", "Анна Сидорова", "Петр Иванов"},
        "Программирование", "Питер", "Стеллаж 3, Полка 2", 2021);
    
    auto book4 = std::make_shared<AuthorBook>(
        "Алгоритмы и структуры данных", "Томас Кормен", 
        "Программирование", "Вильямс", "Стеллаж 3, Полка 1", 2009);
    
    auto book5 = std::make_shared<MultiAuthorBook>(
        "Физика для всех", 
        std::vector<std::string>{"Александр Эйнштейн", "Никола Тесла"},
        "Наука", "Наука", "Стеллаж 4, Полка 1", 2018);
    
    // : ДОБАВЛЕНИЕ КНИГ В БИБЛИОТЕКУ 
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book5);
    
    //  ДЕМОНСТРАЦИЯ ПОЛИМОРФИЗМА
    // Итерация по коллекции базового типа Book
    std::cout << "=== Все книги в библиотеке ===" << std::endl;
    for (const auto& book : library.getAllBooks()) {
        // Полиморфный вызов: book->printInfo() вызывает правильную версию метода
        // в зависимости от фактического типа объекта
        book->printInfo();
    }
    
    //  ДЕМОНСТРАЦИЯ ПОИСКА 
    
    // Поиск по названию
    std::cout << "\n=== Поиск книг по названию 'Мастер и Маргарита' ===" << std::endl;
    auto booksByTitle = library.findBooksByTitle("Мастер и Маргарита");
    for (const auto& book : booksByTitle) {
        book->printInfo();
    }
    
    // Поиск по автору
    std::cout << "\n=== Поиск книг автора 'Томас Кормен' ===" << std::endl;
    auto booksByAuthor = library.findBooksByAuthor("Томас Кормен");
    for (const auto& book : booksByAuthor) {
        book->printInfo();
    }
    
    // Поиск по тематике
    std::cout << "\n=== Поиск книг по тематике 'Программирование' ===" << std::endl;
    auto booksByTheme = library.findBooksByTheme("Программирование");
    for (const auto& book : booksByTheme) {
        book->printInfo();
    }
    
    // Поиск по издательству
    std::cout << "\n=== Поиск книг издательства 'Питер' ===" << std::endl;
    auto booksByPublisher = library.findBooksByPublisher("Питер");
    for (const auto& book : booksByPublisher) {
        book->printInfo();
    }
    
    // Поиск местоположения
    std::cout << "\n=== Местонахождение книги 'Алгоритмы и структуры данных' ===" << std::endl;
    std::cout << library.findBookLocation("Алгоритмы и структуры данных") << std::endl;
    
    return 0;  // Успешное завершение программы
}