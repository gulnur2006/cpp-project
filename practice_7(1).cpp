#include <iostream>
#include <ctime>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* generateRandomTree(int depth, int maxValue) {
    if (depth == 0 || rand() % 5 == 0) { 
        return nullptr;
    }
    TreeNode* node = new TreeNode(rand() % maxValue + 1);
    node->left = generateRandomTree(depth - 1, maxValue);
    node->right = generateRandomTree(depth - 1, maxValue);
    return node;
}

void treeToDoublyList(TreeNode* node, TreeNode*& prev, TreeNode*& head) {
    if (!node) return;

    treeToDoublyList(node->left, prev, head);

    if (!prev) {
        head = node; 
    }
    else {
        prev->right = node;
        node->left = prev;
    }
    prev = node;

    treeToDoublyList(node->right, prev, head);
}

TreeNode* convertTreeToList(TreeNode* root) {
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;
    treeToDoublyList(root, prev, head);
    return head;
}

void printTree(TreeNode* root, int space = 0) {
    if (!root) return;
    space += 5;
    printTree(root->right, space);
    cout << endl;
    for (int i = 5; i < space; i++) cout << " ";
    cout << root->val << "\n";
    printTree(root->left, space);
}

void printList(TreeNode* head) {
    TreeNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0)); 
   
    TreeNode* root = generateRandomTree(3, 100);

    cout << "Бинарное дерево:\n";
    printTree(root);

    TreeNode* listHead = convertTreeToList(root);

    cout << "\nДвусвязный список (инфиксный порядок):\n";
    printList(listHead);

    return 0;
}