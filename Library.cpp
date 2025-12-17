#include "Library.h"
#include <algorithm>
#include <iostream>

// Конструктор
Library::Library() : nextAuthorId(1) {}

//  Методы работы с авторами 

// Добавление нового автора с именем
std::shared_ptr<Author> Library::addAuthor(const std::string& name) {
    auto author = std::make_shared<Author>(nextAuthorId, name);
    authors[nextAuthorId] = author;
    nextAuthorId++;
    return author;
}

// Добавление нового автора с именем и биографией
std::shared_ptr<Author> Library::addAuthor(const std::string& name, const std::string& biography) {
    auto author = std::make_shared<Author>(nextAuthorId, name, biography);
    authors[nextAuthorId] = author;
    nextAuthorId++;
    return author;
}

// Поиск автора по ID
std::shared_ptr<Author> Library::findAuthorById(int id) const {
    auto it = authors.find(id);
    if (it != authors.end()) {
        return it->second;
    }
    return nullptr;
}

// Поиск автора по имени
std::vector<std::shared_ptr<Author>> Library::findAuthorsByName(const std::string& name) const {
    std::vector<std::shared_ptr<Author>> result;
    for (const auto& pair : authors) {
        if (pair.second->hasName(name)) {
            result.push_back(pair.second);
        }
    }
    return result;
}

// Получение всех авторов
std::vector<std::shared_ptr<Author>> Library::getAllAuthors() const {
    std::vector<std::shared_ptr<Author>> result;
    for (const auto& pair : authors) {
        result.push_back(pair.second);
    }
    return result;
}

// Методы работы с книгами 

// Добавление книги с одним автором
void Library::addAuthorBook(const std::shared_ptr<AuthorBook>& book) {
    authorBooks.push_back(book);
    // Связываем книгу с автором
    auto author = book->getAuthor();
    if (author) {
        author->addBook(book);
    }
}

// Добавление книги с несколькими авторами
void Library::addMultiAuthorBook(const std::shared_ptr<MultiAuthorBook>& book) {
    multiAuthorBooks.push_back(book);
    // Связываем книгу со всеми авторами
    auto authors = book->getAuthors();
    for (const auto& author : authors) {
        author->addBook(book);
    }
}

// Создание и добавление книги с одним автором
void Library::addAuthorBook(const std::string& title, int authorId,
                           const std::string& theme, const std::string& publisher,
                           const std::string& location, int year) {
    auto author = findAuthorById(authorId);
    if (!author) {
        std::cerr << "Ошибка: автор с ID " << authorId << " не найден!" << std::endl;
        return;
    }

    auto book = std::make_shared<AuthorBook>(title, author, theme, publisher, location, year);
    authorBooks.push_back(book);
    // Связываем книгу с автором
    author->addBook(book);
}

// Создание и добавление книги с несколькими авторами
void Library::addMultiAuthorBook(const std::string& title, const std::vector<int>& authorIds,
                                const std::string& theme, const std::string& publisher,
                                const std::string& location, int year) {
    std::vector<std::shared_ptr<Author>> authorsVec;

    for (int id : authorIds) {
        auto author = findAuthorById(id);
        if (!author) {
            std::cerr << "Ошибка: автор с ID " << id << " не найден!" << std::endl;
            return;
        }
        authorsVec.push_back(author);
    }

    if (authorsVec.empty()) {
        std::cerr << "Ошибка: не указаны авторы!" << std::endl;
        return;
    }

    auto book = std::make_shared<MultiAuthorBook>(title, authorsVec, theme, publisher, location, year);
    multiAuthorBooks.push_back(book);
    // Связываем книгу со всеми авторами
    for (const auto& author : authorsVec) {
        author->addBook(book);
    }
}

// === Методы поиска книг ===

// Поиск книг по точному названию
std::vector<std::shared_ptr<Book>> Library::findBooksByTitle(const std::string& title) const {
    std::vector<std::shared_ptr<Book>> result;

    // Ищем в книгах с одним автором
    for (const auto& book : authorBooks) {
        if (book->getTitle() == title) {
            result.push_back(book);
        }
    }

    // Ищем в книгах с несколькими авторами
    for (const auto& book : multiAuthorBooks) {
        if (book->getTitle() == title) {
            result.push_back(book);
        }
    }

    return result;
}

// Поиск книг по автору (по ID)
std::vector<std::shared_ptr<Book>> Library::findBooksByAuthor(int authorId) const {
    std::vector<std::shared_ptr<Book>> result;

    // Ищем в книгах с одним автором
    for (const auto& book : authorBooks) {
        auto authors = book->getAuthors();
        for (const auto& author : authors) {
            if (author->getId() == authorId) {
                result.push_back(book);
                break;
            }
        }
    }

    // Ищем в книгах с несколькими авторами
    for (const auto& book : multiAuthorBooks) {
        auto authors = book->getAuthors();
        for (const auto& author : authors) {
            if (author->getId() == authorId) {
                result.push_back(book);
                break;
            }
        }
    }

    return result;
}

// Поиск книг по имени автора
std::vector<std::shared_ptr<Book>> Library::findBooksByAuthorName(const std::string& authorName) const {
    std::vector<std::shared_ptr<Book>> result;

    // Ищем в книгах с одним автором
    for (const auto& book : authorBooks) {
        auto authors = book->getAuthors();
        for (const auto& author : authors) {
            if (author->hasName(authorName)) {
                result.push_back(book);
                break;
            }
        }
    }

    // Ищем в книгах с несколькими авторами
    for (const auto& book : multiAuthorBooks) {
        auto authors = book->getAuthors();
        for (const auto& author : authors) {
            if (author->hasName(authorName)) {
                result.push_back(book);
                break;
            }
        }
    }

    return result;
}

// Поиск книг по тематике
std::vector<std::shared_ptr<Book>> Library::findBooksByTheme(const std::string& theme) const {
    std::vector<std::shared_ptr<Book>> result;

    for (const auto& book : authorBooks) {
        if (book->getTheme() == theme) {
            result.push_back(book);
        }
    }

    for (const auto& book : multiAuthorBooks) {
        if (book->getTheme() == theme) {
            result.push_back(book);
        }
    }

    return result;
}

// Поиск книг по издательству
std::vector<std::shared_ptr<Book>> Library::findBooksByPublisher(const std::string& publisher) const {
    std::vector<std::shared_ptr<Book>> result;

    for (const auto& book : authorBooks) {
        if (book->getPublisher() == publisher) {
            result.push_back(book);
        }
    }

    for (const auto& book : multiAuthorBooks) {
        if (book->getPublisher() == publisher) {
            result.push_back(book);
        }
    }

    return result;
}

// Поиск местоположения книги
std::string Library::findBookLocation(const std::string& title) const {
    for (const auto& book : authorBooks) {
        if (book->getTitle() == title) {
            return book->getLocation();
        }
    }

    for (const auto& book : multiAuthorBooks) {
        if (book->getTitle() == title) {
            return book->getLocation();
        }
    }

    return "Книга не найдена";
}

// Получение всех книг как базового типа
std::vector<std::shared_ptr<Book>> Library::getAllBooks() const {
    std::vector<std::shared_ptr<Book>> allBooks;

    // Добавляем книги с одним автором
    for (const auto& book : authorBooks) {
        allBooks.push_back(book);
    }

    // Добавляем книги с несколькими авторами
    for (const auto& book : multiAuthorBooks) {
        allBooks.push_back(book);
    }

    return allBooks;
}

// Получение всех книг с одним автором
const std::vector<std::shared_ptr<AuthorBook>>& Library::getAllAuthorBooks() const {
    return authorBooks;
}

// Получение всех книг с несколькими авторами
const std::vector<std::shared_ptr<MultiAuthorBook>>& Library::getAllMultiAuthorBooks() const {
    return multiAuthorBooks;
}
