#include <iostream>
using namespace std;

template<typename T>
class List {
private:
    // Внутрішня структура вузла
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    // Конструктор
    List() : head(nullptr) {}

    // Деструктор
    ~List() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    // Додавання елемента в кінець списку
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* tmp = head;
            while (tmp->next)
                tmp = tmp->next;
            tmp->next = newNode;
        }
    }

    // Ітератор
    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            if (current)
                current = current->next;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    // Повернення початку і кінця списку
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    // Вивід списку
    void print() {
        for (Iterator it = begin(); it != end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
};

// === Тестування ===
int main() {
    List<int> intList;
    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);

    cout << "List<int>: ";
    intList.print();

    List<char> charList;
    charList.push_back('A');
    charList.push_back('B');
    charList.push_back('C');

    cout << "List<char>: ";
    for (auto it = charList.begin(); it != charList.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}
