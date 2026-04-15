#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book b("Les Miserables", "Victor Hugo", "9780743273565");

    cout << "Book Details:" << endl;
    cout << "Title: " << b.getTitle() << endl;
    cout << "Author: " << b.getAuthor() << endl;
    cout << "ISBN: " << b.getISBN() << endl;

    return 0;
}
