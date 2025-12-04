

#include <gtest/gtest.h>
#include "Book.h"
#include "AuthorBook.h"
#include "MultiAuthorBook.h"
#include "Library.h"

// === ТЕСТЫ ДЛЯ КЛАССА AuthorBook ===

// Тест конструктора и геттеров AuthorBook
TEST(AuthorBookTest, ConstructorAndGetters) {
    // Создаем тестовый объект
    AuthorBook book("Test", "Author", "Theme", "Publisher", "Location", 2023);
    
    // Проверяем, что все поля инициализированы правильно
    EXPECT_EQ(book.getTitle(), "Test");
    EXPECT_EQ(book.getAuthor(), "Author");
    EXPECT_EQ(book.getTheme(), "Theme");
    EXPECT_EQ(book.getPublisher(), "Publisher");
    EXPECT_EQ(book.getLocation(), "Location");
    EXPECT_EQ(book.getYear(), 2023);
}

// === ТЕСТЫ ДЛЯ КЛАССА MultiAuthorBook ===

// Тест конструктора и геттеров MultiAuthorBook
TEST(MultiAuthorBookTest, ConstructorAndGetters) {
    // Создаем вектор авторов
    std::vector<std::string> authors = {"Author1", "Author2", "Author3"};
    
    // Создаем тестовый объект
    MultiAuthorBook book("Test", authors, "Theme", "Publisher", "Location", 2023);
    
    // Проверяем базовые поля
    EXPECT_EQ(book.getTitle(), "Test");
    
    // Получаем и проверяем список авторов
    auto bookAuthors = book.getAuthors();
    EXPECT_EQ(bookAuthors.size(), 3);
    EXPECT_EQ(bookAuthors[0], "Author1");
    EXPECT_EQ(bookAuthors[1], "Author2");
    EXPECT_EQ(bookAuthors[2], "Author3");
}

// === ТЕСТЫ ДЛЯ КЛАССА Library ===

// Тест добавления и поиска книг в библиотеке
TEST(LibraryTest, AddAndFindBook) {
    // Создаем библиотеку
    Library library;
    
    // Создаем тестовые книги
    auto book1 = std::make_shared<AuthorBook>("Book1", "Author1", "Theme1", "Pub1", "Loc1", 2000);
    auto book2 = std::make_shared<AuthorBook>("Book2", "Author2", "Theme2", "Pub2", "Loc2", 2001);
    
    // Добавляем книги в библиотеку
    library.addBook(book1);
    library.addBook(book2);
    
    // Тестируем поиск по названию
    auto foundBooks = library.findBooksByTitle("Book1");
    EXPECT_EQ(foundBooks.size(), 1);  // Должна найти одну книгу
    EXPECT_EQ(foundBooks[0]->getTitle(), "Book1");  // Должна быть именно Book1
    
    // Тестируем поиск по автору
    auto authorBooks = library.findBooksByAuthor("Author2");
    EXPECT_EQ(authorBooks.size(), 1);  // Должна найти одну книгу
    EXPECT_EQ(authorBooks[0]->getAuthors()[0], "Author2");  // Проверяем автора
}

// === ТОЧКА ВХОДА ДЛЯ ЗАПУСКА ТЕСТОВ ===
int main(int argc, char **argv) {
    // Инициализация Google Test Framework
    ::testing::InitGoogleTest(&argc, argv);
    
    // Запуск всех тестов
    return RUN_ALL_TESTS();
}