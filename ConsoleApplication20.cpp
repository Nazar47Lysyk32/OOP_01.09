#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Додати елемент в кінець списку
void append(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}


void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


bool isSorted(Node* head) {
    Node* current = head;
    while (current && current->next) {
        if (current->data > current->next->data) {
            return false;
        }
        current = current->next;
    }
    return true;
}

// Перевірка спису на пару ел. з однаковими значеннями
bool hasDuplicate(Node* head) {
    Node* current = head;
    while (current) {
        Node* runner = current->next;
        while (runner) {
            if (current->data == runner->data) {
                return true;
            }
            runner = runner->next;
        }
        current = current->next;
    }
    return false;
}

// Поміняти місцями елементи списку (перший з другим, третій з четвертим і т.д.)
void swapPairs(Node* head) {
    Node* current = head;
    while (current && current->next) {
        swap(current->data, current->next->data);
        current = current->next->next;
    }
}

// Визначити, чи список L1 входить як частина у список L2
bool isSublist(Node* L1, Node* L2) {
    if (!L1) {
        return true;  // Порожній список є підсписком будь-якого списку
    }
    if (!L2) {
        return false; // Непорожній список не може бути підсписком порожнього
    }

    Node* current1 = L1;
    Node* current2 = L2;

    while (current2) {
        if (current1->data == current2->data) {
            current1 = current1->next;
            if (!current1) {
                return true;  // Знайдено підсписок
            }
        }
        else {
            current1 = L1;  // Починаємо перевірку співпадінь знову
        }
        current2 = current2->next;
    }

    return false; // Підсписок не знайдено
}


void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* myList = nullptr;
    append(myList, 1);
    append(myList, 2);
    append(myList, 3);
    append(myList, 4);
    append(myList, 5);

    cout << "List: ";
    printList(myList);

    if (isSorted(myList)) {
        cout << "The list is sorted in descending order." << endl;
    }
    else {
        cout << "The list is not in descending order." << endl;
    }

    if (hasDuplicate(myList)) {
        cout << "The list contains a pair of elements with the same values." << endl;
    }
    else {
        cout << "The list does not contain a pair of elements with the same values." << endl;
    }

    swapPairs(myList);
    cout << "The list after exchanging pairs of elements: ";
    printList(myList);

    //  другий список для використання в функції isSublist
    Node* subList = nullptr;
    append(subList, 3);
    append(subList, 4);

    if (isSublist(subList, myList)) {
        cout << "L1 is a sublist of L2." << endl;
    }
    else {
        cout << "L1 is not a sublist of L2." << endl;
    }

    // Звільнити пам'ять)
    deleteList(myList);
    deleteList(subList);

    return 0;
}
