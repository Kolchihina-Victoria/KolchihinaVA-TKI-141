#include "LibraryManager.h"
#include <algorithm>

void LibraryManager::addBook(const Book& book) {
    books.push_back(book);
}

std::vector<Book> LibraryManager::getBooksByTitle(const std::string& title) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> LibraryManager::getBooksByAuthor(const std::string& author) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (std::find(book.getAuthors().begin(), book.getAuthors().end(), author) != book.getAuthors().end()) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> LibraryManager::getBooksByTopic(const std::string& topic) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getTopic() == topic) {
            result.push_back(book);
        }
    }
    return result;
}

std::vector<Book> LibraryManager::getBooksByPublisher(const std::string& publisher) const {
    std::vector<Book> result;
    for (const auto& book : books) {
        if (book.getPublisher() == publisher) {
            result.push_back(book);
        }
    }
    return result;
}

std::string LibraryManager::getLocationByTitle(const std::string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            return book.getLocation();
        }
    }
    return "";
}