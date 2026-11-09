
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>
using namespace std;

struct Book {
    int id;
    string title, author;
    bool available;

    Book(int i, string t, string a)
        : id(i), title(t), author(a), available(true) {}
};

class Library {
    vector<Book> books;

    Book* find(int id) {
        for (auto& b : books)
            if (b.id == id)
                return &b;

        return nullptr;
    }

public:
    void add(Book b) {
        if (find(b.id))
            throw runtime_error("Duplicate ID");

        books.push_back(b);
    }

    void search(int id) const {
        for (const auto& b : books) {
            if (b.id == id) {
                cout << "Search result: " << b.title
                     << " by " << b.author
                     << " | "
                     << (b.available ? "Available" : "Issued")
                     << endl;
                return;
            }
        }

        cout << "Book not found" << endl;
    }

    void issue(int id) {
        Book* b = find(id);

        if (!b)
            throw runtime_error("Not found");

        if (!b->available)
            throw runtime_error("Already issued");

        b->available = false;
    }

    void giveBack(int id) {
        Book* b = find(id);

        if (!b)
            throw runtime_error("Not found");

        if (b->available)
            throw runtime_error("Not issued");

        b->available = true;
    }

    void list() const {
        for (const auto& b : books) {
            cout << b.id << " | "
                 << b.title << " | "
                 << b.author << " | "
                 << (b.available ? "Available" : "Issued")
                 << endl;
        }
    }

    void save() const {
        ofstream f("books.txt");

        if (!f)
            throw runtime_error("File error");

        for (const auto& b : books) {
            f << b.id << '|'
              << b.title << '|'
              << b.author << '|'
              << b.available << '\n';
        }

        if (!f)
            throw runtime_error("Could not write books.txt");
    }

    void load() {
        ifstream f("books.txt");

        if (!f)
            throw runtime_error("Could not open books.txt");

        string line;

        while (getline(f, line)) {
            istringstream x(line);
            string id, t, a, v;

            getline(x, id, '|');
            getline(x, t, '|');
            getline(x, a, '|');
            getline(x, v);

            if (!id.empty()) {
                books.emplace_back(stoi(id), t, a);
                books.back().available = (v == "1");
            }
        }
    }
};

int main() {
    cout << "Student: Fatemeh Sahranvard" << endl;

    try {
        Library l;

        l.add(Book(1, "C++ Basics", "Bjarne Stroustrup"));
        l.add(Book(2, "Data Structures", "Seymour Lipschutz"));

        l.search(1);
        l.search(3);

        l.issue(1);
        cout << "Book 1 issued" << endl;

        l.giveBack(1);
        cout << "Book 1 returned" << endl;

        l.list();

        l.save();
        cout << "Saved to books.txt" << endl;

        Library loaded;
        loaded.load();

        cout << "Reloaded records:" << endl;
        loaded.list();

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
