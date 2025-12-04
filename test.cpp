#include <gtest/gtest.h>
#include "Library.h"

// Тесты для класса Author
TEST(AuthorTest, ConstructorAndGetters) {
    Author author(1, "Test Author", "Test Biography");
    
    EXPECT_EQ(author.getId(), 1);
    EXPECT_EQ(author.getName(), "Test Author");
    EXPECT_EQ(author.getBiography(), "Test Biography");
}

TEST(AuthorTest, HasName) {
    Author author(1, "Иван Петров");
    
    EXPECT_TRUE(author.hasName("Иван"));
    EXPECT_TRUE(author.hasName("Петров"));
    EXPECT_TRUE(author.hasName("ван Пет"));
    EXPECT_FALSE(author.hasName("Сидоров"));
}

// Тесты для класса AuthorBook
TEST(AuthorBookTest, ConstructorAndGetters) {
    auto author = std::make_shared<Author>(1, "Test Author");
    AuthorBook book("Test Book", author, "Test Theme", "Test Publisher", "Test Location", 2023);
    
    EXPECT_EQ(book.getTitle(), "Test Book");
    EXPECT_EQ(book.getAuthor()->getId(), 1);
    EXPECT_EQ(book.getAuthors().size(), 1);
    EXPECT_EQ(book.getAuthorNames()[0], "Test Author");
    EXPECT_EQ(book.getTheme(), "Test Theme");
    EXPECT_EQ(book.getPublisher(), "Test Publisher");
    EXPECT_EQ(book.getLocation(), "Test Location");
    EXPECT_EQ(book.getYear(), 2023);
}

// Тесты для класса MultiAuthorBook
TEST(MultiAuthorBookTest, ConstructorAndGetters) {
    auto author1 = std::make_shared<Author>(1, "Author 1");
    auto author2 = std::make_shared<Author>(2, "Author 2");
    std::vector<std::shared_ptr<Author>> authors = {author1, author2};
    
    MultiAuthorBook book("Test Book", authors, "Test Theme", "Test Publisher", "Test Location", 2023);
    
    EXPECT_EQ(book.getTitle(), "Test Book");
    EXPECT_EQ(book.getAuthors().size(), 2);
    EXPECT_EQ(book.getAuthorNames().size(), 2);
    EXPECT_EQ(book.getAuthorNames()[0], "Author 1");
    EXPECT_EQ(book.getAuthorNames()[1], "Author 2");
}

// Тесты для класса Library
TEST(LibraryTest, AddAndFindAuthor) {
    Library library;
    
    auto author1 = library.addAuthor("Author 1");
    auto author2 = library.addAuthor("Author 2", "Biography 2");
    
    EXPECT_EQ(author1->getId(), 1);
    EXPECT_EQ(author2->getId(), 2);
    EXPECT_EQ(author1->getName(), "Author 1");
    EXPECT_EQ(author2->getName(), "Author 2");
    EXPECT_EQ(author2->getBiography(), "Biography 2");
}

TEST(LibraryTest, AddAndFindBooks) {
    Library library;
    
    // Создаем авторов
    auto author1 = library.addAuthor("Author 1");
    auto author2 = library.addAuthor("Author 2");
    
    // Создаем книгу с одним автором
    library.addAuthorBook("Book 1", author1->getId(),
                         "Theme 1", "Publisher 1", "Location 1", 2000);
    
    // Создаем книгу с несколькими авторами
    library.addMultiAuthorBook("Book 2", {author1->getId(), author2->getId()},
                              "Theme 2", "Publisher 2", "Location 2", 2001);
    
    // Проверяем поиск по наз
