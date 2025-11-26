#include "Book.h"

Book::Book(const std::string& title, const std::vector<std::string>& authors,
           const std::string& topic, const std::string& publisher, const std::string& location)
    : title(title), authors(authors), topic(topic), publisher(publisher), location(location) {}

const std::string& Book::getTitle() const {
    return title;
}

const std::vector<std::string>& Book::getAuthors() const {
    return authors;
}

const std::string& Book::getTopic() const {
    return topic;
}

const std::string& Book::getPublisher() const {
    return publisher;
}

const std::string& Book::getLocation() const {
    return location;
}