#include <iostream>
#include <memory>
#include <vector>
#include "Library.h"

int main() {
    setlocale(LC_ALL, "Russian");
    
    //  СОЗДАНИЕ БИБЛИОТЕКИ 
    Library library;
    
    //  СОЗДАНИЕ АВТОРОВ 
    auto author1 = library.addAuthor("Михаил Булгаков", "Русский писатель, драматург");
    auto author2 = library.addAuthor("Федор Достоевский", "Русский писатель, мыслитель");
    auto author3 = library.addAuthor("Иван Петров");
    auto author4 = library.addAuthor("Анна Сидорова");
    auto author5 = library.addAuthor("Петр Иванов");
    auto author6 = library.addAuthor("Томас Кормен", "Американский ученый в области информатики");
    auto author7 = library.addAuthor("Александр Эйнштейн", "Физик-теоретик, Нобелевский лауреат");
    auto author8 = library.addAuthor("Никола Тесла", "Изобретатель в области электротехники");
    
    // СОЗДАНИЕ И ДОБАВЛЕНИЕ КНИГ 
    
    // Книга с одним автором (через метод библиотеки)
    library.addAuthorBook("Мастер и Маргарита", author1->getId(),
                         "Роман", "Эксмо", "Стеллаж 1, Полка 3", 1967);
    
    // Книга с одним автором (через метод библиотеки)
    library.addAuthorBook("Преступление и наказание", author2->getId(),
                         "Роман", "АСТ", "Стеллаж 2, Полка 1", 1866);
    
    // Книга с несколькими авторами (через метод библиотеки)
    library.addMultiAuthorBook("C++ для начинающих", 
                              {author3->getId(), author4->getId(), author5->getId()},
                              "Программирование", "Питер", "Стеллаж 3, Полка 2", 2021);
    
    // Книга с одним автором (создание напрямую и добавление)
    auto book4 = std::make_shared<AuthorBook>(
        "Алгоритмы и структуры данных", author6,
        "Программирование", "Вильямс", "Стеллаж 3, Полка 1", 2009);
    library.addAuthorBook(book4);
    
    // Книга с несколькими авторами (создание напрямую и добавление)
    auto book5 = std::make_shared<MultiAuthorBook>(
        "Физика для всех", 
        {author7, author8},
        "Наука", "Наука", "Стеллаж 4, Полка 1", 2018);
    library.addMultiAuthorBook(book5);
    
    // ДЕМОНСТРАЦИЯ РАБОТЫ БИБЛИОТЕКИ 
    
    std::cout << "Все авторы в библиотеке " << std::endl;
    for (const auto& author : library.getAllAuthors()) {
        author->printInfo();
    }
    
    std::cout << "\n Все книги в библиотеке ===" << std::endl;
    for (const auto& book : library.getAllBooks()) {
        book->printInfo();
    }
    
    // ДЕМОНСТРАЦИЯ ПОИСКА 
    
    std::cout << "\n Поиск книг по названию 'Мастер и Маргарита' " << std::endl;
    auto booksByTitle = library.findBooksByTitle("Мастер и Маргарита");
    for (const auto& book : booksByTitle) {
        book->printInfo();
    }
    
    std::cout << "\n=== Поиск книг автора 'Томас Кормен' (по имени) ===" << std::endl;
    auto booksByAuthorName = library.findBooksByAuthorName("Кормен");
    for (const auto& book : booksByAuthorName) {
        book->printInfo();
    }
    
    std::cout << "\n=== Все книги автора с ID " << author6->getId() << " ===" << std::endl;
    auto booksByAuthorId = library.findBooksByAuthor(author6->getId());
    for (const auto& book : booksByAuthorId) {
        book->printInfo();
    }
    
    std::cout << "\n Поиск книг по тематике 'Программирование' " << std::endl;
    auto booksByTheme = library.findBooksByTheme("Программирование");
    for (const auto& book : booksByTheme) {
        book->printInfo();
    }
    
    std::cout << "\n Поиск книг издательства 'Питер' " << std::endl;
    auto booksByPublisher = library.findBooksByPublisher("Питер");
    for (const auto& book : booksByPublisher) {
        book->printInfo();
    }
    
    std::cout << "\n=== Поиск авторов по имени 'Петр' ===" << std::endl;
    auto foundAuthors = library.findAuthorsByName("Петр");
    for (const auto& author : foundAuthors) {
        author->printInfo();
    }
    
    std::cout << "\n Местонахождение книги 'Алгоритмы и структуры данных' " << std::endl;
    std::cout << library.findBookLocation("Алгоритмы и структуры данных") << std::endl;
    
    // ДЕМОНСТРАЦИЯ РАЗНЫХ ТИПОВ КНИГ 
    
    std::cout << "\n Книги с одним автором " << std::endl;
    for (const auto& book : library.getAllAuthorBooks()) {
        book->printInfo();
    }
    
    std::cout << "\n Книги с несколькими авторами " << std::endl;
    for (const auto& book : library.getAllMultiAuthorBooks()) {
        book->printInfo();
    }
    
    return 0;
}
