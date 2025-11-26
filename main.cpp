#include <iostream>
#include <vector>
#include "Book.h"
#include "LibraryManager.h"

int main() {
    LibraryManager lib;

    // Добавляем книги
    lib.addBook(Book("C++ Primer", {"Stanley Lippman", "Josée Lajoie", "Barbara Moo"},
                     "Programming", "Addison-Wesley", "A1"));
    lib.addBook(Book("Effective C++", {"Scott Meyers"}, "Programming", "Addison-Wesley", "B2"));

    // Создаём коллекцию базового типа
    std::vector<Book> books = {
        Book("Modern C++", {"Scott Meyers"}, "Programming", "O'Reilly", "C3"),
        Book("Clean Code", {"Robert Martin"}, "Software Design", "Prentice Hall", "D4")
    };

    // Итерируем коллекцию
    for (const auto& book : books) {
        std::cout << "Title: " << book.getTitle() << ", Location: " << book.getLocation() << "\n";
    }

    return 0;
}