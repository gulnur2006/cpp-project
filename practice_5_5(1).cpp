#include <iostream>
#include <ctime>    

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createRandomList(int N) {
    if (N <= 0) return nullptr;

    srand(time(0));  

    ListNode* head = new ListNode(rand() % 100 + 1);  
    ListNode* current = head;

    for (int i = 1; i < N; ++i) {
        current->next = new ListNode(rand() % 100 + 1);
        current = current->next;
    }

    return head;
}

ListNode* reverseFirstK(ListNode* head, int k) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    int count = 0;
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
      
    if (head != nullptr) {
        head->next = current;
    }

    return prev;
}

ListNode* reflectLeft(ListNode* head, int k) {
    if (head == nullptr || k <= 1) {
        return head;
    }
        
    int length = 0;
    ListNode* temp = head;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
        
    if (k > length) {
        std::cout << "k превышает длину списка. Список не изменен." << std::endl;
        return head;
    }

    return reverseFirstK(head, k);
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deleteList(ListNode* head) {
    ListNode* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    int N, k;

    std::cout << "Введите количество элементов в списке: ";
    std::cin >> N;

    if (N <= 0) {
        std::cout << "Некорректный размер списка!" << std::endl;
        return 1;
    }

    ListNode* head = createRandomList(N);

    std::cout << "Сгенерированный список: ";
    printList(head);

    std::cout << "Введите k (сколько элементов отразить влево): ";
    std::cin >> k;

    head = reflectLeft(head, k);

    std::cout << "Список после отражения: ";
    printList(head);
        
    deleteList(head);

    return 0;
}