#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void Push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int Pop() {
        if (IsEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        Node* temp = top;
        int poppedValue = top->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int Peek() {
        if (IsEmpty()) {
            throw std::runtime_error("Стек пуст!");
        }
        return top->data;
    }

    bool IsEmpty() {
        return top == nullptr;
    }

    void Display() {
        Node* current = top;
        std::cout << "Содержимое стека (сверху вниз): ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~Stack() {
        while (!IsEmpty()) {
            Pop();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Stack s;
    int choice, value;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент (Push)\n";
        std::cout << "2. Удалить элемент (Pop)\n";
        std::cout << "3. Просмотреть верхний элемент (Peek)\n";
        std::cout << "4. Вывести стек\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Введите значение: ";
            std::cin >> value;
            s.Push(value);
            break;
        case 2:
            try {
                std::cout << "Удалённый элемент: " << s.Pop() << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 3:
            try {
                std::cout << "Верхний элемент: " << s.Peek() << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        case 4:
            s.Display();
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}