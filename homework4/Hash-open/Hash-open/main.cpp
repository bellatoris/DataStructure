//
//  main.cpp
//  Hash-open
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "Hash.h"

void print(Node *temp)
{
    while(temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}


int main()
{
    SHash* shash_test = new SHash();
    
    (*shash_test).insert(30);
    (*shash_test).insert(11);
    (*shash_test).insert(30);
    (*shash_test).insert(30);
    (*shash_test).insert(30);
    (*shash_test).insert(30);
    
    
    (*shash_test).delete_element(30);
    (*shash_test).delete_element(30);
    
    (*shash_test).insert(12);
    (*shash_test).insert(22);
    (*shash_test).insert(12);
    
    (*shash_test).find(20);
    (*shash_test).delete_element(20);
    (*shash_test).find(20);
    
    (*shash_test).delete_element(12);

    delete shash_test;
    
}