#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "book.h"

class Inventory {
private:
    std::vector<Book> books;

public:
    bool addBook(const Book& book);  // Changed to bool return
    void displayInventory();
    void searchBook(const std::string& title);
    void updateBook(const std::string& ISBN, int newQuantity);
    bool removeBook(const std::string& ISBN);  // Changed to bool return
};

#endif // INVENTORY_H
