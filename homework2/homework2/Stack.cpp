//
//  Stack.cpp
//  Lab3 - Stack
//
//  Created by Doogie's mac on 2015. 10. 9..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    Node* dummy = new Node("dummy", -1);
    setHead(dummy);
}

Stack::~Stack()
{
//    Node *current, *temp;
//    current = getHead();
//    temp = getHead();
//    while(current != NULL)
//    {
//        current = current->next;
////        cout << "I delete temp \t" << temp << endl;
//        delete temp;
//        temp = current;
//    }
//    setHead(NULL);
}

void Stack::push(int data)
{
    push_front("NULL", data);
}

void Stack::pop()
{
    if(IsEmpty() == true)
        cout << "These is no data in stack. " << endl;
    else
    {
        Node* temp = getHead()->next;
        
        delete_node(temp);
    }
}

void Stack::top()
{
    if(IsEmpty() == true)
        cout << "There is no data in stack. " << endl;
    else
    {
        Node* temp = getHead()->next;
        
        cout << temp->data << endl;
    }
}

void Stack::print()
{
    if(IsEmpty() == true)
        cout << "There is no data in stack. " << endl;
    else
    {
        Node* temp = getHead()->next;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        return;
    }
}

bool Stack::IsEmpty()
{
    Node* temp = getHead()->next;
    
    if(temp == NULL)
        return true;
    else
        return false;
}

