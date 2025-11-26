#pragma once
#include <string>
#include <vector>

class Book {
protected:
    std::string title;
    std::vector<std::string> authors;
    std::string topic;
    std::string publisher;
    std::string location;

public:
    Book(const std::string& title, const std::vector<std::string>& authors,
         const std::string& topic, const std::string& publisher, const std::string& location);

    const std::string& getTitle() const;
    const std::vector<std::string>& getAuthors() const;
    const std::string& getTopic() const;
    const std::string& getPublisher() const;
    const std::string& getLocation() const;

    virtual ~Book() = default;
};