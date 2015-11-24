//
//  dLinkedList.cpp
//  homework2
//
//  Created by Doogie's mac on 2015. 10. 9..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "dLinkedList.h"
#include <iostream>

using namespace std;

dNode::dNode(int data, dNode* n_ptr, dNode* p_ptr)
{
    this->data = data;
    next = n_ptr;
    prev = p_ptr;
}

dLinkedList::dLinkedList()
{
    Head = new dNode(-1);           //dummy 노드들의 data 값은 -1로 해주었습니다.
    Tail = new dNode(-1);
    
    Head->next = Tail;              //처음 dLinkedList를 생성하면 Head dummy와 Tail dummy가 서로를 가리키게 했습니다.
    Tail->prev = Head;
}

dLinkedList::~dLinkedList()
{
    dNode *current, *temp;          //파괴자의 경우 전형적인 LinkedList파괴자의 방법을 사용했습니다.
    current = Head;
    temp = Head;
    while(current != NULL)
    {
        current = current->next;
        delete temp;
        temp = current;
    }
}

void dLinkedList::push_front(int data)
{
    Head->next = new dNode(data, Head->next, Head);     //push_front함수의 경우 새로운 노드를 만들고 그 노드의 prev는 Head dummy를 가리키고 next는 Head dummy의 next가 가리키던 node를 가리키게 하였습니다. 그리고 그 node를 Head dummy의 next가 가르키게 하였습니다.
    
    dNode* temp = Head->next;
    
    temp->next->prev = temp;                            //원래 Head dummy의 next였던 node의 prev가 새로 생긴 Head dummy의 next를 가리키게 하였습니다.
}

void dLinkedList::push_back(int data)
{
    Tail->prev = new dNode(data, Tail, Tail->prev);     //push_front함수를 그냥 tail에서 반대로 구현하였습니다.
    
    dNode* temp = Tail->prev;
    
    temp->prev->next = temp;
}

void dLinkedList::pop_front()           //IsEmpty를 사용하여 error checking 하였습니다.
{
    if(IsEmpty() == true)
    {
        cout << "There is no data in list. " << endl;
        return;
    }
    
    dNode* temp = Head->next;           //Head dummy의 next node의 next를 Head dummy의 next가 가리키게 하고 그 이후 Head dummy의 next node의 prev가 Head를 가리키게 해주었습니다.
    
    Head->next = temp->next;
    
    Head->next->prev = Head;
    
    delete temp;                        //그 이후 원래 Head dummy의 next node를 메모리 해제 하였습니다.
}

void dLinkedList::pop_back()            //pop_front와 반대로 구현하였습니다.
{
    if(IsEmpty() == true)
    {
        cout << "There is no data in list. " << endl;
        return;
    }
    
    dNode* temp = Tail->prev;
    
    Tail->prev = temp->prev;
    
    Tail->prev->next = Tail;
    
    delete temp;
}

void dLinkedList::insert(int data, dNode* p)        //insert함수는 dNode포인터 p뒤에 새로운 node를 생성하도록 구현하였습니다.
{
    if(p == Tail)                                   //억지로 Tail뒤에 node를 생성하려 하면 error문구를 띄우고 불가능하도록 하였습니다.
    {
        cout << "You can't insert there" << endl;
        return;
    }
    
    p->next = new dNode(data, p->next, p);          //p의 next에 새로운 node를 만들고 그 node의 next는 원래 p의 next를 가리키게 하였고 prev는 p를 가리키게 하였습니다.
    
    p->next->next->prev = p->next;                  //원래 p의 next node의 prev가 새로생긴 node를 가리키게 하였습니다.
}

void dLinkedList::delete_node(dNode* p)
{
    if(p == Tail || p == Head)                      //Head나 Tail을 지우려 한면 error문구를 띄우고 불가능하도록 하였습니다.
    {
        cout << "You can't delete this node." << endl;
        return;
    }
    dNode* temp = p;                                // p의 next node와 prev node가 서로를 가르키게 하고 p node를 메모리 해제 하였습니다.
    
    temp->next->prev = temp->prev;
    
    temp->prev->next = temp->next;
    
    delete temp;
}

dNode* dLinkedList::locate_data(int data)
{
    if(IsEmpty() == true)                           //IsEmpty로 처음 error checking을 해줍니다.
    {
        cout << "There is no data in list. " << endl;
        return NULL;
    }
    
    dNode* temp = Head->next;                       //Head와 Tail쪽에서 동시에 중앙쪽으로 가면서 search합니다.
    
    dNode* temp2 = Tail->prev;
    
    while(temp != temp2)
    {
        if(temp->data == data)
            return temp;
        
        if(temp2->data == data)
            return temp2;
        
        temp = temp->next;
        temp2 = temp2->prev;
    }
    
    if(temp->data == data)
        return temp;
    
    cout << "There is no node which has the data in list. " << endl;  //해당 data가 list에 없을 경우 문구를 띄어주고 NULL pointer를 return해줍니다.
    
    return NULL;
}

void dLinkedList::print()               //전형적인 list print입니다.
{
    if(IsEmpty() == true)
    {
        cout << "There is no data in list. " << endl;
    }
    else
    {
        cout << "Doubly Linked List: " << endl;
        
        dNode* temp = Head->next;
        
        while(temp != Tail)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    return;
}

bool dLinkedList::IsEmpty()         //IsEmpty함수는 Head dummy의 next가 Tail dummy를 가리키고 있다면 return true하게 하였습니다.
{
    if(Head->next == Tail)
        return true;
    else
        return false;
}

