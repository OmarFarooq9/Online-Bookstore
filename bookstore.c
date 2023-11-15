#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char id[20];
    char name[100];
    char author[100];
};

struct Library {
    struct Book books[MAX_BOOKS];
    int numBooks;
};

void displayMenu() {
    printf("\nLibrary Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search for a Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void addBook(struct Library *library) {
    if (library->numBooks < MAX_BOOKS) {
        printf("\nEnter Book ID: ");
        scanf("%s", library->books[library->numBooks].id);

        // Check if the book with the same ID already exists
        for (int i = 0; i < library->numBooks; i++) {
            if (strcmp(library->books[i].id, library->books[library->numBooks].id) == 0) {
                printf("A book with the same ID already exists. Please enter a unique ID.\n");
                return;
            }
        }

        printf("Enter Book Name: ");
        scanf(" %[^\n]s", library->books[library->numBooks].name);

        printf("Enter Author Name: ");
        scanf(" %[^\n]s", library->books[library->numBooks].author);

        printf("\nBook added successfully!\n");
        library->numBooks++;
    } else {
        printf("\nMaximum number of books reached!\n");
    }
}

void displayBooks(struct Library *library) {
    printf("\nList of Books:\n");
    printf("%-20s%-30s%-30s\n", "Book ID", "Book", "Author");
    printf("-------------------------------------------------------------\n");

    for (int i = 0; i < library->numBooks; i++) {
        printf("%-20s%-30s%-30s\n", library->books[i].id, library->books[i].name, library->books[i].author);
    }
}

void searchBook(struct Library *library) {
    char searchID[20];
    printf("Enter Book ID to search: ");
    scanf("%s", searchID);

    for (int i = 0; i < library->numBooks; i++) {
        if (strcmp(searchID, library->books[i].id) == 0) {
            printf("\nBook Found!\n");
            printf("%-20s%-30s%-30s\n", "Book ID", "Book", "Author");
            printf("-------------------------------------------------------------\n");
            printf("%-20s%-30s%-30s\n", library->books[i].id, library->books[i].name, library->books[i].author);
            return;
        }
    }

    printf("\nBook not found!\n");
}

void deleteBook(struct Library *library) {
    char deleteID[20];
    printf("Enter Book ID to delete: ");
    scanf("%s", deleteID);

    for (int i = 0; i < library->numBooks; i++) {
        if (strcmp(deleteID, library->books[i].id) == 0) {
            for (int j = i; j < library->numBooks - 1; j++) {
                // Move the remaining books to fill the gap
                strcpy(library->books[j].id, library->books[j + 1].id);
                strcpy(library->books[j].name, library->books[j + 1].name);
                strcpy(library->books[j].author, library->books[j + 1].author);
            }

            printf("\nBook deleted successfully!\n");
            library->numBooks--;
            return;
        }
    }

    printf("\nBook not found!\n");
}

int main() {
    struct Library library;
    library.numBooks = 0;

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(&library);
                break;
            case 2:
                displayBooks(&library);
                break;
            case 3:
                searchBook(&library);
                break;
            case 4:
                deleteBook(&library);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
