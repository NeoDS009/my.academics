#include <iostream>
using namespace std;

#include "RegList.h"

RegList::RegList() : head(nullptr), tail(nullptr) { }

RegList::RegList(RegList& otherList, Student* stu)
{

    head = nullptr;
    tail = nullptr;

    Node* currNode = otherList.head;

    while (currNode != nullptr)
    {
        if (currNode->data->getStudent() == stu)
        {
            add(currNode->data);
        }
        currNode = currNode->next;
    }

}

RegList::~RegList()
{
    cleanData();
}

void RegList::add(Registration* reg)
{
    Node* newNode = new Node;
    newNode->data = reg;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}


void RegList::del(string n, Registration** reg)
{
    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr)
    {
        if (currNode->data->getStudent()->getName() == n)
            break;

        prevNode = currNode;
        currNode = currNode->next;
    }

    if (currNode == nullptr)
    {
        *reg = nullptr;
        return;
    }

    if (prevNode == nullptr)
    {
        head = currNode->next;
    }
    else
    {
        prevNode->next = currNode->next;
    }

    if (currNode == tail)
    {
        tail = prevNode;
    }

    *reg = currNode->data;
    delete currNode;
}

void RegList::print() const
{
    Node* currNode = head;

    while (currNode != nullptr) {
    currNode->data->print();
    currNode = currNode->next;
    } 

    if (head) {
        cout << "HEAD: ";
        head->data->print();
    } else {
        cout << "HEAD: NONE" << endl;
    }

    if (tail) {
        cout << "TAIL: ";
        tail->data->print();
    } else {
        cout << "TAIL: NONE" << endl;
    }
}

void RegList::cleanData()
{
    Node* currNode = head;
    Node* nextNode;

    while (currNode != nullptr)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}



