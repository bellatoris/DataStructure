//
//  Hash.hpp
//  Hash-closed
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <iostream>

using namespace std;

class QHash
{
public:
    QHash(int size = 10);
    ~QHash();
    int Hash_function(int key);
    void insert(int key);
    void delete_element(int key);
    int find(int key);
    
private:
    int* hash_table;
    int hash_size;
};

#endif /* Hash_hpp */
