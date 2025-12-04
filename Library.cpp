//  Содержит определения методов управления библиотекой
#include "Library.h"
#include <algorithm>  // Для std::find
#include <iostream>

// Добавляет книгу в коллекцию библиотеки
void Library::addBook(const std::shared_ptr<Book>& book) {
    books.push_back(book);  // Просто добавляем в конец вектора
}

// Поиск книг по точному названию
std::vector<std::shared_ptr<Book>> Library::findBooksByTitle(const std::string& title) const {
    std::vector<std::shared_ptr<Book>> result;  // Вектор для результатов
    
    // Простой линейный поиск по всем книгам
    for (const auto& book : books) {
        if (book->getTitle() == title) {  // Сравниваем названия
            result.push_back(book);       // Добавляем в результат
        }
    }
    return result;
}

// Поиск книг по автору (учитывает соавторство)
std::vector<std::shared_ptr<Book>> Library::findBooksByAuthor(const std::string& author) const {
    std::vector<std::shared_ptr<Book>> result;
    
    for (const auto& book : books) {
        // Получаем список авторов книги (работает для обоих типов книг)
        auto authors = book->getAuthors();
        
        // Ищем автора в списке авторов книги
        if (std::find(authors.begin(), authors.end(), author) != authors.end()) {
            result.push_back(book);
        }
    }
    return result;
}

// Поиск книг по тематике
std::vector<std::shared_ptr<Book>> Library::findBooksByTheme(const std::string& theme) const {
    std::vector<std::shared_ptr<Book>> result;
    
    for (const auto& book : books) {
        if (book->getTheme() == theme) {
            result.push_back(book);
        }
    }
    return result;
}

// Поиск книг по издательству
std::vector<std::shared_ptr<Book>> Library::findBooksByPublisher(const std::string& publisher) const {
    std::vector<std::shared_ptr<Book>> result;
    
    for (const auto& book : books) {
        if (book->getPublisher() == publisher) {
            result.push_back(book);
        }
    }
    return result;
}

// Поиск местоположения книги по названию
// Возвращает строку с местоположением или сообщение об ошибке
std::string Library::findBookLocation(const std::string& title) const {
    for (const auto& book : books) {
        if (book->getTitle() == title) {
            return book->getLocation();  // Нашли - возвращаем местоположение
        }
    }
    return "Книга не найдена";  // Не нашли - возвращаем сообщение
}

// Возвращает константную ссылку на все книги
// Эффективно, так как не создает копию вектора
const std::vector<std::shared_ptr<Book>>& Library::getAllBooks() const {
    return books;
}
