//
//  Stack.hpp
//  Lab3 - Stack
//
//  Created by Doogie's mac on 2015. 10. 9..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <iostream>
#include "LinkedList.h"

class Stack: public LinkedList
{
public:
    Stack();
    ~Stack();
    void push(int data);
    void pop();
    void top();
    void print();
    bool IsEmpty();
};

#endif /* Stack_hpp */
