//
//  main.cpp
//  homework2-1
//
//  Created by Doogie's mac on 2015. 10. 10..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include <iostream>
#include "skiplist.h"

using namespace std;

int main()
{
    
    skiplist* s = new skiplist(11);
    
    s->delete_node(3);
    s->search(3);
    s->print();
    
    cout << s->size() << endl;
    
    for(int i = 0; i < 4000000; i++)
    {
        int k = i;
        s->insert(k);
    }
	cout << "complete" << endl << endl;;

//    s->print();           //input개수가 적을 때 사용하는게 좋습니다.
//    s->result(995000,994990,994980);
    s->result2(3995000,3994990,3994980);
    
    s->AvgPtr();
    
//    s->print();

    delete s;
    
    
    return 0;
}
