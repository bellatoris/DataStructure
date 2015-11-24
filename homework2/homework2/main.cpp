//
//  main.cpp
//  homework2
//
//  Created by Doogie's mac on 2015. 10. 9..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include <iostream>
#include "dLinkedList.h"

using namespace std;

int main()
{
    dLinkedList* d = new dLinkedList();
    
    
    for(int i = 0; i < 7; i++)
    {
        if(i % 2 == 0)
            d->push_front(i);
        else
            d->push_back(i);
        
        d->print();
    }
    
    dNode* p2 = d->locate_data(5);
    
    d->insert(10, p2->next);
    d->delete_node(p2->next);
    
    d->locate_data(10);
    
    dNode* p = d->locate_data(2);
    d->insert(7, p);
    d->print();
    d->delete_node(p);
    d->print();
    
    
    d->pop_front();
    d->pop_back();
    
    d->print();
    
    d->pop_front();
    d->pop_back();
    
    d->print();
    
    d->pop_front();
    d->pop_back();
    
    d->print();
    
    d->pop_back();
    d->pop_front();
    d->print();
    
    delete d;
}

