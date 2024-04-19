#include "inventory.h"
#include <iostream>
#include <algorithm>

void Inventory::addBook(const Book& book) {
    books.push_back(book);
}

void Inventory::displayInventory() {
    for (size_t i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        std::cout << "ISBN: " << book.ISBN << std::endl;
        std::cout << "Quantity: " << book.quantity << std::endl << std::endl;
    }
}

void Inventory::searchBook(const std::string& title) {
    bool found = false;
    for (size_t i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        if (book.title == title) {
            std::cout << "Book found:" << std::endl;
            std::cout << "Title: " << book.title << std::endl;
            std::cout << "Author: " << book.author << std::endl;
            std::cout << "ISBN: " << book.ISBN << std::endl;
            std::cout << "Quantity: " << book.quantity << std::endl << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Book not found." << std::endl << std::endl;
    }
}

void Inventory::updateBook(const std::string& ISBN, int newQuantity) {
    for (size_t i = 0; i < books.size(); ++i) {
        Book& book = books[i];
        if (book.ISBN == ISBN) {
            book.quantity = newQuantity;
            std::cout << "Quantity updated successfully." << std::endl << std::endl;
            return;
        }
    }
    std::cout << "Book with ISBN " << ISBN << " not found." << std::endl << std::endl;
}

void Inventory::removeBook(const std::string& ISBN) {
    for (size_t i = 0; i < books.size(); ++i) {
        Book& book = books[i];
        if (book.ISBN == ISBN) {
            books.erase(books.begin() + i);
            std::cout << "Book removed successfully." << std::endl << std::endl;
            return;
        }
    }
    std::cout << "Book with ISBN " << ISBN << " not found." << std::endl << std::endl;
}
