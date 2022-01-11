"""This program implements Book Management System using Maps"""

book = {}


def insertBook():
    """Inserts a book in dictionary"""
    id = int(input("Enter Book ID: "))
    if id in book:
        print("This book has already been added\n")
        return
    name = input("Enter Book title: ")
    book[id] = name
    print("Book successfully added\n")
    return


def deleteBook():
    """Deletes a book in dictionary by accepting ID or Title of the book as input"""
    flag = not book
    if flag:
        print("No books exist\n\n")
        return
    id = int(input("Enter Book ID to delete: "))

    if id not in book:
        print(f"Book with ID: {id} does not exist or has already been deleted\n")
        return

    book.pop(id)
    print(f"Book with ID: {id} has been deleted successfully\n")
    return


def display():
    """Displays all available books"""
    flag = not book
    if flag:
        print("No book to show\n")
        return

    print("Displaying all books available")
    for key in book:
        print(f"ID: {key} - Title: {book[key]}")
    return


def searchBook():
    """Searches book by either ID or Title"""
    print("How do you want to search?\n"
          "1: Search by Book ID\n"
          "2: Search by Book title\n")
    n = int(input("Enter choice: "))
    if n == 1:
        id = int(input("Enter book ID: "))
        if id in book:
            print(f"\nBook ID: {id} - Title: {book[id]}\n")
            return
    if n == 2:
        name = input("Enter book title: ")
        for key in book:
            if name == book[key]:
                print(f"\nBook ID: {key} - Title: {book[key]}\n")
                return
        print("Book does not exist\n")
        return
    print("Invalid input. Going back to main menu\n")
    return


def main():
    n = 0
    while True:
        print("Menu")
        print("1: Insert a new Book\n"
              "2: Delete a book\n"
              "3: Display all books\n"
              "4: Search a book\n"
              "5: Quit\n")
        n = int(input("Enter your choice: "))
        if n == 1:
            insertBook()
        elif n == 2:
            deleteBook()
        elif n == 3:
            display()
        elif n == 4:
            searchBook()
        elif n == 5:
            print("Exiting...")
            exit(1)
        else:
            print("Incorrect input. Please select correct input from below Menu")


if __name__ == '__main__':
    main()
