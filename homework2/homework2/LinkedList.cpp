//
//  LinkedList.cpp
//  homework1
//
//  Created by Doogie's mac on 2015. 9. 22..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "LinkedList.h"
#include <string>

Node::Node(): str("NULL"), data(-1), next(NULL)
{
    
}

Node::Node(string str, int data, Node* ptr): str(str), data(data), next(ptr)
{
    
}

void Node::print()
{
    cout << str << ", " << data << endl;
}

void swap(Node* a, Node* b)                 //Node의 data와 str을 swap해주는 함수
{
    int data = a->data;
    string str = a->str;
    a->data = b->data;
    a->str = b->str;
    b->data = data;
    b->str = str;
}

LinkedList::LinkedList()
{
    head = new Node("dummy", -1);
}

LinkedList::~LinkedList()
{
    Node *current, *temp;                   //LinkedList를 파괴할 때 LinkedList안에 존재하는 모든 Node를 파괴한다.
    current = head;
    temp = head;
    while(current != NULL)
    {
        current = current->next;
        delete temp;
        temp = current;
    }
}

void LinkedList::insert(string str, int data, Node* p)
{
    if(p == NULL)
        return;
    p->next = new Node(str, data, p->next);     //새로운 Node를 p 앞에 넣을 때 원래 p->next를 새로운 Node의 next에 넣어준후 p->next는 새로운 노드를 가르키게 한다.
}

void LinkedList::delete_node(Node* p)
{
    if(p == NULL)                               //p == NULL일 경우 return
        return;
    else if(p->next == NULL)                    //p->next == NULL일 경우 p의 바로 앞 노드를 찾고 p를 지운다.
    {
        Node* temp = head;
        while(temp->next->next != NULL)
            temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }
    else                                        //p의 data와 str을 p->next의 data와 str을 swap한후 p->next를 파괴한다.
    {
        Node* temp = p->next;
        swap(p, p->next);
        p->next = p->next->next;
        delete temp;
    }
}

Node* LinkedList::locate_str(string str)
{
    Node* temp = head->next;
    while(temp != NULL)
    {
        if(temp->str == str)
            return temp;
        temp = temp->next;
    }
//    if(temp == NULL)
//        cout << "List does not have string which you insert" << endl;
    return temp;                               //str을 가진 Node를 찾고 그 포인터를 반환한다. 만약 그러한 포인터가 없을 경우 NULL 포인터를 반환한다.
}

Node* LinkedList::locate_data(int data)
{
    Node* temp = head->next;
    while(temp != NULL)
    {
        if(temp->data == data)
            return temp;
        temp = temp->next;
    }
//    if(temp == NULL)
//        cout << "List does not have data which you insert" << endl;
    return temp;                                //data를 가진 Node를 찾고 그 포인터를 반환한다. 만약 그러한 포인터가 없을 경우 NULL 포인터를 반환한다.
}

void LinkedList::push_back(string str, int data)    //LinkedList의 맨뒤에 새로운 Node를 추가한다.
{
    Node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(str, data);
}

void LinkedList::push_front(string str, int data)
{
    head->next = new Node(str, data, head->next);
}

void LinkedList::selection_sort(bool isString)
{
    if(head->next == NULL)
        return;
    Node* startNode = head->next;

    while(startNode->next != NULL)
    {
        Node* minNode;
        if(isString == true)
        {
            for(minNode = startNode; minNode->next != NULL; minNode = minNode->next)
            {
                if(strcmp(minNode->str.c_str(), minNode->next->str.c_str()) < 0)
                    swap(minNode, minNode->next);
            }
        }
        else
        {
            for(minNode = startNode; minNode->next != NULL; minNode = minNode->next)
            {
                if(minNode->data < minNode->next->data)
                    swap(minNode, minNode->next);
            }
        }
        swap(startNode, minNode);
        startNode = startNode->next;
    }
}

void LinkedList::print()
{
    Node* temp = head->next;
    while(temp != NULL)
    {
        temp->print();
        temp = temp->next;
    }
    return;
}

Node* LinkedList::getHead()
{
    return this->head;
}

void LinkedList::setHead(Node* temp)
{
    head = temp;
}