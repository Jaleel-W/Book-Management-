#include "inventory.h"
#include <iostream>
#include <algorithm>
#include <limits>

bool Inventory::addBook(const Book& book) {
    // Check for duplicate ISBN
    for (const auto& b : books) {
        if (b.ISBN == book.ISBN) {
            std::cout << "\nError: Book with ISBN " << book.ISBN 
                      << " already exists!\n" << std::endl;
            return false;
        }
    }
    books.push_back(book);
    return true;
}

void Inventory::displayInventory() {
    if (books.empty()) {
        std::cout << "\nInventory is empty.\n" << std::endl;
        return;
    }
    
    std::cout << "\n===== INVENTORY =====\n";
    for (size_t i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        std::cout << "Entry #" << i+1 << ":\n";
        std::cout << "  Title:    " << book.title << "\n";
        std::cout << "  Author:   " << book.author << "\n";
        std::cout << "  ISBN:     " << book.ISBN << "\n";
        std::cout << "  Quantity: " << book.quantity << "\n\n";
    }
    std::cout << "====================\n" << std::endl;
}

void Inventory::searchBook(const std::string& title) {
    bool found = false;
    std::cout << "\nSearch Results:\n";
    
    for (size_t i = 0; i < books.size(); ++i) {
        const Book& book = books[i];
        if (book.title.find(title) != std::string::npos) {
            std::cout << "Entry #" << i+1 << ":\n";
            std::cout << "  Title:    " << book.title << "\n";
            std::cout << "  Author:   " << book.author << "\n";
            std::cout << "  ISBN:     " << book.ISBN << "\n";
            std::cout << "  Quantity: " << book.quantity << "\n\n";
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "No books found matching '" << title << "'\n";
    }
    std::cout << "====================\n" << std::endl;
}

void Inventory::updateBook(const std::string& ISBN, int newQuantity) {
    for (auto& book : books) {
        if (book.ISBN == ISBN) {
            book.quantity = newQuantity;
            std::cout << "\nQuantity updated successfully for ISBN " 
                      << ISBN << "\n" << std::endl;
            return;
        }
    }
    std::cout << "\nError: Book with ISBN " << ISBN 
              << " not found!\n" << std::endl;
}

bool Inventory::removeBook(const std::string& ISBN) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->ISBN == ISBN) {
            books.erase(it);
            return true;
        }
    }
    return false;
}
