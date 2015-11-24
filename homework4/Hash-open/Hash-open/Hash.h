//
//  Hash.hpp
//  Hash-open
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include "LinkedList.h"

class SHash
{
public:
    SHash(int size = 10);     //기본 size는 10
    ~SHash();
    int Hash_function(int key);
    void insert(int key);
    void delete_element(int key);
    bool find(int key);
    
private:
    Node** hash_table;
    int hash_size;      //hash_size를 만들어 hash table의 size를 변경할 수 있게 해놨다.
};

#endif /* Hash_hpp */
