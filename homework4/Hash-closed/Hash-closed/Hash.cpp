//
//  Hash.cpp
//  Hash-closed
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "Hash.h"


QHash::QHash(int size): hash_size(size)
{
    hash_table = new int[2 * hash_size];    //2 * hash_size만큼의 hash_table을 만든다. 처음 hash_size는 실제 data저장을 위한 array다. 그 다음은 empty flag를 위한 array다.
    for(int i = hash_size; i < 2 * hash_size; i++)  //flag array의 모든값을 0(empty)로 해둔다.
        hash_table[i] = 0;
}

QHash::~QHash()
{
    delete hash_table;
}

int QHash::Hash_function(int key)
{
    int hash = key%hash_size;
    int i = 0;
    
    while(hash_table[hash + hash_size] && hash_table[hash])  //flag[hash]이 비어 있지도(0) table[hash]가 지워져 있지도(0) 않으면 hash값을 바꿔준다.
    {
        if(i++ == hash_size)    //probing을 hash_size보다 많이 하면 -1을 return 한다. hash_size이상은 동일한 index로 접근할 뿐이다.
            return -1;
        hash = (key%hash_size+i*i)%hash_size;
    }
    return hash;
}

void QHash::insert(int key)
{
    int hash = Hash_function(key);
    if(hash == -1)      //hash == -1 이면 table이 full이라고 error문구를 띄어준다.
    {
        cout << "The table is full" << endl;
        return;
    }
    hash_table[hash] = key;     //hash != -1이라면 hash에 해당하는 entry에 key를 넣어준다.
    hash_table[hash + hash_size] = 1; //flag[hash_size] = 1 (not empty)를 넣어준다.
    cout << "Insert: " << key << ", position: " << hash << endl;
}

void QHash::delete_element(int key)
{
    int hash = key%hash_size;
    int i = 0;
    int alr = 1;    //한번이라도 지운적이 있는지 확인하기 위한 variable

    while(hash_table[hash + hash_size])   //flag[hash] == 0(empty)이면 probing을 중단한다.
    {
        if(i++ == hash_size)
        {
            if(alr) //지운적이 없다면 error문구 출력
                cout << key << " does not exists" << endl;
            return;
        }
        
        if(hash_table[hash] == key)     //key를 가지고 있는 entry를 찾으면 NULL(deleted)로 바꿔준다.
        {
            cout << "Delete " << key << " from Hash table" << endl;
            hash_table[hash] = NULL;
            alr = 0;    //한번이라도 지웠다는 것을 표기.
        }
        hash = (key%hash_size+i*i)%hash_size;
    }
    if(alr)
        cout << key << " does not exists" << endl;
    return;
}

int QHash::find(int key)
{
    int hash = key%hash_size;
    int i = 0;
    int rtn = -1;

    while(hash_table[hash + hash_size]) //flag[hash] == 0(empty)면 probing  중단
    {
        if(i++ == hash_size)    //hash_size보다 많이 probing하면 return
            return rtn;
        
        if(hash_table[hash] == key)
        {
            int temp = 1;
            if(rtn == -1)
                rtn = hash;     //맨처음 찾은 hash값을 return 해주기 위해 그 hash 값을 저장해둔다.
            
            for(int k = 0; k < i - 1; k++)  //동일한 index의 출력을 방지하기 위한 for문
            {
                if(hash == (key%hash_size+k*k)%hash_size)   //동일한 hash가 한번이라도 나왔으면 출력을 하지 않는다.
                {
                    temp = 0;
                    break;
                }
            }
            if(temp)    //hash가 한번도 안나온 hash라면 출력한다.
                cout << "Find: " << key << ", position: " << hash << endl;
        }
        hash = (key%hash_size+i*i)%hash_size;
    }
    
    return rtn;
}