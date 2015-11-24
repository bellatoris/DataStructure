//
//  TRIE.cpp
//  TRIE
//
//  Created by Doogie's mac on 2015. 10. 26..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "TRIE.h"



TRIE::TRIE()
{
    root = new TRIENode();                  //root에 TRIENode를 만든다.
}

TRIE::~TRIE()
{
    if(root)                //root가 NULL이 아니라면 지운다.
        delete root;
}

string TRIE::find(string word)
{
    long int length = strlen(word.c_str());         //word의 길이를 받아온다.
    
    TRIENode* insrt = root;
    
    for(int i = 0; i < length; i++)
        if(insrt->childs[word[i]-97])               //word의 문자가 TRIE에 있으면 다음 노드로 넘어간다.
            insrt = insrt->childs[word[i]-97];
        else
            return "";
    
    if(insrt->isWord)                               //그 단어가 isWord가 true면 word를 리턴해준다.
        return word;
    else
        return "";
}

void TRIE::insertion(string word)
{
    long int length = strlen(word.c_str());
    
    TRIENode* insrt = root;
    
    for(int i = 0; i < length; i++)
    {
        if(!insrt->childs[word[i]-97])                              //word의 문자가 TRIE에 없는지 확인하고 없으면 새로 만든다.
            insrt->childs[word[i]-97] = new TRIENode(word[i], false);
        
        insrt = insrt->childs[word[i]-97];                  //다음 노드로 넘어간다.
    }
    
    if(insrt != root)
        insrt->isWord = true;                       //그 word의 마지막 노드의 isWord를 true로 바꿔준다.
}

void TRIE::deletion(string word)
{
    long int length = strlen(word.c_str());
    
    TRIENode* insrt = root;
    TRIENode* index = root;                 //지워야 할 노드의 부모 노드
    
    int del = 0;
    
    for(int i = 0; i < length; i++)
    {
        if(!insrt->childs[word[i]-97])       //그런 단어가 없다면 NO WORD를 출력한다.
        {
            cout << "NO WORD" << endl;
            return;
        }
        
        int k = 0;
        
        for(int j = 0; j < 26; j++)               //자식이 2개 이상이거나 자신이 isWord가 true라면 그 노드를 index에 저장한다.
        {
            if(insrt->childs[j])
                k++;
            
            if(insrt->isWord || k == 2)
            {
                index = insrt;
                del = i;
                break;
            }
        }
        
        insrt = insrt->childs[word[i]-97];      //다음 노드로 이동
    }
    
    if(insrt->isWord)                   //최종적으로 도착하여 그 단어가 존재한다면,
    {
        for(int i = 0; i < 26; i++)     //자식 노드가 존재하는지 봐서 자식노드가 존재하면 isWord = false하고 리턴 해준다.
            if(insrt->childs[i])
            {
                insrt->isWord = false;
                return;
            }
        
        delete index->childs[word[del]-97];     //자식 노드 없으면 index를 사용해서 필요없는 노드들을 모두 지워준다.
        index->childs[word[del]-97] = NULL;     //방어적으로 코딩하기 위해 그 지워진 부분을 NULL로 바꿔준다.
    }
    else
        cout << "NO WORD" << endl;
}

void TRIE::print(string word)
{
    long int length = strlen(word.c_str());
    
    TRIENode* insrt = root;
    
    for(int i = 0; i < length; i++)                 //word의 마지막 node까지 진행한다.
        if(insrt->childs[word[i]-97])
            insrt = insrt->childs[word[i]-97];
        else
            return;
    
    print_slave(word, insrt);           //recursive함수인 print_slave를 call한다.
}

void TRIE::printAll()
{
    print("");                  //모든 단어를 출력한다.
}

void TRIE::print_slave(string word, TRIENode* node)
{
    if(node->isWord)                        //현재 node가 word의 마지막 node라면 word를 출력 한다.
        cout << word << endl;
    
    for(int i = 0; i < 26; i++)             //26개의 alphabet을 모두 탐색하며 recursive하게 함수가 call된다. preorder로 TRIE를 돈다.
        if(node->childs[i])
            print_slave(word + node->childs[i]->data, node->childs[i]);
}