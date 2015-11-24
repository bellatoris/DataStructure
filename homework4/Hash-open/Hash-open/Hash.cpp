//
//  Hash.cpp
//  Hash-open
//
//  Created by Doogie's mac on 2015. 11. 12..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "Hash.h"


SHash::SHash(int size): hash_size(size)     //hash_size에 size를 넣어준다.
{
    hash_table = new Node* [hash_size];     //hash_table에 Node pointer array를 hash_size만큼 만든다.
    
    for(int i = 0; i < hash_size; i++)
    {
        hash_table[i] = new Node("HDR", -1);    //각각의 pointer에 dummy Node를 만들어 둔다.
    }
}

SHash::~SHash()
{
    for(int i = 0; i < hash_size; i++)      //dummy Node를 해제
    {
        delete hash_table[i];
    }
    delete [] hash_table;       //pointer array 해제
}

int SHash::Hash_function(int key)
{
    return key%hash_size;   //key값을 hash_size로 나눈 나머지를 hash 값으로 사용한다
}

void SHash::insert(int key)
{
    int hash = Hash_function(key);
    
    Node* temp = hash_table[hash];
    
    while(temp->next)
    {
        temp = temp->next;  //key에 해당하는 hash 값을 index에 넣어 해당하는 linked list 제일 뒤에 새로운 Node로 삽입한다.
    }
    
    temp->next = new Node("", key);
}

void SHash::delete_element(int key)
{
    int hash = Hash_function(key);
    
    Node* temp = hash_table[hash];
    Node* ptemp = temp;     //linked list의 제일 마지막에 해당하는 key가 존재할 경우를 위한 Node pointer
    Node* del = NULL;
    int alr = 1;    //이전에 지운 Node가 있었는지 확인 하기 위한 integer
    
    while(temp->next)   //temp가 마지막 Node일 때까지 while문이 돈다.
    {
        if(temp->data == key)   //key를 가진 Node를 찾았다면 next Node와 data를 swap한다.
        {
            cout << "Delete " << key << " from Hash table" << endl;
            del = temp->next;
            temp->data = temp->next->data;      //temp->next != NULL이므로
            temp->next = temp->next->next;
            del->next = NULL;
            delete del;
            alr = 0;    //"지운적이 있다"라고 표시해둔다.
        }
        else    //temp->data != key라면 ptemp와 temp를 한 칸씩 옮겨준다.
        {
            ptemp = temp;
            temp = temp->next;
        }
    }
    
    if(temp->data == key)   //마지막 Node의 key값이 우리가 원하는 key값이었을 경우
    {
        cout << "Delete " << key << " from Hash table" << endl;
        ptemp->next = NULL;
        delete temp;
    }
    else if(alr)    //지운적이 없다면 error문구 출력
        cout << key << " does not exists" << endl;
}

bool SHash::find(int key)
{
    int hash = Hash_function(key);
    
    Node* temp = hash_table[hash];
    
    while(temp)     //key값을 가진 Node가 하나라도 있으면 true를 return한다.
    {
        if(temp->data == key)
        {
            cout << key << endl;
            return true;
        }
        temp = temp->next;
    }
    
    cout << key << " does not exists" << endl;
    return false;
}