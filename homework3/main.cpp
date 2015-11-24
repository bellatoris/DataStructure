#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include "TRIE.h"

using namespace std;

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	TRIE* trie = new TRIE();

	cout << "INSERTION" << endl;
	
	trie->insertion("cart");
	trie->insertion("car");
	trie->insertion("cat");
	trie->insertion("cartoon");
	trie->insertion("dust");
	trie->insertion("card");

	cout << "PRINTALL" << endl; 
	trie->printAll();
	cout << endl;

	//Insertion Test
	cout << "INSERTION TEST" << endl;

	trie->insertion("a");
	cout << "INSERT a & PRINT a" << endl;
	trie->print("a");
	
	trie->insertion("ant");
	cout << "INSERT ant & PRINT a" << endl;
	trie->print("a");

	trie->insertion("an");
	cout << "INSERT an & PRINT a" << endl;
	trie->print("a");

	trie->insertion("and");
	cout << "INSERT and & PRINT a" << endl;
	trie->print("a");
		
	cout << "PRINT CAR" << endl;
	trie->print("car");
	//deletion
	cout << "DELETE cat" << endl;
	trie->deletion("cat");
	cout<< trie->find("cat")<<endl;
	
	cout << "DELETE car" << endl;
	trie->deletion("car");
	cout << trie->find("car") << endl;
	
	cout << "DELETE card" << endl;
	trie->deletion("card");
	cout << trie->find("card") << endl;
	
	cout << "DELETE carto" << endl;
	trie->deletion("carto");
	cout << endl;

	cout << "DELETE cards" << endl;
	trie->deletion("cards");
	cout << trie->find("cards") << endl;
	
	trie->printAll();
}



