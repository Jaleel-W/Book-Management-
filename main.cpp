#include <iostream>
#include <limits>
#include "inventory.h"

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Inventory inventory;
    int choice;
    std::string input;

    do {
        std::cout << "\n===== BOOK MANAGER =====\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Display Inventory\n";
        std::cout << "3. Search Book\n";
        std::cout << "4. Update Book Quantity\n";
        std::cout << "5. Remove Book\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "\nInvalid input! Please enter a number.\n";
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch(choice) {
            case 1: {
                Book newBook;
                std::cout << "\nEnter title: ";
                std::getline(std::cin, newBook.title);
                
                std::cout << "Enter author: ";
                std::getline(std::cin, newBook.author);
                
                std::cout << "Enter ISBN: ";
                std::getline(std::cin, newBook.ISBN);
                
                while (true) {
                    std::cout << "Enter quantity: ";
                    if (std::cin >> newBook.quantity) {
                        clearInputBuffer();
                        break;
                    }
                    std::cout << "Invalid quantity! ";
                    clearInputBuffer();
                }
                
                if (inventory.addBook(newBook)) {
                    std::cout << "\nBook added successfully!\n";
                }
                break;
            }
            case 2:
                inventory.displayInventory();
                break;
            case 3: {
                std::string title;
                std::cout << "\nEnter title to search: ";
                std::getline(std::cin, title);
                inventory.searchBook(title);
                break;
            }
            case 4: {
                std::string ISBN;
                int newQuantity;
                
                std::cout << "\nEnter ISBN to update: ";
                std::getline(std::cin, ISBN);
                
                while (true) {
                    std::cout << "Enter new quantity: ";
                    if (std::cin >> newQuantity) {
                        clearInputBuffer();
                        break;
                    }
                    std::cout << "Invalid quantity! ";
                    clearInputBuffer();
                }
                
                inventory.updateBook(ISBN, newQuantity);
                break;
            }
            case 5: {
                std::string ISBN;
                std::cout << "\nEnter ISBN to remove: ";
                std::getline(std::cin, ISBN);
                
                if (inventory.removeBook(ISBN)) {
                    std::cout << "\nBook removed successfully!\n";
                } else {
                    std::cout << "\nError: Book not found!\n";
                }
                break;
            }
            case 6:
                std::cout << "\nExiting program.\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please enter 1-6.\n";
        }
    } while (choice != 6);

    return 0;
}
