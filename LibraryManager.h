#pragma once
#include "Book.h"
#include <vector>
#include <string>

class LibraryManager {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    std::vector<Book> getBooksByTitle(const std::string& title) const;
    std::vector<Book> getBooksByAuthor(const std::string& author) const;
    std::vector<Book> getBooksByTopic(const std::string& topic) const;
    std::vector<Book> getBooksByPublisher(const std::string& publisher) const;
    std::string getLocationByTitle(const std::string& title) const;
};