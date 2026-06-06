#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <limits>
#include <sstream>

// Note: each line is a Node...
struct Node {
    std::string data;
    Node* prev = nullptr;
    Node* next = nullptr;
};

class TextEditor {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* current = nullptr;
    int line_count = 0;
    std::stack<std::pair<std::vector<std::string>, int>> undo;

    // Function to clear the buffer:
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        current = nullptr;
        line_count = 0;
    }

    // Function to get the current line number:
    int get_current_line() {
        if (!current)
            return 1;
        int num = 1;
        Node* temp = head;
        while (temp != current) {
            temp = temp->next;
            num++;
        }
        return num;
    }

    // 1-level undo function:
    void restore(const std::vector<std::string>& snap, int current_line) {
        clear();
        for (const auto& line : snap) {
            insert_line(line);
        }
        goto_line(current_line);
    }

public:
    ~TextEditor() {
        clear();
    }

    // Insert a new line in the end of the file:
    void insert_line(const std::string& line) {
        Node* new_node = new Node{line};
        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        line_count++;
        if (!current)
            current = head;
    }

    // Loading the file...
    void read(const std::string& filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cout << "File not found..." << std::endl;
            return;
        }
        clear();
        std::string line;
        while (std::getline(file, line)) {
            insert_line(line);
        }
        current = head;
        std::cout << "File loaded successfully..." << std::endl;
    }

    // Writing the file...
    void write(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            std::cout << "Cannot open file for writing..." << std::endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            file << temp->data << std::endl;
            temp = temp->next;
        }
        std::cout << "File written successfully!" << std::endl;
    }

    void push_undo() {
        std::vector<std::string> mem;
        Node* temp = head;
        while (temp) {
            mem.push_back(temp->data);
            temp = temp->next;
        }
        int current_line = get_current_line();
        undo.push({mem, current_line});
    }

    void undo_it() {
        if (undo.empty()) {
            std::cout << "No previous actions!" << std::endl;
            return;
        }
        auto [mem, num] = undo.top();
        undo.pop();
        restore(mem, num);
        std::cout << "Undo process succeeded!" << std::endl;
    }

    void delete_current() {
        if (!current) {
            std::cout << "No current line" << std::endl;
        }
        Node* to_delete = current;
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
            current = current->next;
        } else {
            current = current->prev;
            tail = current->prev;
        }
        delete to_delete;
        line_count--;
        if (line_count == 0)
            current = nullptr;
    }

    bool find(const std::string& pattern) {
        if (pattern.empty())
            return false;
        Node* temp = current;
        while (temp) {
            if (temp->data.find(pattern) != std::string::npos) {
                current = temp;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void replace_current(
        const std::string& old, const std::string& new_str
    ) {
        if (!current || old.empty())
            return;
        size_t pos = 0;
        while (
            (pos = current->data.find(old, pos)) != std::string::npos
        ) {
            current->data.replace(pos, old.length(), new_str);
            pos += new_str.length();
        }
    }

    void replace_all(
        const std::string& old, const std::string& new_str
    ) {
        if (old.empty())
            return;
        Node* temp = head;
        while (temp) {
            size_t pos = 0;
            while (
                (pos = temp->data.find(old, pos)) != std::string::npos
            ) {
                temp->data.replace(pos, old.length(), new_str);
                pos += new_str.length();
            }
            temp = temp->next;
        }
    }

    void next() {
        if (current && current->next)
            current = current->next;
    }

    void prev() {
        if (current && current->prev)
            current = current->prev;
    }

    void to_top() {
        if (head)
            current = head;
    }

    void to_end() {
        if (tail)
            current = tail;
    }

    void goto_line(int n) {
        if (n < 1 || n > line_count) {
            std::cout << "Invalid line number." << std::endl;
            return;
        }
        current = head;
        for (int i = 1; i < n; ++i) {
            current = current->next;
        }
    }

    void view() {
        if (!head) {
            std::cout << "Buffer is empty..." << std::endl;
            return;
        }
        Node* temp = head;
        int num = 1;
        while (temp) {
            std::cout << num << ": " << temp->data << std::endl;
            temp  = temp->next;
            ++num;
        }
    }

    void help() {
        std::cout << "Available commands:" << std::endl;
        std::cout << "R - Read a text file into the buffer" << std::endl;
        std::cout << "W - Write the content of the buffer to a file" << std::endl;
        std::cout << "D - Delete the current line and move to the next line" << std::endl;
        std::cout << "F - Search for a pattern string starting from the current line" << std::endl;
        std::cout << "C - Replace a selected substring (within the current line or globally)" << std::endl;
        std::cout << "Q - Quit the editor" << std::endl;
        std::cout << "H - Display help information" << std::endl;
        std::cout << "N - Move to the next line" << std::endl;
        std::cout << "P - Move to the previous line" << std::endl;
        std::cout << "B - Move to the beginning (first line)" << std::endl;
        std::cout << "E - Move to the end (last line)" << std::endl;
        std::cout << "G - Jump to a specified line number" << std::endl;
        std::cout << "V - View and print the entire buffer content" << std::endl;
        std::cout << "U - Undo the most recent edit (delete or replace)" << std::endl;
    }

    void display_current() {
        if (current) {
            std::cout << "Current line: " << current->data << std::endl;
        } else {
            std::cout << "No current line." << std::endl;
        }
    }
};

int main() {
    TextEditor editor;
    std::string command;

    while (true) {
        std::cout << "Command: ";
        if (!(std::cin >> command)) break;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (command == "Q") {
            break;
        } else if (command == "H") {
            editor.help();
        } else if (command == "V") {
            editor.view();
        } else if (command == "B") {
            editor.to_top();
            editor.display_current();
        } else if (command == "E") {
            editor.to_end();
            editor.display_current();
        } else if (command == "N") {
            editor.next();
            editor.display_current();
        } else if (command == "P") {
            editor.prev();
            editor.display_current();
        } else if (command == "G") {
            int n;
            std::cout << "Enter line number: ";
            if (std::cin >> n) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                editor.goto_line(n);
                editor.display_current();
            }
        } else if (command == "R") {
            std::string file;
            std::cout << "Enter filename: ";
            std::getline(std::cin, file);
            editor.read(file);
            editor.display_current();
        } else if (command == "W") {
            std::string file;
            std::cout << "Enter filename: ";
            std::getline(std::cin, file);
            editor.write(file);
        } else if (command == "D") {
            editor.push_undo();
            editor.delete_current();
            editor.display_current();
        } else if (command == "F") {
            std::string pattern;
            std::cout << "Enter pattern: ";
            std::getline(std::cin, pattern);
            if (editor.find(pattern)) {
                std::cout << "Found." << std::endl;
                editor.display_current();
            } else {
                std::cout << "Not found." << std::endl;
            }
        } else if (command == "C") {
            std::string oldStr, newStr, scope;
            std::cout << "Enter old substring: ";
            std::getline(std::cin, oldStr);
            std::cout << "Enter new substring: ";
            std::getline(std::cin, newStr);
            std::cout << "Scope (current/global): ";
            std::getline(std::cin, scope);
            editor.push_undo();
            if (scope == "current") {
                editor.replace_current(oldStr, newStr);
            } else if (scope == "global") {
                editor.replace_all(oldStr, newStr);
            } else {
                std::cout << "Invalid scope." << std::endl;
            }
            editor.display_current();
        } else if (command == "U") {
            editor.undo_it();
            editor.display_current();
        } else {
            std::cout << "Unknown command. Use H for help." << std::endl;
        }
    }

    return 0;
}