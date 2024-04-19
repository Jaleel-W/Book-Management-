#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    int quantity;
};

#endif // BOOK_H
