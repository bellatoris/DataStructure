//
//  LinkedList.h
//  homework1
//
//  Created by Doogie's mac on 2015. 9. 22..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include<iostream>

using namespace std;

class Node
{
public:
    string str;
    int data;
    Node* next;
    Node();
    Node(string str, int data, Node* ptr = NULL);
    void print();
};

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    void insert(string str, int data, Node* p);
    void delete_node(Node* p);
    Node* locate_str(string str);
    Node* locate_data(int data);
    
    void push_back(string str, int data);
    void push_front(string str, int data);
    void selection_sort(bool isString);
    void print();
    
    Node* getHead();
    void setHead(Node* temp);
    
private:
    Node* head;                 //L이라는 Identifier보다 head가 익숙하여 바꿔서 사용하였습니다.
};

#endif /* LinkedList_h */
