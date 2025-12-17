#include "Author.h"
#include "Book.h"  // Теперь включаем заголовок Book

// Конструктор с именем
Author::Author(int id, const std::string& name)
    : id(id), name(name), biography("") {}

// Конструктор с именем и биографией
Author::Author(int id, const std::string& name, const std::string& biography)
    : id(id), name(name), biography(biography) {}

// Геттеры
int Author::getId() const { return id; }
std::string Author::getName() const { return name; }
std::string Author::getBiography() const { return biography; }

// Сеттер для биографии
void Author::setBiography(const std::string& biography) {
    this->biography = biography;
}

// Метод для добавления книги автору
void Author::addBook(const std::shared_ptr<Book>& book) {
    books.push_back(book);
}

// Метод для получения всех книг автора
std::vector<std::shared_ptr<Book>> Author::getBooks() const {
    return books;
}

// Проверка, есть ли у автора книги
bool Author::hasBooks() const {
    return !books.empty();
}

// Метод для вывода всех книг автора
void Author::printAllBooks() const {
    std::cout << "Книги автора " << name << ":" << std::endl;
    if (books.empty()) {
        std::cout << "  (нет книг)" << std::endl;
    } else {
        for (const auto& book : books) {
            std::cout << "  - " << book->getTitle() << " (" << book->getYear() << ")" << std::endl;
        }
    }
    std::cout << "-------------------" << std::endl;
}

// Метод вывода информации
void Author::printInfo() const {
    std::cout << "ID автора: " << id << std::endl;
    std::cout << "Имя: " << name << std::endl;
    if (!biography.empty()) {
        std::cout << "Биография: " << biography << std::endl;
    }
    if (!books.empty()) {
        std::cout << "Количество книг: " << books.size() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
}

// Оператор сравнения
bool Author::operator==(const Author& other) const {
    return id == other.id;  // Сравниваем по уникальному ID
}

// Метод для сравнения по имени
bool Author::hasName(const std::string& name) const {
    return this->name.find(name) != std::string::npos;
}
