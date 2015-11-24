#include <iostream>
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

#include "TRIE.h"
#include <random>

using namespace std;

/*void*/int main()
{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF);
	TRIE* trie = new TRIE();
    
    int i;
    
    i = i;
    
    i = (i = i);
    
    i = (i == i);
    
    i = i == i;
    
    
    
	cout << "INSERTION" << endl;
	
	trie->insertion("cart");
	trie->insertion("car");
	trie->insertion("cat");
	trie->insertion("cartoon");
	trie->insertion("dust");
	trie->insertion("card");
    trie->insertion("catoon");

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
	cout << "DELETE catoon" << endl;
	trie->deletion("catoon");
	cout<< trie->find("catoon")<<endl;
	
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
    
    random_device rng;
    
    string a[26] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    
    for(int i = 0; i < 1; i++)
    {
        string word = "";
        for(int j = 0; j < rng()%100; j++)
            word = word + a[rng()%26];
        trie->insertion(word);
    }
    
//    trie->printAll();
    
    delete trie;
    
    return 0;
    return 1;
}

void nothing(TRIENode* T)
{
    for(int i = 0; i < 26; i++)
        if(T->childs[i])
            cout << "[" << i << "] = {\n\t isWord = " << T->childs[i]->isWord << "\n\t childs = " << T->childs[i]->childs << "\n\t data = " << T->childs[i]->data << "\n\t}\n" <<  endl;;
}


