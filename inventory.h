#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "book.h"

class Inventory {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void displayInventory();
    void searchBook(const std::string& title);
    void updateBook(const std::string& ISBN, int newQuantity);
    void removeBook(const std::string& ISBN);
};

#endif // INVENTORY_H
