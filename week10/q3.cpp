#include <iostream>
#include <cstring>
using namespace std;

struct Book
{
    int book_id;
    char title[50];
    char author[50];
    double price;
};

void printBook(Book b)
{
    cout << b.book_id << " " << b.title << " " << b.author << " " << b.price;
}

int main()
{
    Book b;
    cin >> b.book_id >> b.title >> b.author >> b.price;
    printBook(b);
    return 0;
}
