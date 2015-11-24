#ifndef _TRIE_H_
#define _TRIE_H_

#include <string>

#include "TRIENode.h"

#pragma once

class TRIE
{
public:
	TRIE();
	~TRIE();
	string find(string word);
	void insertion(string word);
	void deletion(string word);
	void print(string word);
	void printAll();
private:
	TRIENode* root;
	void print_slave(string word, TRIENode* node);
};

#endif