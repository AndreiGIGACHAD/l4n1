#include <iostream>

struct Node {
    int d;
    Node* next;
};

Node* first(int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    return pv;
}

void add(Node** pend, int d) {
    Node* pv = new Node;
    pv->d = d;
    pv->next = nullptr;
    (*pend)->next = pv;
    *pend = pv;
}

Node* find(Node* pbeg, int d) {
    Node* pv = pbeg;
    while (pv) {
        if (pv->d == d)
            break;
        pv = pv->next;
    }
    return pv;
}

int remove(Node pbeg, Node pend, int key) {
    Node* pkey = find(*pbeg, key);
    if (pkey) {
        if (*pbeg == pkey) {
            *pbeg = (*pbeg)->next;
            if (*pbeg == nullptr) // если список оказался пустым после удаления
                *pend = nullptr;
        }
        else {
            Node* prev = *pbeg;
            while (prev->next != pkey)
                prev = prev->next;
            prev->next = pkey->next;
            if (pkey == *pend)
                *pend = prev;
        }
        delete pkey;
        return 1;
    }
    return 0;
}

Node* insert(Node* pbeg, Node** pend, int key, int d) {
    Node* pkey = find(pbeg, key);
    if (pkey) {
        Node* pv = new Node;
        pv->d = d;
        pv->next = pkey->next;
        pkey->next = pv;
        if (pkey == *pend)
            *pend = pv;
        return pv;
    }
    return nullptr;
}

int main() {
    Node* pbeg = first(1);
    Node* pend = pbeg;
    for (int i = 2; i < 6; i++)
        add(&pend, i);
    insert(pbeg, &pend, 2, 200);
    if (!remove(&pbeg, &pend, 5))
        std::cout << "не найден";
    Node* pv = pbeg;
    while (pv) {
        std::cout << pv->d << " ";
        pv = pv->next;
    }
    return 0;
}