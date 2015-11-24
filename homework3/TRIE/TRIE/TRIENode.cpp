//
//  TRIENode.cpp
//  TRIE
//
//  Created by Doogie's mac on 2015. 10. 26..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "TRIENode.h"

TRIENode::TRIENode()
{
    childs = new TRIENode*[26];         //childs에 26개의 TRIENode pointer array를 만든다.
    
    for(int i = 0; i < 26; i++)         //모두 NULL로 초기화 한다.
        childs[i] = NULL;
    
    isWord = false;                     //isWord는 false로 초기화 한다.
}

TRIENode::~TRIENode()
{
    for(int i = 0; i < 26; i++)         //childs[i]가 NULL이 아니라면 지운다.
        if(childs[i])
            delete childs[i];
    
    if(childs)                          //childs가 NULL이 아니라면 지운다.
        delete [] childs;
}

TRIENode::TRIENode(char data, bool isWordNew):data(data), isWord(isWordNew)
{
    childs = new TRIENode*[26];         //TRIENode()와 동일
    
    for(int i = 0; i < 26; i++)
        childs[i] = NULL;
}

void TRIENode::print()
{
    cout << data;
}
