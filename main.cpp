#include <iostream>
#include "inventory.h"

int main() {
    Inventory inventory;
    int choice;
    std::string title, author, ISBN;
    int quantity;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Book" << std::endl;
        std::cout << "2. Display Inventory" << std::endl;
        std::cout << "3. Search Book" << std::endl;
        std::cout << "4. Update Book Quantity" << std::endl;
        std::cout << "5. Remove Book" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1:
                std::cout << "Enter title, author, ISBN, and quantity: ";
                std::cin >> title >> author >> ISBN >> quantity;
                inventory.addBook(Book{title, author, ISBN, quantity});
                break;
            case 2:
                inventory.displayInventory();
                break;
            case 3:
                std::cout << "Enter the title to search: ";
                std::cin >> title;
                inventory.searchBook(title);
                break;
            case 4:
                std::cout << "Enter the ISBN and new quantity: ";
                std::cin >> ISBN >> quantity;
                inventory.updateBook(ISBN, quantity);
                break;
            case 5:
                std::cout << "Enter the ISBN to remove: ";
                std::cin >> ISBN;
                inventory.removeBook(ISBN);
                break;
            case 6:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number from 1 to 6." << std::endl;
        }
    } while (choice != 6);

    return 0;
}
