#pragma once
#include <iostream>
#include "DataTypes.h"
#include <memory.h>

//========================================СПИСКИ========================================//
template<typename Type>
struct node0
{
    Type data;
    struct node0* next;

    node0(const Type& value)
    {
        this->data = value;
        this->next = this;
    }

    node0(const Type& value, node0<Type>*& next)
    {
        this->data = value;
        this->next = next;
    }
};

template<typename Type>
struct node1
{
    Type data;
    struct node1<Type>* next;
    struct node1<Type>* past;

    node1(const Type& value)
    {
        this->data = value;
        this->next = nullptr;
        this->past = nullptr;
    }

    node1(const Type& value, node1<Type>* next, node1<Type>* past)
    {
        this->data = value;
        this->next = next;
        this->past = past;
    }
};

template<typename Type>
struct node2
{
    Type data;
    struct node2<Type>* next;

    node2(const Type& value)
    {
        this->data = value;
        this->next = nullptr;
    }

    node2(const Type& value, node2<Type>* next)
    {
        this->data = value;
        this->next = next;
    }
};

template<typename Type>
class CycleList
{
private:

    node0<Type>* head;
    unsigned int size;
public:
    CycleList();
    node0<Type>* find_last();
    void push_back(Type value);
    void push_back(Type* value);
    bool delete_by_value(Type value);
    bool delete_by_id(int i);
    Type* get_data_by_id(int i);
    node0<Type>* get_node_by_id(int i);
    bool is_empty();
    unsigned int getCount();
    void print();
    ~CycleList();
};

template<typename Type>
class TwoPointList {
private:
    node1<Type>* head;
    unsigned int count;
public:
    TwoPointList();
    void push_back(Type data);
    void delete_element(Type data);
    node1<Type>* search_element(Type data);
    void print_list();
    Type* get_element(int i);
    unsigned int getCount();
    ~TwoPointList();
};

template<typename Type>
class OnePointList {
private:
    node2<Type>* head;
    unsigned int count;
public:
    OnePointList();
    void push_back(Type data);
    void delete_element(Type data);
    node2<Type>* search_element(Type data);
    void print_list();
    Type* get_element(int i);
    unsigned int getCount();
    ~OnePointList();
};

//========================================ДЕРЕВЬЯ========================================//
template<typename keyType, typename valueType>
struct Node
{
    CycleList<valueType> *value;
    keyType key;
    struct Node<keyType, valueType>* left;
    struct Node<keyType, valueType>* right;
    char balance;
    Node(keyType newKey, valueType newValue) { key = newKey, value = new CycleList<valueType>(); value->push_back(newValue); left = nullptr; right = nullptr; balance = 0; }
};

template<typename keyType, typename valueType>
struct treeNode {
    treeNode* leftChild;
    treeNode* rightChild;
    int balanceFactor;
    OnePointList<valueType> *value;
    keyType head;
    treeNode(keyType newKey, valueType newValue) { head = newKey; value = new OnePointList<valueType>(); value->push_back(newValue); leftChild = nullptr; rightChild = nullptr; balanceFactor = 0; }
    // список
    treeNode(keyType newKey, OnePointList<valueType>* newValue) { head = newKey; value = newValue; leftChild = nullptr; rightChild = nullptr; balanceFactor = 0; }
};

template<typename keyType, typename valueType>
struct elem
{
    keyType key;
    TwoPointList<valueType>* value;
    struct elem<keyType, valueType>* left;
    struct elem<keyType, valueType>* right;
    char balance;
    elem(keyType newKey, valueType newValue) { this->key = newKey; value = new TwoPointList<valueType>(); value->push_back(newValue); left = nullptr; right = nullptr; balance = 0; }
};


template<typename keyType, typename valueType>
class AvlTree1 {
private:
    Node<keyType, valueType>* tree1;
    bool h;
    void BalanceL(Node<keyType, valueType>*& root);
    void BalanceR(Node<keyType, valueType>*& root);
    void Del(Node<keyType, valueType>*& r, Node<keyType, valueType>*& q);
    void AddRec(Node<keyType, valueType>*& root, keyType key, valueType value);
    void DeleteRec(Node<keyType, valueType>*& root, keyType key, valueType value);
    void SearchElementRec(Node<keyType, valueType>* root, keyType key, valueType value, Node<keyType, valueType>*& res);
    void PrintTreeRec(Node<keyType, valueType>* root, int h);
    void MemoryClear(Node<keyType, valueType>*& root);

public:
    AvlTree1();
    void push(keyType key, valueType value);
    void delete_key(keyType key, valueType value);
    Node<keyType, valueType>* search_key(keyType key, valueType value);
    void print();
    ~AvlTree1();
};

template<typename keyType, typename valueType>
class AvlTree2 {
private:
    treeNode<keyType, valueType>* tree;
    bool heightChanged;
    void addNode(treeNode<keyType, valueType>*& pointer, keyType key, valueType value);
    void printTree(treeNode<keyType, valueType>* root, int h);
    void _deleteTree(treeNode<keyType, valueType>*& pointer);
    treeNode<keyType, valueType>* deleteTree(treeNode<keyType, valueType>*& root);
    void _del_balanceLeft(treeNode<keyType, valueType>*& node);
    void _del_balanceRight(treeNode<keyType, valueType>*& node);
    void _delWhenTwoChild(treeNode<keyType, valueType>*& node, treeNode<keyType, valueType>*& delNode);
    void delNode(treeNode<keyType, valueType>*& pointer, keyType key, valueType value);
    void searchTreeNode(treeNode<keyType, valueType>* pointer, keyType key, valueType value, treeNode<keyType, valueType>*& res);

public:
    AvlTree2();
    void push(keyType key, valueType value);
    void delete_key(keyType key, valueType value);
    treeNode<keyType, valueType>* search_key(keyType key, valueType value);
    void print();
    ~AvlTree2();
};

template<typename keyType, typename valueType>
class AvlTree3 {
private:
    elem<keyType, valueType>* tree1;
    bool h;
    void BalanceL(elem<keyType, valueType>*& root);
    void BalanceR(elem<keyType, valueType>*& root);
    void Del(elem<keyType, valueType>*& r, elem<keyType, valueType>*& q);
    void AddRec(elem<keyType, valueType>*& root, keyType key, valueType value);
    void DeleteRec(elem<keyType, valueType>*& root, keyType key, valueType value);
    void SearchElementRec(elem<keyType, valueType>* root, keyType key, valueType value, elem<keyType, valueType>*& res);
    void PrintTreeRec(elem<keyType, valueType>* root, int h);
    void MemoryClear(elem<keyType, valueType>*& root);

public:
    AvlTree3();
    void push(keyType key, valueType value);
    void delete_key(keyType key, valueType value);
    elem<keyType, valueType>* search_key(keyType key, valueType value);
    void print();
    ~AvlTree3();
};

//========================================СПИСКИ========================================//
template<typename Type>CycleList<Type>::CycleList() {
    this->head = nullptr;
    this->size = 0;
}

template<typename Type> node0<Type>* CycleList<Type>::find_last()
{
    node0<Type>* buffer = this->head;
    if (!this->head)return nullptr;
    while (buffer->next != this->head)buffer = buffer->next;
    return buffer;
}

template<typename Type>void CycleList<Type>::push_back(Type value)
{
    if (!this->head)head = new node0<Type>(value);
    else
    {
        node0<Type>* last = this->find_last();
        last->next = new node0<Type>(value, this->head);
    }
    this->size++;
}

template<typename Type>void CycleList<Type>::push_back(Type* value)
{
    if (!this->head)head = new node0<Type>(*value);
    else
    {
        node0<Type>* last = this->find_last();
        last->next = new node0<Type>(*value, this->head);
    }
    this->size++;
}

template<typename Type>bool CycleList<Type>::delete_by_value(Type value)
{
    if (!this->head)return false;
    if (this->head->data == value)
    {
        node0<Type>* last = this->find_last();
        last->next = this->head->next;
        delete head;
        head = last->next;
        this->size--;
        if (this->size == 0)head = nullptr;
        return true;
    }
    else
    {
        node0<Type>* buffer = this->head;
        while (buffer->next != this->head && buffer->next->data != value)buffer = buffer->next;
        if (buffer->next->data == value)
        {
            node0<Type>* del = buffer->next;
            buffer->next = buffer->next->next;
            delete del;
            this->size--;
            if (this->size == 0)head = nullptr;
            return true;
        }
        return false;
    }
}

template<typename Type> bool CycleList<Type>::delete_by_id(int i)
{
    if (!this->head)return false;
    if (i == 0)
    {
        node0<Type>* last = this->find_last();
        last->next = this->head->next;
        delete head;
        head = last->next;
        this->size--;
        if (this->size == 0)head = nullptr;
        return true;
    }
    else
    {
        node0<Type>* buffer = this->head;
        int j = 0;
        for (; (j < i - 1) && (j < this->size - 1);j++)buffer = buffer->next;
        if (j == i - 1)
        {
            node0<Type>* del = buffer->next;
            buffer->next = buffer->next->next;
            delete del;
            this->size--;
            if (this->size == 0)head = nullptr;
            return true;
        }
        return false;
    }
}

template<typename Type> Type* CycleList<Type>::get_data_by_id(int i)
{
    node0<Type>* buffer = this->head;
    int j = 0;
    if (!this->head)return nullptr;
    for (; (j < i) && (j < this->size - 1);j++)buffer = buffer->next;
    if (j == i)return &(buffer->data);
    else return nullptr;
}

template<typename Type> node0<Type>* CycleList<Type>::get_node_by_id(int i)
{
    node0<Type>* buffer = this->head;
    int j = 0;
    if (!this->head)return nullptr;
    for (; (j < i) && (j < this->size - 1);j++)buffer = buffer->next;
    if (j == i)return buffer;
    else return nullptr;
}

template<typename Type> bool CycleList<Type>::is_empty()
{
    if (head)return false;
    else return true;
}

template<typename Type> void CycleList<Type>::print()
{
    node0<Type>* buffer = this->head;
    if (this->head)
    {
        int i = 1;
        while (buffer->next != this->head)
        {
            std::cout << i++ << " " << buffer->data << " next: " << buffer->next->data << std::endl;
            buffer = buffer->next;
        }
        std::cout << i++ << " " << buffer->data << " next: " << buffer->next->data << std::endl;
    }
}

template<typename Type> CycleList<Type>::~CycleList()
{
    if (this->head)
    {
        while (this->head->next != this->head)
        {
            node0<Type>* del = this->head->next;
            this->head->next = this->head->next->next;
            delete del;
        }
        delete head;
    }
}

template<typename Type> unsigned int CycleList<Type>::getCount() { return this->size; }

template<typename Type> Type* TwoPointList<Type>::get_element(int i) {
    if (head) {
        node1<Type>* buffer = head;
        int j = 0;
        while (j != i && buffer->next != nullptr) {
            buffer = buffer->next;
            j++;
        }
        if (j == i)return &(buffer->data);
        else return nullptr;
    }
}

template<typename Type>TwoPointList<Type>::TwoPointList() {
    this->head = nullptr;
    this->count = 0;
}

template<typename Type> void TwoPointList<Type>::push_back(Type data) {
    if (head) {
        if (head->data > data) {
            node1<Type>* newData = new node1<Type>(data, head, head);
            head->past = newData;
            head = newData;
        }
        else {
            node1<Type>* buffer = head;
            while (buffer->data < data && buffer->next != nullptr)buffer = buffer->next;
            if (buffer->data <= data) {
                node1<Type>* newData = new node1<Type>(data, buffer->next, buffer);
                buffer->next = newData;
            }
            else {
                node1<Type>* newData = new node1<Type>(data, buffer, buffer->past);
                buffer->past = newData;
                if (head == buffer)head = newData;
            }
        }
        this->count++;
    }
    else {
        head = new node1<Type>(data);
        this->count++;
    }
}

template<typename Type> void TwoPointList<Type>::delete_element(Type data) {
    if (head) {
        node1<Type>* buffer = head;
        while (buffer->data != data && buffer != nullptr)buffer = buffer->next;
        if (buffer != nullptr) {
            node1<Type>* del = buffer;
            if(del != head)buffer->past->next = buffer->next;
            else if (del == head)head = del->next;
            delete del;
            this->count--;
        }
    }
}

template<typename Type> node1<Type>* TwoPointList<Type>::search_element(Type data) {
    if (head) {
        node1<Type>* buffer = head;
        while (buffer->data != data && buffer->next != nullptr)buffer = buffer->next;
        if (buffer->data == data)return buffer;
        else return nullptr;
    }
}

template<typename Type> void TwoPointList<Type>::print_list() {
    if (head) {
        node1<Type>* buffer = head;
        while (buffer != nullptr) {
            std::cout << buffer->data << std::endl;
            buffer = buffer->next;
        }
    }
}

template<typename Type> unsigned int TwoPointList<Type>::getCount() { return this->count; }

template<typename Type>TwoPointList<Type>::~TwoPointList() {
    if (!head) {
        node1<Type>* buffer = head;
        while (buffer != nullptr) {
            buffer = head->next;
            head->next = head->next->next;
            delete buffer;
        }
        delete head;
        head = nullptr;
    }
}

template<typename Type>OnePointList<Type>::OnePointList() {
    this->head = nullptr;
    this->count = 0;
}

template<typename Type> void OnePointList<Type>::push_back(Type data) {
    if (head) {
        if (head->data > data) {
            node2<Type>* newData = new node2<Type>(data, head);
            head = newData;
        }
        else {
            node2<Type>* buffer = head;
            while (buffer->next != nullptr && buffer->next->data <= data)buffer = buffer->next;
            node2<Type>* newData = new node2<Type>(data, buffer->next);
            buffer->next = newData;
        }
        this->count++;
    }
    else {
        head = new node2<Type>(data);
        this->count++;
    }
}

template<typename Type> Type* OnePointList<Type>::get_element(int i) {
    if (head) {
        node2<Type>* buffer = head;
        int j = 0;
        while (j != i && buffer->next != nullptr) {
            buffer = buffer->next;
            j++;
        }
        if (j == i)return &buffer->data;
        else return nullptr;
    }
}

template<typename Type> void OnePointList<Type>::delete_element(Type data) {
    if (head) {
        node2<Type>* buffer = head;
        if (head->data == data) {
            head = head->next;
            delete buffer;
            this->count--;
        }
        else {
            if (buffer->next != nullptr) {
                node2<Type>* next = buffer->next;
                while (next->next != nullptr && next->data != data)
                {
                    buffer = next;
                    next = next->next;
                }
                if (next->data == data) {
                    buffer->next = next->next;
                    delete next;
                    this->count--;
                }

            }
        }
    }
}

template<typename Type> node2<Type>* OnePointList<Type>::search_element(Type data) {
    if (head) {
        node2<Type>* buffer = head;
        while (buffer->data != data && buffer->next != nullptr)buffer = buffer->next;
        if (buffer->data == data)return buffer;
        else return nullptr;
    }
}

template<typename Type> void OnePointList<Type>::print_list() {
    if (head) {
        node2<Type>* buffer = head;
        while (buffer != nullptr) {
            std::cout << buffer->data << std::endl;
            buffer = buffer->next;
        }
    }
}

template<typename Type> unsigned int OnePointList<Type>::getCount() { return this->count; }

template<typename Type>OnePointList<Type>::~OnePointList() {
    if (!head) {
        node2<Type>* buffer = head;
        while (buffer != nullptr) {
            buffer = head->next;
            head->next = head->next->next;
            delete buffer;
        }
        delete head;
        head = nullptr;
    }
}

//========================================ДЕРЕВЬЯ========================================//
template<typename keyType, typename valueType> AvlTree1<keyType, valueType>::AvlTree1() {
    this->tree1 = nullptr;
    this->h = false;
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::BalanceL(Node<keyType, valueType>*& root) {
    Node<keyType, valueType>* p1;
    Node<keyType, valueType>* p2;
    char bal1, bal2;
    switch (root->balance)
    {
    case -1:
        root->balance = 0;
        break;
    case 0:
        root->balance = 1;
        h = false;
        break;
    case 1:
        p1 = root->right; bal1 = p1->balance;
        if (bal1 >= 0)
        {
            root->right = p1->left;
            p1->left = root;
            if (bal1 == 0) {
                root->balance = 1;
                p1->balance = -1;
                h = false;
            }
            else
            {
                root->balance = 0;
                p1->balance = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->left; bal2 = p2->balance;
            p1->left = p2->right; p2->right = p1;
            root->right = p2->left; p2->left = root;
            if (bal2 == 1) root->balance = -1;
            else root->balance = 0;
            if (bal2 == -1) p1->balance = 1;
            else p1->balance = 0;
            root = p2;
            p2->balance = 0;
        }

    }
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::BalanceR(Node<keyType, valueType>*& root) {
    Node<keyType, valueType>* p1;
    Node<keyType, valueType>* p2;
    char bal1, bal2;
    switch (root->balance)
    {
    case 1:
        root->balance = 0;
        break;
    case 0:
        root->balance = 1;
        h = false;
        break;
    case -1:
        p1 = root->left; bal1 = p1->balance;
        if (bal1 <= 0)
        {
            root->left = p1->right;
            p1->right = root;
            if (bal1 == 0) {
                root->balance = -1;
                p1->balance = 1;
                h = false;
            }
            else
            {
                root->balance = 0;
                p1->balance = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->right; bal2 = p2->balance;
            p1->right = p2->left; p2->left = p1;
            root->left = p2->right; p2->right = root;
            if (bal2 == -1) root->balance = 1;
            else root->balance = 0;
            if (bal2 == 1) p1->balance = -1;
            else p1->balance = 0;
            root = p2;
            p2->balance = 0;
        }

    }
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::AddRec(Node<keyType, valueType>*& root, keyType key, valueType value) {
    Node<keyType, valueType>* p1;
    Node<keyType, valueType>* p2;
    if (!root)
    {
        root = new Node<keyType, valueType>(key, value);
        h = true;
    }
    else if (root->key > key)
    {
        AddRec(root->left, key, value);
        if (h)
        {
            if (root->balance == 1) { root->balance = 0; h = false; }
            else if (root->balance == 0) { root->balance = -1; }
            else
            {
                p1 = root->left;
                if (p1->balance == -1)
                {
                    root->left = p1->right;
                    p1->right = root;
                    root->balance = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->right;
                    p1->right = p2->left;
                    p2->left = p1;
                    root->left = p2->right;
                    p2->right = root;
                    if (p2->balance == -1)
                    {
                        root->balance = 1;
                    }
                    else
                    {
                        root->balance = 0;
                    }
                    if (p2->balance == 1)
                    {
                        p1->balance = -1;
                    }
                    else
                    {
                        p1->balance = 0;
                    }
                    root = p2;
                }
                root->balance = 0;
                h = false;
            }
        }
    }
    else if (root->key < key)
    {
        AddRec(root->right, key, value);
        if (h)
        {
            if (root->balance == -1) { root->balance = 0; h = false; }
            else if (root->balance == 0) { root->balance = 1; }
            else
            {
                p1 = root->right;
                if (p1->balance == 1)
                {
                    root->right = p1->left;
                    p1->left = root;
                    root->balance = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->left;
                    p1->left = p2->right;
                    p2->right = p1;
                    root->right = p2->left;
                    p2->left = root;

                    if (p2->balance == 1)
                    {
                        root->balance = -1;
                    }
                    else
                    {
                        root->balance = 0;
                    }
                    if (p2->balance == -1)
                    {
                        p1->balance = 1;
                    }
                    else
                    {
                        p1->balance = 0;
                    }
                    root = p2;
                }

                root->balance = 0;
                h = false;

            }
        }
    }
    else {
        root->value->push_back(value);
    }
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::Del(Node<keyType, valueType>*& r, Node<keyType, valueType>*& q) {
    if (r->right)
    {
        Del(r->right, q);
        if (h)BalanceR(r);
    }
    else
    {
        q->key = r->key;
        q = r;
        r = r->left;
        h = true;
    }
}

template<typename keyType, typename valueType> void AvlTree1<keyType, valueType>::DeleteRec(Node<keyType, valueType>*& root, keyType key, valueType value) {
    Node<keyType, valueType>* q;
    if (!root) {}
    else if (root->key > key)
    {
        DeleteRec(root->left, key, value);
        if (h) BalanceL(root);
    }
    else if (root->key < key)
    {
        DeleteRec(root->right, key, value);
        if (h) BalanceR(root);
    }
    else
    {
        q = root;
        if (!q->right) { root = q->left; h = true; }
        else if (!q->left) { root = q->right; h = true; }
        else
        {
            Del(q->left, q);
            if (h) BalanceL(root);
        }
    }
}

template<typename keyType, typename valueType> void AvlTree1<keyType, valueType>::SearchElementRec(Node<keyType, valueType>* root, keyType key, valueType value, Node<keyType, valueType>*& res) {
    if (root->key == key)res = root;
    if (root->left)SearchElementRec(root->left, key, value, res);
    if (root->right)SearchElementRec(root->right, key, value, res);
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::PrintTreeRec(Node<keyType, valueType>* root, int h) {
    if (root)
    {
        PrintTreeRec(root->right, h + 4);
        for (int i = 1; i <= h; i++)std::cout << " ";
        std::cout << root->key << std::endl;
        PrintTreeRec(root->left, h + 4);
    }
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::MemoryClear(Node<keyType, valueType>*& root) {
    if (root) {
        if (root->left)MemoryClear(root->left);
        if (root->right)MemoryClear(root->right);
        delete root;
        root = nullptr;
    }
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::push(keyType key, valueType value) { AddRec(tree1, key, value); }

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::delete_key(keyType key, valueType value) { DeleteRec(tree1, key, value); }

template<typename keyType, typename valueType>  Node<keyType, valueType>* AvlTree1<keyType, valueType>::search_key(keyType key, valueType value) {
    Node<keyType, valueType>* res = nullptr;
    SearchElementRec(tree1, key, value, res);
    return res;
}

template<typename keyType, typename valueType>  void AvlTree1<keyType, valueType>::print() { PrintTreeRec(tree1, 1); }

template<typename keyType, typename valueType> AvlTree1<keyType, valueType>::~AvlTree1() { MemoryClear(tree1); }

template<typename keyType, typename valueType> AvlTree2<keyType, valueType>::AvlTree2() {
    this->tree = nullptr;
    this->heightChanged = false;
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::printTree(treeNode<keyType, valueType>* root, int h) {
    if (root)
    {
        printTree(root->rightChild, h + 4);
        for (int i = 1; i <= h; i++)std::cout << " ";
        std::cout << root->head << std::endl;
        printTree(root->leftChild, h + 4);
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::addNode(treeNode<keyType, valueType>*& pointer, keyType key, valueType value) {
    treeNode<keyType, valueType>* pointer1, * pointer2;
    if (pointer == nullptr) {
        heightChanged = true;
        pointer = new treeNode<keyType, valueType>(key, value);

    }
    else if (pointer->head > key) {
        addNode(pointer->leftChild, key, value);
        if (heightChanged) { // выросла левая часть 
            if (pointer->balanceFactor == 1) {
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
            else if (pointer->balanceFactor == 0) {
                pointer->balanceFactor = -1;
            }
            else {
                pointer2 = new treeNode<keyType, valueType>(key, value);
                pointer1 = new treeNode<keyType, valueType>(key, value);
                pointer1 = pointer->leftChild;
                if (pointer1->balanceFactor == -1) { //одиночная LL-ротация
                    pointer->leftChild = pointer1->rightChild;
                    pointer1->rightChild = pointer;
                    pointer->balanceFactor = 0;
                    pointer = pointer1;
                }
                else { //двойная LR ротация
                    pointer2 = pointer1->rightChild;
                    pointer1->rightChild = pointer2->leftChild;
                    pointer2->leftChild = pointer1;
                    pointer->leftChild = pointer2->rightChild;
                    pointer2->rightChild = pointer;
                    if (pointer2->balanceFactor == -1) pointer->balanceFactor = 1; else pointer->balanceFactor = 0;
                    if (pointer2->balanceFactor == 1) pointer1->balanceFactor = -1; else pointer1->balanceFactor = 0;
                    pointer = pointer2;
                }
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
        }
    }
    else if (pointer->head < key) {
        addNode(pointer->rightChild, key, value);
        if (heightChanged) { //выросла правая часть 
            if (pointer->balanceFactor == -1) {
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
            else if (pointer->balanceFactor == 0) {
                pointer->balanceFactor = 1;
            }
            else {
                pointer2 = new treeNode<keyType, valueType>(key, value);
                pointer1 = new treeNode<keyType, valueType>(key, value);
                pointer1 = pointer->rightChild;
                if (pointer1->balanceFactor == 1) { // одиночаня RR ротация 
                    pointer->rightChild = pointer1->leftChild;
                    pointer1->leftChild = pointer;
                    pointer->balanceFactor = 0;
                    pointer = pointer1;
                }
                else { // двойная RL ротация 
                    pointer2 = pointer1->leftChild;
                    pointer1->leftChild = pointer2->rightChild;
                    pointer2->rightChild = pointer1;
                    pointer->rightChild = pointer2->leftChild;
                    pointer2->leftChild = pointer;
                    if (pointer2->balanceFactor == 1) pointer->balanceFactor = -1; else pointer->balanceFactor = 0;
                    if (pointer2->balanceFactor == -1) pointer1->balanceFactor = 1; else pointer1->balanceFactor = 0;
                    pointer = pointer2;
                }
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
        }

    }
    else {
        pointer->value->push_back(value);
        heightChanged = false;
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::_deleteTree(treeNode<keyType, valueType>*& pointer) {
    if (pointer) {
        if (pointer->leftChild != nullptr) {
            _deleteTree(pointer->leftChild);
        }
        if (pointer->rightChild != nullptr) {
            _deleteTree(pointer->rightChild);
        }
        delete pointer;
    }
}

template<typename keyType, typename valueType> treeNode<keyType, valueType>* AvlTree2<keyType, valueType>::deleteTree(treeNode<keyType, valueType>*& root) {
    _deleteTree(root);
    root = nullptr;
    return root;
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::_del_balanceLeft(treeNode<keyType, valueType>*& node) {
    treeNode<keyType, valueType>* pointer1, * pointer2;
    if (node->balanceFactor == -1) node->balanceFactor = 0;
    else if (node->balanceFactor == 0) {
        node->balanceFactor = 1;
        heightChanged = false;
    }
    else {
        pointer1 = new treeNode<keyType, valueType>(node->head, node->value);
        pointer1 = node->rightChild;
        if (pointer1->balanceFactor >= 0) {
            node->rightChild = pointer1->leftChild;
            pointer1->leftChild = node;
            if (pointer1->balanceFactor == 0) {
                node->balanceFactor = 1;
                pointer1->balanceFactor = -1;
                heightChanged = false;
            }
            else {
                node->balanceFactor = 0;
                pointer1->balanceFactor = 0;
            }
            node = pointer1;
        }
        else {
            pointer2 = new treeNode<keyType, valueType>(node->head, node->value);
            pointer2 = pointer1->leftChild;
            pointer1->leftChild = pointer2->rightChild;
            pointer2->rightChild = pointer1;
            node->rightChild = pointer2->leftChild;
            pointer2->leftChild = node;
            if (pointer2->balanceFactor == 1) {
                node->balanceFactor = -1;
            }
            else {
                node->balanceFactor = 0;
            }
            if (pointer2->balanceFactor == -1) {
                pointer1->balanceFactor = 1;
            }
            else {
                pointer1->balanceFactor = 0;
            }
            node = pointer2;
            pointer2->balanceFactor = 0;
        }
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::_del_balanceRight(treeNode<keyType, valueType>*& node) {
    treeNode<keyType, valueType>* pointer1, * pointer2;
    if (node->balanceFactor == 1) node->balanceFactor = 0;
    else if (node->balanceFactor == 0) {
        node->balanceFactor = -1;
        heightChanged = false;
    }
    else {
        pointer1 = new treeNode<keyType, valueType>(node->head, node->value);
        pointer1 = node->leftChild;
        if (pointer1->balanceFactor <= 0) {
            node->leftChild = pointer1->rightChild;
            pointer1->rightChild = node;
            if (pointer1->balanceFactor == 0) {
                node->balanceFactor = -1;
                pointer1->balanceFactor = 1;
                heightChanged = false;
            }
            else {
                node->balanceFactor = 0;
                pointer1->balanceFactor = 0;
            }
            node = pointer1;
        }
        else {
            pointer2 = new treeNode<keyType, valueType>(node->head, node->value);
            pointer2 = pointer1->rightChild;
            pointer1->rightChild = pointer2->leftChild;
            pointer2->leftChild = pointer1;
            node->leftChild = pointer2->rightChild;
            pointer2->rightChild = node;
            if (pointer2->balanceFactor == -1) node->balanceFactor = 1; else node->balanceFactor = 0;
            if (pointer2->balanceFactor == 1) pointer1->balanceFactor = -1; else pointer1->balanceFactor = 0;
            node = pointer2;
            pointer2->balanceFactor = 0;
        }
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::_delWhenTwoChild(treeNode<keyType, valueType>*& node, treeNode<keyType, valueType>*& delNode) {
    if (node->leftChild != nullptr) {
        _delWhenTwoChild(node->leftChild, delNode);
        if (heightChanged) {
            _del_balanceLeft(node);
        }
    }
    else {
        delNode->head = node->head;
        delNode = node;
        node = node->rightChild;
        heightChanged = true;

    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::delNode(treeNode<keyType, valueType>*& pointer, keyType key, valueType value) {
    treeNode<keyType, valueType>* temp = nullptr;
    if (pointer == nullptr);//нет в дереве
    else if (pointer->head > key) {// > 
        delNode(pointer->leftChild, key, value);
        if (heightChanged) {
            _del_balanceLeft(pointer);
        }

    }
    else if (pointer->head < key) {// <
        delNode(pointer->rightChild, key, value);
        if (heightChanged) {
            _del_balanceRight(pointer);
        }
    }
    else {
        temp = pointer;
        if (temp->rightChild == nullptr) {
            pointer = temp->leftChild;
            heightChanged = true;
            delete temp;
            temp = nullptr;
        }
        else if (temp->leftChild == nullptr) {

            pointer = temp->rightChild;
            heightChanged = true;
            delete temp;
            temp = nullptr;
        }
        else {
            _delWhenTwoChild(temp->rightChild, temp);
            if (heightChanged) _del_balanceRight(pointer);
        }
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::searchTreeNode(treeNode<keyType, valueType>* pointer, keyType key, valueType value, treeNode<keyType, valueType>*& res) {
    if (pointer != NULL) {
        if (pointer->head > key) {
            if (pointer->leftChild != nullptr) {
                searchTreeNode(pointer->leftChild, key, value, res);
            }
        }
        else if (pointer->head < key) {
            if (pointer->rightChild != nullptr) {
                searchTreeNode(pointer->rightChild, key, value, res);
            }
        }
        else {
            res = pointer;
        }
    }
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::push(keyType key, valueType value) { addNode(tree, key, value); }

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::delete_key(keyType key, valueType value) { delNode(tree, key, value); }

template<typename keyType, typename valueType> treeNode<keyType, valueType>* AvlTree2<keyType, valueType>::search_key(keyType key, valueType value) {
    treeNode<keyType, valueType>* res = nullptr;
    searchTreeNode(tree, key, value, res);
    return res;
}

template<typename keyType, typename valueType> void AvlTree2<keyType, valueType>::print() { printTree(tree, 1); }

template<typename keyType, typename valueType> AvlTree2<keyType, valueType>::~AvlTree2() { deleteTree(tree); }

template<typename keyType, typename valueType> AvlTree3<keyType, valueType>::AvlTree3() {
    this->tree1 = nullptr;
    this->h = false;
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::BalanceL(elem<keyType, valueType>*& root) {
    elem<keyType, valueType>* p1;
    elem<keyType, valueType>* p2;
    char bal1, bal2;
    switch (root->balance)
    {
    case -1:
        root->balance = 0;
        break;
    case 0:
        root->balance = 1;
        h = false;
        break;
    case 1:
        p1 = root->right; bal1 = p1->balance;
        if (bal1 >= 0)
        {
            root->right = p1->left;
            p1->left = root;
            if (bal1 == 0) {
                root->balance = 1;
                p1->balance = -1;
                h = false;
            }
            else
            {
                root->balance = 0;
                p1->balance = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->left; bal2 = p2->balance;
            p1->left = p2->right; p2->right = p1;
            root->right = p2->left; p2->left = root;
            if (bal2 == 1) root->balance = -1;
            else root->balance = 0;
            if (bal2 == -1) p1->balance = 1;
            else p1->balance = 0;
            root = p2;
            p2->balance = 0;
        }

    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::BalanceR(elem<keyType, valueType>*& root) {
    elem<keyType, valueType>* p1;
    elem<keyType, valueType>* p2;
    char bal1, bal2;
    switch (root->balance)
    {
    case 1:
        root->balance = 0;
        break;
    case 0:
        root->balance = 1;
        h = false;
        break;
    case -1:
        p1 = root->left; bal1 = p1->balance;
        if (bal1 <= 0)
        {
            root->left = p1->right;
            p1->right = root;
            if (bal1 == 0) {
                root->balance = -1;
                p1->balance = 1;
                h = false;
            }
            else
            {
                root->balance = 0;
                p1->balance = 0;
            }
            root = p1;
        }
        else
        {
            p2 = p1->right; bal2 = p2->balance;
            p1->right = p2->left; p2->left = p1;
            root->left = p2->right; p2->right = root;
            if (bal2 == -1) root->balance = 1;
            else root->balance = 0;
            if (bal2 == 1) p1->balance = -1;
            else p1->balance = 0;
            root = p2;
            p2->balance = 0;
        }

    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::AddRec(elem<keyType, valueType>*& root, keyType key, valueType value) {
    elem<keyType, valueType>* p1;
    elem<keyType, valueType>* p2;
    if (!root)
    {
        root = new elem<keyType, valueType>(key,value );
        h = true;
    }
    else if (root->key > key)
    {
        AddRec(root->left, key, value);
        if (h)
        {
            if (root->balance == 1) { root->balance = 0; h = false; }
            else if (root->balance == 0) { root->balance = -1; }
            else
            {
                p1 = root->left;
                if (p1->balance == -1)
                {
                    root->left = p1->right;
                    p1->right = root;
                    root->balance = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->right;
                    p1->right = p2->left;
                    p2->left = p1;
                    root->left = p2->right;
                    p2->right = root;
                    if (p2->balance == -1)
                    {
                        root->balance = 1;
                    }
                    else
                    {
                        root->balance = 0;
                    }
                    if (p2->balance == 1)
                    {
                        p1->balance = -1;
                    }
                    else
                    {
                        p1->balance = 0;
                    }
                    root = p2;
                }
                root->balance = 0;
                h = false;
            }
        }
    }
    else if (root->key < key)
    {
        AddRec(root->right, key, value);
        if (h)
        {
            if (root->balance == -1) { root->balance = 0; h = false; }
            else if (root->balance == 0) { root->balance = 1; }
            else
            {
                p1 = root->right;
                if (p1->balance == 1)
                {
                    root->right = p1->left;
                    p1->left = root;
                    root->balance = 0;
                    root = p1;
                }
                else
                {
                    p2 = p1->left;
                    p1->left = p2->right;
                    p2->right = p1;
                    root->right = p2->left;
                    p2->left = root;

                    if (p2->balance == 1)
                    {
                        root->balance = -1;
                    }
                    else
                    {
                        root->balance = 0;
                    }
                    if (p2->balance == -1)
                    {
                        p1->balance = 1;
                    }
                    else
                    {
                        p1->balance = 0;
                    }
                    root = p2;
                }

                root->balance = 0;
                h = false;

            }
        }
    }
    else {
        root->value->push_back(value);
    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::Del(elem<keyType, valueType>*& r, elem<keyType, valueType>*& q) {
    if (r->right)
    {
        Del(r->right, q);
        if (h)BalanceR(r);
    }
    else
    {
        q->key = r->key;
        q -> value = r->value;
        q = r;
        r = r->left;
        h = true;
    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::DeleteRec(elem<keyType, valueType>*& root, keyType key, valueType value) {
    elem<keyType, valueType>* q;
    if (!root) {}
    else if (root->key > key)
    {
        DeleteRec(root->left, key, value);
        if (h) BalanceL(root);
    }
    else if (root->key < key)
    {
        DeleteRec(root->right, key, value);
        if (h) BalanceR(root);
    }
    else
    {
        q = root;
        if (!q->right) { root = q->left; h = true; }
        else if (!q->left) { root = q->right; h = true; }
        else
        {
            Del(q->left, q);
            if (h) BalanceL(root);
        }
    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::SearchElementRec(elem<keyType, valueType>* root, keyType key, valueType value, elem<keyType, valueType>*& res) {
    if (root->key == key)res = root;
    if (root->left)SearchElementRec(root->left, key, value, res);
    if (root->right)SearchElementRec(root->right, key, value, res);
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::PrintTreeRec(elem<keyType, valueType>* root, int h) {
    if (root)
    {
        PrintTreeRec(root->right, h + 4);
        for (int i = 1; i <= h; i++)std::cout << " ";
        std::cout << root->key << std::endl;
        PrintTreeRec(root->left, h + 4);
    }
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::MemoryClear(elem<keyType, valueType>*& root) {
    if (root) {
        if (root->left)MemoryClear(root->left);
        if (root->right)MemoryClear(root->right);
        delete root;
        root = nullptr;
    }
}

template<typename keyType, typename valueType > void AvlTree3<keyType, valueType>::push(keyType key, valueType value) { AddRec(tree1, key, value); }

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::delete_key(keyType key, valueType value) { DeleteRec(tree1, key, value); }

template<typename keyType, typename valueType> elem<keyType, valueType>* AvlTree3<keyType, valueType>::search_key(keyType key, valueType value) {
    elem<keyType, valueType>* res = nullptr;
    SearchElementRec(tree1, key, value, res);
    return res;
}

template<typename keyType, typename valueType> void AvlTree3<keyType, valueType>::print() { PrintTreeRec(tree1, 1); }

template<typename keyType, typename valueType> AvlTree3<keyType, valueType>::~AvlTree3() { MemoryClear(tree1); }

//========================================ШЕХ ТАБЛИЦЫ========================================//

class HashTable1
{
private:
    Order** table;
    char* status;
    unsigned int _userSize;
    unsigned int _size;
    unsigned int count = 0;
public:
    HashTable1(unsigned int size)
    {
        _size = size;
        _userSize = size;
        table = new Order*[_size];
        //for(int i = 0; i < _size; i++)table[i]
        status = new char[_size];
        memset(status, 0, _size);
    }

    int HashFunc(Order* hash_key)
    {
        int hash = hash_key->getStartDate().getDay() + hash_key->getStartDate().getMonth() + hash_key->getStartDate().getYear();
        for (int i = 0; i < hash_key->getLogin().length(); i++)hash += hash_key->getLogin()[i];
        for (int i = 0; i < hash_key->getName().length(); i++)hash += hash_key->getName()[i];
        for (int i = 0; i < hash_key->getCompany().length(); i++)hash += hash_key->getCompany()[i];
        return ((hash * hash) / 10) % _size;
    }

    int CollideFunc(int hash, int stp)
    {
        return (hash + 1 * stp + 2 * stp * stp) % _size;
    }

    void Print()
    {
        for (int i = 0; i < _size; i++)
        {
            //if (status[i] == 1)std::cout << "Hash:" << i << " value:" << table[i].passangerName << ' ' << table[i].flightNumbers << " " << table[i].day << ":" << table[i].month << ":" << table[i].year << " " << HashFunc(table[i]) << std::endl;
        }
    }

    int Find(Order* key)
    {
        int hash = HashFunc(key);
        if (status[hash] != 0)
        {
            if (table[hash] == key && status[hash] == 1)
            {
                return hash;
            }
            else
            {
                return colFind(hash, key);
            }
        }
        else return -1;
    }

    int colFind(int hash, Order* key)
    {
        int i = 1;
        int col = CollideFunc(hash, i);
        while (status[col] != 0 && i <= _size && !(table[col] == key && status[col] == 1))col = CollideFunc(hash, ++i);
        if (table[col] == key && status[col] == 1)return col;
        else return -1;
    }

    void Add(Order* key)
    {
        int hash = HashFunc(key);
        if (status[hash] != 1)
        {
            int i = 1;
            int col = CollideFunc(hash, i);
            while (status[col] != 0 && !(table[col] == key && status[col] == 1) && i <= _size)col = CollideFunc(hash, ++i);
            if (!(table[col] == key && status[col] == 1))
            {
                table[hash] = key;
                status[hash] = true;
                count++;
            }
            else
            {
                //std::cout << "~Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
            }
        }
        else if (!(table[hash] == key && status[hash] == 1))
        {
            colAdd(hash, key);
        }
        else
        {
            //std::cout << "+Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
        }
        if ((float(count) / _size) > 0.75)Resize(_size + _userSize);
    }

    void colAdd(int hash, Order* key)
    {
        bool isAdded = false;
        int i = 1;
        int col = CollideFunc(hash, i);
        while (status[col] != 0 && !(table[col] == key) && i <= _size)col = CollideFunc(hash, ++i);
        if (status[col] <= 0)
        {
            table[col] = key;
            status[col] = true;
            count++;
            isAdded = true;
        }
        else if (table[hash] == key)
        {
            //std::cout << "-Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
        }

        if (!isAdded)
        {
            Resize(_size + _userSize);
            Add(key);
        }
    }

    void Delete(Order* key)
    {
        int hash = HashFunc(key);
        if (status[hash] != 0)
        {
            if (table[hash] == key && status[hash] == 1)
            {
                int i = 1;
                int col = CollideFunc(hash, i);
                int last = hash;
                while (status[col] != 0 && i <= _size)
                {
                    if (HashFunc(table[col]) == hash && status[col] == 1)last = col;
                    col = CollideFunc(hash, ++i);
                }
                table[hash] = table[last];
                status[last] = -1;
                count--;
            }
            else
            {
                colDel(hash, key);
            }
            if ((_userSize <= _size - _userSize) && ((float(count) / _size) < 0.25))
            {
                Resize(_size - _userSize);
            }
        }
        else
        {
            //std::cout << "Nothing to delete: " << key.passangerName << " " << key.flightNumbers << std::endl;
        }
    }

    void colDel(int hash, Order* key)
    {
        int del = -1;
        int i = 1;
        int col = CollideFunc(hash, i);
        int last = hash;
        while (status[col] != 0 && i <= _size)
        {
            if (table[col] == key && status[col] == 1)del = col;
            if (HashFunc(table[col]) == hash && status[col] == 1)last = col;
            col = CollideFunc(hash, ++i);
        }
        if (del == -1)
        {
            //std::cout << "nothing to delete: " << key.passangerName << " " << key.flightNumbers << std::endl;
        }
        else
        {
            table[del] = table[last];
            status[last] = -1;
            count--;
        }
    }

    void Resize(int newSize)
    {
        Order** oldTable = table;
        char* oldStatus = status;
        int oldSize = _size;
        table = new Order*[newSize];
        status = new char[newSize];
        _size = newSize;
        count = 0;
        memset(status, 0, _size);
        for (int i = 0; i < oldSize; i++) { if (oldStatus[i] == 1) { Add(oldTable[i]); } };
        delete[] oldStatus;
        delete[] oldTable;
    }

    ~HashTable1()
    {
        delete[] table;
        delete[] status;
    }

};


class HashTable2
{
private:
    //структура для хт таблицы
    struct htnode
    {
        Client* _data;
        char _status;
        int _PrimeHash;
        //тож конструктор
        htnode(Client* data = nullptr, int status = 0, int PrimeHash = -1)
        {
            _data = data;
            _status = status;
            _PrimeHash = PrimeHash;
        }
    };

    //сама таблица
    htnode* table;
    //размер таблицы
    int size;
public:
    //конструктор
    HashTable2(int n)
    {
        size = n;
        //инициализация таблицы
        table = new htnode[size];
    }
    //первая хф
    int FisrtHashFunction(std::string key)
    {
        //перевод строки в числа
        int result = 0;
        //модуль нужен тк код символа может быть с минусом
        for (int i = 0; i < key.length(); i++)result += abs(key[i]);
        return result % size;
    }
    //вторая хв
    int SecondHashFunction(std::string key)
    {
        int result = 0;
        for (int i = 0; i < key.length(); i++)result += abs(key[i]);
        return 1 + result % (size - 2);
    }
    //функция коллизии
    int CollisionFunction(int hash1, int hash2, int i)
    {
        return (hash1 + i * hash2) % size;
    };
    //добавление
    void Add(Client* userInput)
    {
        //получаем хеш
        int hash = FisrtHashFunction(userInput->getLogin());
        //если ячейка имеет статус 0 или 2, те свободна
        // если статус ноль, то добавля. иначе разрешаю коллизию
        if (table[hash]._status != 1)
        {
            int hash2 = SecondHashFunction(userInput->getLogin());
            int i = 1;
            int collision = CollisionFunction(hash, hash2, i);
            while (table[collision]._status != 0 && !(userInput == table[collision]._data && table[collision]._status == 1) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
            if (!(userInput == table[collision]._data))
            {
                table[hash]._status = 1;
                table[hash]._data = userInput;
                table[hash]._PrimeHash = hash;
            }
            else
            {
                //cout << "уже есть" << endl;
            }
        }
        //если ячейка занята то идем добавлять через коллизию
        else if (!(userInput == table[hash]._data))
        {
            collisionAdd(hash, userInput);
        }
        else
        {
            //cout << "уже есть" << endl;
        }
    }
    //добавление с коллизией
    void collisionAdd(int hash, Client*& userInput)
    {
        //зарание получаем второй хеш для коллизии
        int hash2 = SecondHashFunction(userInput->getLogin());
        //переменная нужна, чтоб отслеживать был ли добавлен ключ или нет
        int i = 1;
        int possibleId = -1;
        int collision = CollisionFunction(hash, hash2, i);
        //пробегаем по таблице(убрать брейки, переписать на вайл, пока колиечество попыток вставки не превысят размерность, либо не встречу ячейку с таким ключом)
        while (table[collision]._status != 0 && !(userInput == table[collision]._data && table[collision]._status == 1) && i <= size)
        {
            if (possibleId == -1 && table[collision]._status == 2)possibleId = collision;
            collision = CollisionFunction(hash, hash2, ++i);
        }
        if (!(userInput == table[collision]._data) && table[collision]._status == 0)
        {
            if (possibleId != -1)
            {
                table[possibleId]._status = 1;
                table[possibleId]._data = userInput;
                table[possibleId]._PrimeHash = hash;
            }
            else
            {
                table[collision]._status = 1;
                table[collision]._data = userInput;
                table[collision]._PrimeHash = hash;
            }
        }
        //если не смогли добавить, то пишем, что нет места
        //else cout << "невозможно добавить " << userInput._fio << " " << userInput._hour << ":" << userInput._min << ":" << userInput._sec << endl;

    }
    //удаление
    void Delete(Client* userInput)
    {
        int hash = FisrtHashFunction(userInput->getLogin());

        //если ключ совпадает и ячейка занята
        if (userInput == table[hash]._data && table[hash]._status == 1)
        {
            //то меняем статус на удалено
            table[hash]._status = 2;
        }
        //аналогично с добавлением
        else
        {
            collisionDelete(hash, userInput);
        }
    }
    // брейк убрать, фор заменить на вайл,
    void collisionDelete(int hash, Client* userInput)
    {
        int hash2 = SecondHashFunction(userInput->getLogin());
        int i = 1;
        int collision = CollisionFunction(hash, hash2, i);
        while (table[collision]._status != 0 && !(userInput == table[collision]._data) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
        if (userInput == table[collision]._data && table[collision]._status == 1)
        {
            table[collision]._status = 2;
        }
        else
        {
            //cout << "Твой ключ находится в другой хеш таблице" << endl;
        }

    }
    //поиск
    int search(Client* userInput)
    {
        int hash = FisrtHashFunction(userInput->getLogin());
        //тоже самое что и до этого было
        if (userInput == table[hash]._data && table[hash]._status == 1) {
            //cout << "Существует" << endl;
            return hash;
        }
        else

            return collisionSearch(hash, userInput);
    }
    // фор заменить на вайл, идем пока количество попыток встакви не превысят размерность таблицы или не нашел такой же
    int collisionSearch(int hash, Client* userInput)
    {
        int hash2 = SecondHashFunction(userInput->getLogin());
        int i = 1;
        int collision = CollisionFunction(hash, hash2, i);
        while (table[collision]._status != 0 && !(userInput == table[collision]._data) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
        if (userInput == table[collision]._data)
        {
            //cout << "Существует" << endl;
            return collision;
        }
        else
           // cout << "Не существует" << endl;
        return -1;
    }

    void print()
    {
        //просто пробегаеемся по всей таблице и ищем занятые ячейки
        for (int i = 0; i < size; i++)
        {
            if (table[i]._status == 1)
            {
                //cout << i << " - " << table[i]._data._fio << " " << table[i]._data._hour << ":" << table[i]._data._min << ":" << table[i]._data._sec << " " << table[i]._data._aud << " " << table[i]._PrimeHash << endl;
            }
        }
    }
    //деструктор
    ~HashTable2()
    {
        delete[] table;
    }

};

class HashTable3 {
public:
    int k = 0;
    int size;
    int usersize;
    int count = 0;
    Subscribe** data;
    int* status;
    double fullness;
    HashTable3(int size)
    {
        this->size = size;
        usersize = size;
        data = new Subscribe * [size];
        status = new int[size];
        for (int i = 0; i < size; i++) { status[i] = 0; }
    }

    void setK(int a)
    {
        if (a > 1)
        {
            k = a;
            //cout << "K = " << a << " установлен" << endl;
        }
        //else cout << "Данные некорректны" << endl;
    }

    int stringToInt(const std::string& str) {
        int result = 0;
        for (char c : str) {
            int asciiCode = int(c) + '0';
            result += asciiCode;
        }
        return result;
    }

    unsigned cap(const unsigned x) {
        return x ? ceil(log10(x + 1)) : 1;
    }

    int primary_hash(std::string name, std::string company)
    {
        int buf = 0;
        int key = stringToInt(name) + stringToInt(company);
        buf = ((key % 100) + (key % 10000 / 100) + (key / 10000)) * ((key % 100) + (key % 10000 / 100) + (key / 10000));
        //cout << buf << endl;
        if (cap(buf) == 1) return (buf % size);
        if (cap(buf) == 2) return (buf % size);
        if (cap(buf) == 3) return (buf / 10 % size);
        if (cap(buf) == 4) return (buf / 10 % 100 % size);
        if (cap(buf) == 5) return (buf / 100 % 100 % size);
        if (cap(buf) == 6) return (buf / 100 % 100 % size);
    }

    int secondary_hash(int hash, int i, int k)
    {
        return (hash + i * k) % size;
    }

    void print() {
        for (int i = 0; i < size; i++)
        {
            /*if (status[i] == 1)cout << i << " " << data[i].time.hours << ":" << data[i].time.min << " "
                << data[i].fullname.lastName << " " << data[i].fullname.name << " " << data[i].fullname.patronymic << " " << data[i].aud.audletter << " " << data[i].aud.audnumber << endl;
            if (status[i] == 2) cout << i << " " << "Запись удалена" << endl;
            if (status[i] == 0) cout << i << " " << "Ячейка пуста" << endl;*/
        }
    }

    void checkfullness()
    {
        fullness = ((double)count / size);
    }

    int add_coll_resol(Subscribe* object, int index, int& attempt, bool& isAdded)
    {
        int potential = -1;
        while (attempt <= size && isAdded == false && potential == -1)
        {
            int step = secondary_hash(index, attempt, k);
            if (status[step] == 0 || status[step] == 2)
            {
                potential = step;
            }
            attempt++;
        }
        return potential;
    }
    void add(Subscribe* object) {
        bool isAdded = false;
        int index = primary_hash(object->getName(), object->getCompany());
        int attempt = 0;
        if (status[index] == 0 || status[index] == 2)
        {
            data[index] = object;
            status[index] = 1;
            count++;
            isAdded = true;
            // cout << "Вставлено с " << attempt << " попытки" << endl;
            checkfullness();
            return;
        }
        else
        {

            int index1 = add_coll_resol(object, index, attempt, isAdded);
            if (data[index] == object)
            {
                //cout << "Такой элемент уже существует" << endl;
                return;
            }
            else
            {
                if (index1 != -1) {
                    data[index1] = object;
                    status[index1] = 1;
                    count++;
                    //    cout << "Вставлено с " << attempt << " попытки" << endl;
                    checkfullness();
                    return;
                }
                else
                {
                    resizetable(size + usersize);
                    checkfullness();
                    if (!isAdded)add(object);
                }

            }
        }
        if (fullness >= 0.75 || !isAdded)
        {
            resizetable(size + usersize);
            checkfullness();
            if (!isAdded)add(object);
        }
    }

    int remove_coll_resol(Subscribe* object, int index, int& attempt)
    {
        int potential = -1;
        while (attempt <= size && potential == -1)
        {
            int step = secondary_hash(index, attempt, k);
            if (data[step] == object)
            {
                potential = step;
            }
            attempt++;
        }
        return potential;
    }
    void remove(Subscribe* object)
    {
        int index = primary_hash(object->getName(), object->getCompany());
        int attempt = 0;
        if (status[index] == 1 && data[index] == object)
        {
            count--;
            status[index] = 2;
            checkfullness();
            return;
        }
        else
        {
            int index1 = remove_coll_resol(object, index, attempt);
            count--;
            status[index1] = 2;
            checkfullness();
            return;
        }

        if (!status[index]) return;

        if (fullness <= 0.25)
        {
            resizetable(size - usersize);
            checkfullness();
        }
    }

    void resizetable(int newsize)
    {
        Subscribe** oldTable = data;
        int* oldStatus = status;
        int oldSize = size;
        data = new Subscribe * [newsize];
        status = new int[newsize];
        if (newsize < usersize)size = usersize;
        else size = newsize;
        count = 0;
        memset(status, 0, size);
        for (int i = 0; i < oldSize; i++) { if (oldStatus[i] == 1) { add(oldTable[i]); } };
        delete[] oldStatus;
        delete[] oldTable;
    }

    bool find(Subscribe* object)
    {
        int attempt = 0;
        int index = primary_hash(object->getName(), object->getCompany());
        int step = secondary_hash(index, attempt, k);
        if (status[index] == 1 && data[index]->getName() == object->getName() && data[index]->getCompany() == object->getCompany() && data[index]->getCost() == object->getCost() && data[index]->getMinimalDuration() == object->getMinimalDuration())
        {
            //cout << "Элемент был найден." << endl;
            return true;
        }
        else
        {
            while (attempt <= size)
            {
                step = secondary_hash(index, attempt, k);
                attempt++;
                if (attempt > size || status[step] == 0)
                {
                    //cout << "Элемент не был найден." << endl;
                    return false;
                }
                if (status[index] == 1 && data[index]->getName() == object->getName() && data[index]->getCompany() == object->getCompany() && data[index]->getCost() == object->getCost() && data[index]->getMinimalDuration() == object->getMinimalDuration())
                {
                    //cout << "Элемент был найден." << endl;
                    return true;
                }
            }
        }
    }


    ~HashTable3() {
        delete[] data;
        delete[] status;
    }
};