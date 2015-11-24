//
//  dLinkedList.hpp
//  homework2
//
//  Created by Doogie's mac on 2015. 10. 9..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//


/*******************************************
 *
 * 최대한 header파일은 변경하지 않으려 하였습니다.
 *
 *******************************************/

#ifndef dLinkedList_hpp
#define dLinkedList_hpp

#include <iostream>
#include <string>
#include "Stack.h"              //처음 ppt에 나온대로 구현하려고 했어서 Stack.h를 사용하였습니다.


using namespace std;

class dNode: public Node
{
public:
    dNode* next;
    dNode* prev;
    dNode(int data, dNode* n_ptr = NULL, dNode* p_ptr = NULL);
};

class dLinkedList: public LinkedList
{
public:
    dLinkedList();
    ~dLinkedList();
    void push_front(int data);
    void push_back(int data);
    void pop_front();
    void pop_back();
    void insert(int data, dNode* p);
    void delete_node(dNode* p);
    dNode* locate_data(int data);
    void print();
    bool IsEmpty();
    
private:
    dNode *Head, *Tail;
};

#endif /* dLinkedList_hpp */
