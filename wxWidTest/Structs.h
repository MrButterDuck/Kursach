#pragma once
#include <iostream>
#include "DataTypes.h"
#include <memory.h>
#include <typeinfo>

//========================================—ѕ»— »========================================//
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
    bool push_back(Type value);
    bool delete_by_value(Type value);
    bool delete_by_id(int i);
    Type* get_data_by_id(int i);
    node0<Type>* get_node_by_id(int i);
    bool is_empty();
    unsigned int getCount();
    void print(std::string &line);
    ~CycleList();
};

template<typename Type>
class TwoPointList {
private:
    node1<Type>* head;
    unsigned int count;
public:
    TwoPointList();
    bool push_back(Type data);
    void delete_element(Type data);
    node1<Type>* search_element(Type data);
    void print_list(std::string &line);
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
    bool push_back(Type data);
    void delete_element(Type data);
    node2<Type>* search_element(Type data);
    void print_list(std::string &line);
    Type* get_element(int i);
    unsigned int getCount();

    ~OnePointList();
};

//========================================ƒ≈–≈¬№я========================================//
template< typename valueType>
struct Node
{
    CycleList<valueType> *value;
    std::string key;
    struct Node< valueType>* left;
    struct Node< valueType>* right;
    char balance;
    Node(std::string newKey, valueType newValue) { key = newKey, value = new CycleList<valueType>(); value->push_back(newValue); left = nullptr; right = nullptr; balance = 0; }
};

template< typename valueType>
struct treeNode {
    treeNode* leftChild;
    treeNode* rightChild;
    int balanceFactor;
    OnePointList<valueType> *value;
    std::string head;
    treeNode(std::string newKey, valueType newValue) { head = newKey; value = new OnePointList<valueType>(); value->push_back(newValue); leftChild = nullptr; rightChild = nullptr; balanceFactor = 0; }
    // список
    treeNode(std::string newKey, OnePointList<valueType>* newValue) { head = newKey; value = newValue; leftChild = nullptr; rightChild = nullptr; balanceFactor = 0; }
};

template< typename valueType>
struct elem
{
    std::string key;
    TwoPointList<valueType>* value;
    struct elem< valueType>* left;
    struct elem< valueType>* right;
    char balance;
    elem(std::string newKey, valueType newValue) { this->key = newKey; value = new TwoPointList<valueType>(); value->push_back(newValue); left = nullptr; right = nullptr; balance = 0; }
};


template<typename valueType>
class AvlTree1 {
private:
    Node<valueType>* tree1;
    bool h;
    void BalanceL(Node<valueType>*& root);
    void BalanceR(Node<valueType>*& root);
    void Del(Node<valueType>*& r, Node< valueType>*& q);
    void AddRec(Node<valueType>*& root, std::string key, valueType value);
    void DeleteRec(Node<valueType>*& root, std::string key, valueType value);
    void SearchElementRec(Node< valueType>* root, std::string key, Node< valueType>*& res);
    void PrintTreeRec(Node<valueType>* root, int h, std::string &line);
    void MemoryClear(Node<valueType>*& root);

public:
    AvlTree1();
    void push(std::string key, valueType value);
    void delete_key(std::string key, valueType value);
    Node<valueType>* search_key(std::string key);
    std::string print();
    ~AvlTree1();
};

template<typename valueType>
class AvlTree2 {
private:
    treeNode< valueType>* tree1;
    bool heightChanged;
    void addNode(treeNode< valueType>*& pointer, std::string key, valueType value);
    void printTree(treeNode<valueType>* root, int h, std::string &line);
    void _deleteTree(treeNode<valueType>*& pointer);
    treeNode< valueType>* deleteTree(treeNode<valueType>*& root);
    void _del_balanceLeft(treeNode<valueType>*& node);
    void _del_balanceRight(treeNode<valueType>*& node);
    void _delWhenTwoChild(treeNode<valueType>*& node, treeNode<valueType>*& delNode);
    void delNode(treeNode<valueType>*& pointer, std::string key, valueType value);
    void searchTreeNode(treeNode<valueType>* pointer, std::string key, treeNode<valueType>*& res);

public:
    AvlTree2();
    void push(std::string key, valueType value);
    void delete_key(std::string key, valueType value);
    treeNode<valueType>* search_key(std::string key);
    std::string print();
    ~AvlTree2();
};

template<typename valueType>
class AvlTree3 {
private:
    elem< valueType>* tree1;
    bool h;
    void BalanceL(elem<valueType>*& root);
    void BalanceR(elem<valueType>*& root);
    void Del(elem< valueType>*& r, elem< valueType>*& q);
    void AddRec(elem< valueType>*& root, std::string key, valueType value);
    void DeleteRec(elem< valueType>*& root, std::string key, valueType value);
    void SearchElementRec(elem< valueType>* root, std::string key,  elem< valueType>*& res);
    void PrintTreeRec(elem< valueType>* root, int h, std::string &line);
    void MemoryClear(elem< valueType>*& root);

public:
    AvlTree3();
    void push(std::string key, valueType value);
    void delete_key(std::string key, valueType value);
    elem<valueType>* search_key(std::string key);
    std::string print();
    ~AvlTree3();
};

//========================================—ѕ»— »========================================//
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

template<typename Type>bool CycleList<Type>::push_back(Type value)
{
    if (!this->head) {
        head = new node0<Type>(value);
        this->size++;
        return true;
    }
    else
    {
        node0<Type>* buffer = this->head;
        while (buffer->next != this->head && buffer->data != value)buffer = buffer->next;
        if (buffer->data != value) {
            buffer->next = new node0<Type>(value, this->head);
            this->size++;
            return true;
        }
        else return false;
    }
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

template<typename Type> void CycleList<Type>::print(std::string &line)
{
    node0<Type>* buffer = this->head;
    if (this->head)
    {
        int i = 1;
        while (buffer->next != this->head)
        {
            line += std::to_string(buffer->data) + ",";
            buffer = buffer->next;
        }
        line += std::to_string(buffer->data);
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

template<typename Type> bool TwoPointList<Type>::push_back(Type data) {
    if (head) {
        if (head->data > data) {
            node1<Type>* newData = new node1<Type>(data, head, head);
            head->past = newData;
            head = newData;
            this->count++;
            return true;
        }
        else {
            node1<Type>* buffer = head;
            while (buffer->data < data && buffer->next != nullptr)buffer = buffer->next;
            if (buffer->data < data) {
                node1<Type>* newData = new node1<Type>(data, buffer->next, buffer);
                buffer->next = newData;
                this->count++;
                return true;
            }
            else if (buffer->data > data) {
                node1<Type>* newData = new node1<Type>(data, buffer, buffer->past);
                buffer->past = newData;
                if (head == buffer)head = newData;
                else buffer->past->next = newData;
                this->count++;
                return true;
            }
            else return false;
        }
    }
    else {
        head = new node1<Type>(data);
        this->count++;
        return true;
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

template<typename Type> void TwoPointList<Type>::print_list(std::string &line) {
    if (head) {
        node1<Type>* buffer = head;
        while (buffer != nullptr) {
            line += std::to_string(buffer->data) + ",";
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

template<typename Type> bool OnePointList<Type>::push_back(Type data) {
    if (head) {
        if (head->data == data)return false;
        if (head->data > data) {
            node2<Type>* newData = new node2<Type>(data, head);
            head = newData;
            this->count++;
            return true;
        }
        else {
            node2<Type>* buffer = head;
            while (buffer->next != nullptr && buffer->next->data < data)buffer = buffer->next;
            if(buffer->next != nullptr && buffer->next->data == data)return false;
            node2<Type>* newData = new node2<Type>(data, buffer->next);
            buffer->next = newData;
            this->count++;
            return true;
        }
    }
    else {
        head = new node2<Type>(data);
        this->count++;
        return true;
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

template<typename Type>  void OnePointList<Type>::print_list(std::string &line) {
    if (head) {
        node2<Type>* buffer = head;
        while (buffer != nullptr) {
            line += std::to_string(buffer->data) + ",";
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

//========================================ƒ≈–≈¬№я========================================//
template< typename valueType> AvlTree1< valueType>::AvlTree1() {
    this->tree1 = nullptr;
    this->h = false;
}

template<typename valueType>  void AvlTree1< valueType>::BalanceL(Node<valueType>*& root) {
    Node< valueType>* p1;
    Node< valueType>* p2;
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

template<typename valueType>  void AvlTree1< valueType>::BalanceR(Node<valueType>*& root) {
    Node< valueType>* p1;
    Node< valueType>* p2;
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

template< typename valueType>  void AvlTree1< valueType>::AddRec(Node< valueType>*& root, std::string key, valueType value) {
    Node< valueType>* p1;
    Node< valueType>* p2;
    if (!root)
    {
        root = new Node<valueType>(key, value);
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

template< typename valueType>  void AvlTree1< valueType>::Del(Node< valueType>*& r, Node< valueType>*& q) {
    if (r->right)
    {
        Del(r->right, q);
        if (h)BalanceR(r);
    }
    else
    {
        q->key = r->key;
        q->value = r->value;
        q = r;
        r = r->left;
        h = true;
    }
}

template< typename valueType> void AvlTree1< valueType>::DeleteRec(Node< valueType>*& root, std::string key, valueType value) {
    Node< valueType>* q;
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
        if (this->tree1->value->getCount() > 1)this->tree1->value->delete_by_id(value);
        else {
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
}

template<typename valueType> void AvlTree1< valueType>::SearchElementRec(Node< valueType>* root, std::string key,  Node< valueType>*& res) {
    if (root->key == key)res = root;
    if (root->left)SearchElementRec(root->left, key,  res);
    if (root->right)SearchElementRec(root->right, key,  res);
}

template< typename valueType>  void AvlTree1< valueType>::PrintTreeRec(Node< valueType>* root, int h, std::string &line) {
    if (root)
    {
        PrintTreeRec(root->right, h + 4, line);
        for (int i = 1; i <= h; i++)line += " ";
        line += root->key;
        line += " [";
        root->value->print(line);
        line += "]\n";
        PrintTreeRec(root->left, h + 4, line);
    }
}

template<typename valueType>  void AvlTree1< valueType>::MemoryClear(Node< valueType>*& root) {
    if (root) {
        if (root->left)MemoryClear(root->left);
        if (root->right)MemoryClear(root->right);
        delete root;
        root = nullptr;
    }
}

template<typename valueType>  void AvlTree1< valueType>::push(std::string key, valueType value) { AddRec(tree1, key, value); }

template<typename valueType>  void AvlTree1< valueType>::delete_key(std::string key, valueType value) { DeleteRec(tree1, key, value); }

template<typename valueType>  Node< valueType>* AvlTree1< valueType>::search_key(std::string key) {
    Node< valueType>* res = nullptr;
    SearchElementRec(tree1, key, res);
    return res;
}

template<typename valueType>  std::string AvlTree1< valueType>::print() { std::string line; PrintTreeRec(tree1, 1, line); return line; }

template<typename valueType> AvlTree1< valueType>::~AvlTree1() { MemoryClear(tree1); }

template<typename valueType> AvlTree2< valueType>::AvlTree2() {
    this->tree1 = nullptr;
    this->heightChanged = false;
}

template< typename valueType> void AvlTree2< valueType>::printTree(treeNode< valueType>* root, int h, std::string &line) {
    if (root)
    {
        printTree(root->rightChild, h + 4, line);
        for (int i = 1; i <= h; i++)line += " ";
        line += root->head;
        line += "[";
        root->value->print_list(line);
        line += "]\n";
        printTree(root->leftChild, h + 4, line);
    }
}

template<typename valueType> void AvlTree2< valueType>::addNode(treeNode< valueType>*& pointer, std::string key, valueType value) {
    treeNode< valueType>* pointer1, * pointer2;
    if (pointer == nullptr) {
        heightChanged = true;
        pointer = new treeNode< valueType>(key, value);

    }
    else if (pointer->head > key) {
        addNode(pointer->leftChild, key, value);
        if (heightChanged) { // выросла лева€ часть 
            if (pointer->balanceFactor == 1) {
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
            else if (pointer->balanceFactor == 0) {
                pointer->balanceFactor = -1;
            }
            else {
                pointer2 = new treeNode< valueType>(key, value);
                pointer1 = new treeNode< valueType>(key, value);
                pointer1 = pointer->leftChild;
                if (pointer1->balanceFactor == -1) { //одиночна€ LL-ротаци€
                    pointer->leftChild = pointer1->rightChild;
                    pointer1->rightChild = pointer;
                    pointer->balanceFactor = 0;
                    pointer = pointer1;
                }
                else { //двойна€ LR ротаци€
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
        if (heightChanged) { //выросла права€ часть 
            if (pointer->balanceFactor == -1) {
                pointer->balanceFactor = 0;
                heightChanged = false;
            }
            else if (pointer->balanceFactor == 0) {
                pointer->balanceFactor = 1;
            }
            else {
                pointer2 = new treeNode< valueType>(key, value);
                pointer1 = new treeNode< valueType>(key, value);
                pointer1 = pointer->rightChild;
                if (pointer1->balanceFactor == 1) { // одиночан€ RR ротаци€ 
                    pointer->rightChild = pointer1->leftChild;
                    pointer1->leftChild = pointer;
                    pointer->balanceFactor = 0;
                    pointer = pointer1;
                }
                else { // двойна€ RL ротаци€ 
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

template< typename valueType> void AvlTree2< valueType>::_deleteTree(treeNode< valueType>*& pointer) {
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

template<typename valueType> treeNode< valueType>* AvlTree2< valueType>::deleteTree(treeNode< valueType>*& root) {
    _deleteTree(root);
    root = nullptr;
    return root;
}

template< typename valueType> void AvlTree2< valueType>::_del_balanceLeft(treeNode< valueType>*& node) {
    treeNode< valueType>* pointer1, * pointer2;
    if (node->balanceFactor == -1) node->balanceFactor = 0;
    else if (node->balanceFactor == 0) {
        node->balanceFactor = 1;
        heightChanged = false;
    }
    else {
        pointer1 = new treeNode< valueType>(node->head, node->value);
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
            pointer2 = new treeNode< valueType>(node->head, node->value);
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

template< typename valueType> void AvlTree2< valueType>::_del_balanceRight(treeNode< valueType>*& node) {
    treeNode< valueType>* pointer1, * pointer2;
    if (node->balanceFactor == 1) node->balanceFactor = 0;
    else if (node->balanceFactor == 0) {
        node->balanceFactor = -1;
        heightChanged = false;
    }
    else {
        pointer1 = new treeNode< valueType>(node->head, node->value);
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
            pointer2 = new treeNode< valueType>(node->head, node->value);
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

template< typename valueType> void AvlTree2< valueType>::_delWhenTwoChild(treeNode< valueType>*& node, treeNode< valueType>*& delNode) {
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

template< typename valueType> void AvlTree2< valueType>::delNode(treeNode< valueType>*& pointer, std::string key, valueType value) {
    treeNode< valueType>* temp = nullptr;
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

template< typename valueType> void AvlTree2< valueType>::searchTreeNode(treeNode< valueType>* pointer, std::string key,treeNode<valueType>*& res) {
    if (pointer != NULL) {
        if (pointer->head > key) {
            if (pointer->leftChild != nullptr) {
                searchTreeNode(pointer->leftChild, key,  res);
            }
        }
        else if (pointer->head < key) {
            if (pointer->rightChild != nullptr) {
                searchTreeNode(pointer->rightChild, key,  res);
            }
        }
        else {
            res = pointer;
        }
    }
}

template< typename valueType> void AvlTree2< valueType>::push(std::string key, valueType value) { addNode(tree1, key, value); }

template<typename valueType> void AvlTree2< valueType>::delete_key(std::string key, valueType value) { delNode(tree1, key, value); }

template< typename valueType> treeNode< valueType>* AvlTree2< valueType>::search_key(std::string key ) {
    treeNode< valueType>* res = nullptr;
    searchTreeNode(tree1, key, res);
    return res;
}

template< typename valueType> std::string AvlTree2< valueType>::print() { std::string line; printTree(tree1, 1, line); return line; }

template< typename valueType> AvlTree2< valueType>::~AvlTree2() { deleteTree(tree1); }

template< typename valueType> AvlTree3< valueType>::AvlTree3() {
    this->tree1 = nullptr;
    this->h = false;
}

template< typename valueType> void AvlTree3< valueType>::BalanceL(elem< valueType>*& root) {
    elem< valueType>* p1;
    elem< valueType>* p2;
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

template< typename valueType> void AvlTree3< valueType>::BalanceR(elem< valueType>*& root) {
    elem< valueType>* p1;
    elem< valueType>* p2;
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

template< typename valueType> void AvlTree3< valueType>::AddRec(elem< valueType>*& root, std::string key, valueType value) {
    elem< valueType>* p1;
    elem< valueType>* p2;
    if (!root)
    {
        root = new elem< valueType>(key,value );
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

template<typename valueType> void AvlTree3< valueType>::Del(elem< valueType>*& r, elem< valueType>*& q) {
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

template< typename valueType> void AvlTree3< valueType>::DeleteRec(elem< valueType>*& root, std::string key, valueType value) {
    elem< valueType>* q;
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

template<typename valueType> void AvlTree3< valueType>::SearchElementRec(elem< valueType>* root, std::string key, elem< valueType>*& res) {
    if (root->key == key)res = root;
    if (root->left)SearchElementRec(root->left, key, res);
    if (root->right)SearchElementRec(root->right, key, res);
}

template< typename valueType> void AvlTree3< valueType>::PrintTreeRec(elem< valueType>* root, int h, std::string &line) {
    if (root)
    {
        PrintTreeRec(root->right, h + 4, line);
        line += root->key;
        line += " [";
        root->value->print_list(line);
        line += "]\n";
        PrintTreeRec(root->left, h + 4, line);
    }
}

template< typename valueType> void AvlTree3< valueType>::MemoryClear(elem< valueType>*& root) {
    if (root) {
        if (root->left)MemoryClear(root->left);
        if (root->right)MemoryClear(root->right);
        delete root;
        root = nullptr;
    }
}

template<typename valueType > void AvlTree3< valueType>::push(std::string key, valueType value) { AddRec(tree1, key, value); }

template<typename valueType> void AvlTree3< valueType>::delete_key(std::string key, valueType value) { DeleteRec(tree1, key, value); }

template<typename valueType> elem< valueType>* AvlTree3< valueType>::search_key(std::string key) {
    elem< valueType>* res = nullptr;
    SearchElementRec(tree1, key, res);
    return res;
}

template< typename valueType> std::string AvlTree3< valueType>::print() { std::string line; PrintTreeRec(tree1, 1, line); return line; }

template<typename valueType> AvlTree3< valueType>::~AvlTree3() { MemoryClear(tree1); }

//========================================Ў≈’ “јЅЋ»÷џ========================================//

class HashTable1
{
private:
    Order* table;
    int* value;
    char* status;
    unsigned int _userSize;
    unsigned int _size;
    unsigned int count = 0;
public:
    HashTable1(unsigned int size)
    {
        _size = size;
        _userSize = size;
        table = new Order[_size];
        value = new int[_size];
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

    std::string Print()
    {
        std::string res = "";
        for (int i = 0; i < _size; i++)
        {
            if (status[i] == 1)res += std::to_string(i) + ": "+ table[i].getLogin() + " " + table[i].getName() + " " + table[i].getCompany() + " " + table[i].getStartDate().toString() + " = " + std::to_string(value[i]) + "\n";
        }
        return res;
    }

    int Find(Order* key)
    {
        int hash = HashFunc(key);
        if (status[hash] != 0)
        {
            if (table[hash] == *key && status[hash] == 1)
            {
                return value[hash];
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
        while (status[col] != 0 && i <= _size && !(table[col] == *key && status[col] == 1))col = CollideFunc(hash, ++i);
        if (table[col] == *key && status[col] == 1)return value[col];
        else return -1;
    }

    bool Add(Order* key, int id)
    {
        int hash = HashFunc(key);
        if (status[hash] != 1)
        {
            int i = 1;
            int col = CollideFunc(hash, i);
            while (status[col] != 0 && !(table[col] == *key && status[col] == 1) && i <= _size)col = CollideFunc(hash, ++i);
            if (!(table[col] == *key && status[col] == 1))
            {
                table[hash] = *key;
                status[hash] = true;
                value[hash] = id;
                count++;
                return true;
            }
            else
            {
                //std::cout << "~Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
                return false;
            }
        }
        else if (!(table[hash] == *key && status[hash] == 1))
        {
            return colAdd(hash, key, id);
        }
        else
        {
            //std::cout << "+Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
            return false;
        }
        if ((float(count) / _size) > 0.75)Resize(_size + _userSize);
    }

    bool colAdd(int hash, Order* key, int id)
    {
        bool isAdded = false;
        int i = 1;
        int col = CollideFunc(hash, i);
        while (status[col] != 0 && !(table[col] == *key) && i <= _size)col = CollideFunc(hash, ++i);
        if (status[col] <= 0)
        {
            table[col] = *key;
            status[col] = true;
            value[col] = id;
            count++;
            isAdded = true;
            return true;
        }
        else if (table[hash] == *key)
        {
            //std::cout << "-Already added: " << key.passangerName << " " << key.flightNumbers << std::endl;
            return false;
        }

        if (!isAdded)
        {
            Resize(_size + _userSize);
            return Add(key, id);
        }
    }

    void Delete(Order* key)
    {
        int hash = HashFunc(key);
        if (status[hash] != 0)
        {
            if (table[hash] == *key && status[hash] == 1)
            {
                int i = 1;
                int col = CollideFunc(hash, i);
                int last = hash;
                while (status[col] != 0 && i <= _size)
                {
                    if (HashFunc(&table[col]) == hash && status[col] == 1)last = col;
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
            if (table[col] == *key && status[col] == 1)del = col;
            if (HashFunc(&table[col]) == hash && status[col] == 1)last = col;
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
        Order* oldTable = table;
        int* oldValue = value;
        char* oldStatus = status;
        int oldSize = _size;
        table = new Order[newSize];
        value = new int[newSize];
        status = new char[newSize];
        _size = newSize;
        count = 0;
        memset(status, 0, _size);
        for (int i = 0; i < oldSize; i++) { if (oldStatus[i] == 1) { Add(&oldTable[i], oldValue[i]); } };
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
    //структура дл€ хт таблицы
    struct htnode
    {
        std::string _data;
        char _status;
        int _value;
        //тож конструктор
        htnode(std::string data = "", int status = 0, int value = -1)
        {
            _data = data;
            _status = status;
            _value = value;
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
        //инициализаци€ таблицы
        table = new htnode[size];
    }
    //перва€ хф
    int FisrtHashFunction(std::string key)
    {
        //перевод строки в числа
        int result = 0;
        //модуль нужен тк код символа может быть с минусом
        for (int i = 0; i < key.length(); i++)result += abs(key[i]);
        return result % size;
    }
    //втора€ хв
    int SecondHashFunction(std::string key)
    {
        int result = 0;
        for (int i = 0; i < key.length(); i++)result += abs(key[i]);
        return 1 + result % (size - 2);
    }
    //функци€ коллизии
    int CollisionFunction(int hash1, int hash2, int i)
    {
        return (hash1 + i * hash2) % size;
    };
    //добавление
    bool Add(std::string userInput, int id)
    {
        //получаем хеш
        int hash = FisrtHashFunction(userInput);
        //если €чейка имеет статус 0 или 2, те свободна
        // если статус ноль, то добавл€. иначе разрешаю коллизию
        if (table[hash]._status != 1)
        {
            int hash2 = SecondHashFunction(userInput);
            int i = 1;
            int collision = CollisionFunction(hash, hash2, i);
            while (table[collision]._status != 0 && !(userInput == table[collision]._data && table[collision]._status == 1) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
            if (!(userInput == table[collision]._data))
            {
                table[hash]._status = 1;
                table[hash]._data = userInput;
                table[hash]._value = id;
                return true;
            }
            else
            {
                //cout << "уже есть" << endl;
                return false;
            }
        }
        //если €чейка зан€та то идем добавл€ть через коллизию
        else if (!(userInput == table[hash]._data))
        {
            return collisionAdd(hash, userInput, id);
        }
        else
        {
            //cout << "уже есть" << endl;
            return false;
        }
    }
    //добавление с коллизией
    bool collisionAdd(int hash, std::string& userInput, int id)
    {
        //зарание получаем второй хеш дл€ коллизии
        int hash2 = SecondHashFunction(userInput);
        //переменна€ нужна, чтоб отслеживать был ли добавлен ключ или нет
        int i = 1;
        int possibleId = -1;
        int collision = CollisionFunction(hash, hash2, i);
        //пробегаем по таблице(убрать брейки, переписать на вайл, пока колиечество попыток вставки не превыс€т размерность, либо не встречу €чейку с таким ключом)
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
                table[possibleId]._value = id;
                return true;
            }
            else
            {
                table[collision]._status = 1;
                table[collision]._data = userInput;
                table[collision]._value = id;
                return true;
            }
        }
        //если не смогли добавить, то пишем, что нет места
        else return false;//cout << "невозможно добавить " << userInput._fio << " " << userInput._hour << ":" << userInput._min << ":" << userInput._sec << endl;

    }
    //удаление
    void Delete(std::string userInput)
    {
        int hash = FisrtHashFunction(userInput);

        //если ключ совпадает и €чейка зан€та
        if (userInput == table[hash]._data && table[hash]._status == 1)
        {
            //то мен€ем статус на удалено
            table[hash]._status = 2;
        }
        //аналогично с добавлением
        else
        {
            collisionDelete(hash, userInput);
        }
    }
    // брейк убрать, фор заменить на вайл,
    void collisionDelete(int hash, std::string userInput)
    {
        int hash2 = SecondHashFunction(userInput);
        int i = 1;
        int collision = CollisionFunction(hash, hash2, i);
        while (table[collision]._status != 0 && !(userInput == table[collision]._data) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
        if (userInput == table[collision]._data && table[collision]._status == 1)
        {
            table[collision]._status = 2;
        }
        else
        {
            //cout << "“вой ключ находитс€ в другой хеш таблице" << endl;
        }

    }
    //поиск
    int search(std::string userInput)
    {
        int hash = FisrtHashFunction(userInput);
        //тоже самое что и до этого было
        if (userInput == table[hash]._data && table[hash]._status == 1) {
            //cout << "—уществует" << endl;
            return table[hash]._value;
        }
        else

            return collisionSearch(hash, userInput);
    }
    // фор заменить на вайл, идем пока количество попыток встакви не превыс€т размерность таблицы или не нашел такой же
    int collisionSearch(int hash, std::string userInput)
    {
        int hash2 = SecondHashFunction(userInput);
        int i = 1;
        int collision = CollisionFunction(hash, hash2, i);
        while (table[collision]._status != 0 && !(userInput == table[collision]._data) && i <= size)collision = CollisionFunction(hash, hash2, ++i);
        if (userInput == table[collision]._data)
        {
            //cout << "—уществует" << endl;
            return table[collision]._value;
        }
        else
           // cout << "Ќе существует" << endl;
        return -1;
    }

    std::string Print()
    {
        std::string res = "";
        for (int i = 0; i < size; i++)
        {
            if (table[i]._status == 1)res += std::to_string(i) + ": " + table[i]._data + " = " + std::to_string(table[i]._value) + "\n";
        }
        return res;
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
    std::string* data;
    int* value;
    int* status;
    double fullness;
    HashTable3(int size)
    {
        this->size = size;
        usersize = size;
        data = new std::string [size];
        status = new int[size];
        value = new int[size];
        for (int i = 0; i < size; i++) { status[i] = 0; }
    }

    void setK(int a)
    {
        if (a > 1)
        {
            k = a;
            //cout << "K = " << a << " установлен" << endl;
        }
        //else cout << "ƒанные некорректны" << endl;
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

    int primary_hash(std::string* name)
    {
        int buf = 0;
        int key = stringToInt(*name);
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

    std::string Print()
    {
        std::string res = "";
        for (int i = 0; i < size; i++)
        {
            if (status[i] == 1)res += std::to_string(i) + ": " + data[i] + " = " + std::to_string(value[i]) + "\n";
        }
        return res;
    }

    void checkfullness()
    {
        fullness = ((double)count / size);
    }

    int add_coll_resol(std::string* object, int index, int& attempt, bool& isAdded, int id)
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
    bool add(std::string* object, int id) {
        bool isAdded = false;
        int index = primary_hash(object);
        int attempt = 0;
        if (status[index] == 0 || status[index] == 2)
        {
            data[index] = *object;
            status[index] = 1;
            value[index] = id;
            count++;
            isAdded = true;
            // cout << "¬ставлено с " << attempt << " попытки" << endl;
            checkfullness();
            return true;
        }
        else
        {

            int index1 = add_coll_resol(object, index, attempt, isAdded, id);
            if (data[index] == *object)
            {
                //cout << "“акой элемент уже существует" << endl;
                return false;
            }
            else
            {
                if (index1 != -1) {
                    data[index1] = *object;
                    status[index1] = 1;
                    value[index] = id;
                    count++;
                    //    cout << "¬ставлено с " << attempt << " попытки" << endl;
                    checkfullness();
                    return true;
                }
                else
                {
                    resizetable(size + usersize);
                    checkfullness();
                    if (!isAdded)return add(object, id);
                }

            }
        }
        if (fullness >= 0.75 || !isAdded)
        {
            resizetable(size + usersize);
            checkfullness();
            if (!isAdded)return add(object, id);
        }
    }

    int remove_coll_resol(std::string* object, int index, int& attempt)
    {
        int potential = -1;
        while (attempt <= size && potential == -1)
        {
            int step = secondary_hash(index, attempt, k);
            if (data[step] == *object)
            {
                potential = step;
            }
            attempt++;
        }
        return potential;
    }
    void remove(std::string* object)
    {
        int index = primary_hash(object);
        int attempt = 0;
        if (status[index] == 1 && data[index] == *object)
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
        std::string* oldTable = data;
        int* oldStatus = status;
        int oldSize = size;
        int* OldValue = value;
        data = new std::string[newsize];
        status = new int[newsize];
        value = new int[newsize];
        if (newsize < usersize)size = usersize;
        else size = newsize;
        count = 0;
        memset(status, 0, size);
        for (int i = 0; i < oldSize; i++) { if (oldStatus[i] == 1) { add(&oldTable[i], OldValue[i]); } };
        delete[] oldStatus;
        delete[] oldTable;
    }

    int find(std::string* object)
    {
        int attempt = 0;
        int index = primary_hash(object);
        int step = secondary_hash(index, attempt, k);
        if (status[index] == 1 && data[index] == *object)
        {
            //cout << "Ёлемент был найден." << endl;
            return value[index];
        }
        else
        {
            while (attempt <= size)
            {
                step = secondary_hash(index, attempt, k);
                attempt++;
                if (attempt > size || status[step] == 0)
                {
                    //cout << "Ёлемент не был найден." << endl;
                    return -1;
                }
                if (status[index] == 1 && data[index] == *object) {
                    //cout << "Ёлемент был найден." << endl;
                    return value[index];
                }
            }
        }
    }


    ~HashTable3() {
        delete[] data;
        delete[] status;
    }
};