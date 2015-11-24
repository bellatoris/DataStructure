//
//  main.cpp
//  Hash-closed
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "Hash.h"
#include <random>

int main(int argc, const char * argv[])
{
    random_device rng;
    QHash* qhash_test = new QHash(10);
    
    (*qhash_test).insert(10);
    (*qhash_test).insert(11);
    (*qhash_test).insert(20);
    (*qhash_test).insert(30);
    
    (*qhash_test).delete_element(20);
    cout << (*qhash_test).find(10) << endl;
    cout << (*qhash_test).find(20) << endl;
    
    (*qhash_test).insert(12);
    (*qhash_test).insert(22);
    (*qhash_test).delete_element(12);
    
//    for(int i = 0; i < 1000; i++)
//    {
//        qhash_test->insert(rng()%1000);
//    }
//    
    delete qhash_test;
}
