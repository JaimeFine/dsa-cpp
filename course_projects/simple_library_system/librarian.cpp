#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

void clear_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

struct Book {
    int id;
    char title[50];
    char author[30];
    double price;
    char date[20];
    bool deleted;

    int compare_author(const Book& other) const {
        int res = strcmp(this->author, other.author);
        if (res < 0)
            return -1;  // Before
        if (res > 0)
            return 1;   // After
        return 0;
    }
};

struct Index {
    int id;
    long position;
};

void print_books_help(const char* str, int width) {
    int len = strlen(str);
    cout << str;
    for (int i = 0; i < width - len; ++i)
        cout << " ";
}

void print_books(int val, int width) {
    string s = to_string(val);
    print_books_help(s.c_str(), width);
}

class BookManager {
protected:
    string file;
    vector<Index> id;

    void index() {
        id.clear();
        ifstream resource(file, ios::binary);

        Book book;
        while (resource.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            if (!book.deleted) {
                Index item;
                item.id = book.id;
                item.position = (long)resource.tellg() - (long)sizeof(Book);
                id.push_back(item);
            }
        }
        resource.close();
    }

public:
    BookManager(string filename) : file(filename) {
        index();
    }

    void insert_book() {
        Book book;
        cout << "Input the book ID: "; cin >> book.id;
        clear_input();

        for (size_t i = 0; i < id.size(); ++i) {
            if (id[i].id == book.id) {
                cout << "Book exists!" << endl;
                return;
            }
        }

        cout << "Book name: "; cin.getline(book.title, 50);
        clear_input();
        cout << "Book author: "; cin.getline(book.author, 50);
        clear_input();
        cout << "Book price: "; cin >> book.price;
        clear_input();
        cout << "Book date: "; cin >> book.date;
        clear_input();
        book.deleted = false;

        ofstream out(file, ios::binary | ios::app);
        long pos = out.tellp();
        out.write(reinterpret_cast<char*>(&book), sizeof(Book));
        out.close();

        Index new_item = {book.id, pos};
        id.push_back(new_item);
        cout << "Successfully added!!!" << endl;
    }

    void find_title() {
        char target[50];
        cout << "Enter the book name you wanna find: ";
        cin.getline(target, 50);
        clear_input();
        ifstream in(file, ios::binary);

        Book book;
        bool found = false;
        while (in.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            if (!book.deleted && strcmp(book.title, target) == 0) {
                display(book);
                found = true;
            }
        }
        if (!found)
            cout << "Not Found!" << endl;
        in.close();
    }

    void delete_book() {
        int index;
        cout << "Enter the book id: ";
        cin >> index;

        for (size_t i = 0; i < id.size(); ++i) {
            if (id[i].id == index) {
                fstream fs(file, ios::binary | ios::in | ios::out);
                fs.seekp(id[i].position);
                Book book;
                fs.read(reinterpret_cast<char*>(&book), sizeof(Book));
                book.deleted = true;
                fs.seekp(id[i].position);
                fs.write(reinterpret_cast<char*>(&book), sizeof(Book));
                fs.close();

                id.erase(id.begin() + i);
                cout << "Successfully deleted!!!" << endl;
                return;
            }
        }
        cout << "Not Found!" << endl;
    }

    void sort_author() {
        vector<Book> all;
        ifstream in(file, ios::binary);
        Book book;

        while (in.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            if (!book.deleted)
                all.push_back(book);
        }
        in.close();

        if (all.empty()) {
            cout << "No record!" << endl;
            return;
        }

        for (size_t i = 0; i < all.size() - 1; ++i) {
            for (size_t j = 0; j < all.size() - i - 1; ++j) {
                if (all[j].compare_author(all[j+1]) > 0) {
                    Book temp = all[j];
                    all[j] = all[j+1];
                    all[j+1] = temp;
                }
            }
        }

        cout << "\n--- Books in author ---\n";
        print_books_help("Id", 10);
        print_books_help("Name", 20);
        print_books_help("Author", 15);
        cout << "Price" << endl;

        for (size_t i = 0; i < all.size(); ++i) {
            display(all[i]);
        }
    }

    void display(const Book &book) {
        print_books(book.id, 10);
        print_books_help(book.title, 20);
        print_books_help(book.author, 15);
        cout << book.price << endl;
    }
};


void help() {
    cout << "\n=== Library ===\n";
    cout << "0. Exit" << endl;
    cout << "1. Insert new book" << endl;
    cout << "2. Search by book name" << endl;
    cout << "3. Delete the book" << endl;
    cout << "4. Show all records" << endl;
    cout << "5. Help" << endl;
}

int main() {
    BookManager manager("library.txt");
    int choice;

    help();
    while (true) {
        cout << "Enter your choise: ";
        cin >> choice;
        clear_input();

        switch (choice) {
            case 1:
                manager.insert_book();
                break;
            case 2:
                manager.find_title();
                break;
            case 3:
                manager.delete_book();
                break;
            case 4:
                manager.sort_author();
                break;
            case 5:
                help();
                break;
            case 0:
                return 0;
            default:
                cout << "Retry!!!" << endl;
        }
    }
    return 0;
}