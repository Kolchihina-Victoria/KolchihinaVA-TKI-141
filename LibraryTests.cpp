#include "LibraryManager.h"
#include "Book.h"
#include <cassert>

void testGetBooksByTitle() {
    LibraryManager lib;
    lib.addBook(Book("C++ Primer", {"Lippman"}, "Programming", "AW", "A1"));

    auto result = lib.getBooksByTitle("C++ Primer");
    assert(result.size() == 1);
    assert(result[0].getLocation() == "A1");
}

void runTests() {
    testGetBooksByTitle();
    // другие тесты...
    std::cout << "All tests passed.\n";
}