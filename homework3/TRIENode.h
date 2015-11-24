#ifndef _TRIENODE_H_
#define _TRIENODE_H_

#include <iostream>
using namespace std;
#pragma once
class TRIENode
{
public:
		TRIENode();
		~TRIENode();
		TRIENode(char data, bool isWordNew);
		void print();
		bool isWord;
		TRIENode** childs;
		char data;
};

#endif