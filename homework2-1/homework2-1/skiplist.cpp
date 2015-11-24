//
//  skiplist.cpp
//  homework2-1
//
//  Created by Doogie's mac on 2015. 10. 10..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "skiplist.h"
#include <time.h>
#include <iostream>


using namespace std;

sNode::sNode(int data): nextArr(NULL), level(0)
{
    this->data = data;
}

sNode::~sNode()                 //sNode를 파괴할 때 nextArr도 파괴하게 하였습니다.
{
    if(nextArr != NULL)
        delete[] nextArr;
}

skiplist::skiplist(int max): maxSize(max)   //maxSize에 입력된 max값을 넣도록 하였습니다.
{
    PtrArr = new sNode*[maxSize];
    
    Head = new sNode(-1);           //dummy node의 data에는 -1을 넣었습니다.
    
    Head->nextArr = new sNode*[maxSize];    //maxSize만큼의 node pointer array를 만듭니다.
    Head->level = maxSize - 1;
    
    for(int i = 0; i < maxSize; i++)        //nextArr를 모두 NULL로 초기화 시켜줍니다.
    {
        Head->nextArr[i] = NULL;
    }
}

skiplist::~skiplist()       //파괴자를 부르면 모든 node와 PtrArr의 메모리를 해제 합니다.
{
    sNode *current, *temp;
    
    current = Head;
    temp = Head;
    
    while(current != NULL)      //level 0은 언제나 존재하므로 level 0을 사용하여 모든 node를 해제 합니다.
    {
        current = current->nextArr[0];
        delete temp;
        temp = current;
    }
    
    if(PtrArr != NULL)
        delete[] PtrArr;
}

void skiplist::insert(int data)
{
    random_device rng;
    
    sNode* temp = Head;             //temp에 Head를 넣습니다.
    int curlevel = temp->level;
    
    while(curlevel > -1)                    //level 0부터 존재하므로 -1이 되면 break되게끔 while문을 작성하였습니다.
    {
        if(temp->nextArr[curlevel] == NULL || temp->nextArr[curlevel]->data > data)         /*temp의 nextArr[curlevel]이 NULL을 
																							가리키거나 그 node의 data가 insert하려는 data보다 크기가 크다면 
																							nextArr[curlevel]로 temp를 못 옮기기 때문에 PtrArr[curlevel]에 
																							temp를 저장하고 curlevel을 줄입니다. 이 때 PtrArr[curlevel]에 temp를 
																							저장하는 이유는 새로운 node가 생겼을 때 node의 level이 curlevel이상이라면
																							temp->nextArr[curlevel]은 새로운 node를 가리켜야 하기 때문입니다.
																							그러기 위해서는 PtrArr[curlevel]에 temp를 저장해두어야 합니다. */
        {
            PtrArr[curlevel] = temp;
            curlevel--;
        }
        else if(temp->nextArr[curlevel]->data == data)          //우리가 넣으려는 data가 이미 list에 존재한다면 error문구를 띄우고 return합니다.
        {
        cout << "There is a sNode which has the same data. " << endl;
        return;
        }
        else                //그 외의 경우 temp를 현재 curlevel이 가르키는 node로 옮기고 curlevel을 업데이트해 줍니다.
        {
            temp = temp->nextArr[curlevel];
            curlevel = temp->level;
        }
    }       //c가 -1이되면 while문이 끝납니다. 만약 temp->data < data < temp->nextArr[0]->data 이고 그 사이에 node가 존재하지 않는다면 즉, data가 들어갈 자리라면 curlevel은 계속 감소하여 -1이 됩니다.
    
    int level = 0;
    
    while(0 == rng()%4)          //동전을 던져 새로운 node의 level을 결정합니다. %4로 바꾼다면 1/4확률로 level을 증가시킬수 있습니다.
    {
        level++;
        if(level == maxSize - 1)
            break;
    }
    
    sNode* insrt = new sNode(data);     //새로운 node를 만듭니다.
    
    insrt->nextArr = new sNode*[level + 1];     // level은 0부터 시작하므로 pointer arr의 크기는 level + 1이 되어야 합니다.
    insrt->level = level;

    for(int i = 0; i < level + 1; i++)
    {
        insrt->nextArr[i] = PtrArr[i]->nextArr[i];      //저장해두었던 PtrArr를 사용해 level까지 pointer들을 재정렬 해줍니다. PtrArr들이 가리키던걸 새로운 node가 가리키게 하고 PtrArr들은 새로운 node를 가리키게 합니다.
        PtrArr[i]->nextArr[i] = insrt;
    }
    
}

void skiplist::delete_node(int data)
{
    sNode* temp = Head;
    sNode* del = NULL;

    int curlevel = temp->level;
    
    while(curlevel > -1)
    {
        if(temp->nextArr[curlevel] == NULL || temp->nextArr[curlevel]->data > data)
        {
//            PtrArr[curlevel] = temp;
            curlevel--;
        }
        else if(temp->nextArr[curlevel]->data == data)              /*delete의 경우 나머지 부분은 insert와 거의 동일합니다. 다만 target으로 하는 data를 가진 node를 찾은 경우
																	현재 temp의 nextArr[curlevel]이 target node의 nextArr[curlevel]을 가리키도록 변경해줍니다. */
        {
            del = temp->nextArr[curlevel];
            temp->nextArr[curlevel] = temp->nextArr[curlevel]->nextArr[curlevel];
            curlevel--;
        }
        else
        {
            temp = temp->nextArr[curlevel];
            curlevel = temp->level;
        }
    }
    
    if(del == NULL)
        cout << "There is no sNode which has the data. " << endl;   //data를 못찾은경우 error문구를 띄어줍니다.
    else
        delete del;         //target node를 찾은경우 그 node의 메모리를 해제하여줍니다.
    
}

sNode* skiplist::search(int data)
{
    sNode* temp = Head;
    int curlevel = temp->level;
//    int k = -2;
//    cout << data << endl;
    while(curlevel > -1)
    {
//        if(temp->data != k)                           //이부분과 int k = -2의 comment를 해제 하면 어떤 경로를 따라 search하는지 알 수 있습니다.
//        {
//            k = temp->data;
//            cout << k << endl;
//        }
        if(temp->nextArr[curlevel] == NULL || temp->nextArr[curlevel]->data > data)
        {
//            PtrArr[curlevel] = temp;
            curlevel--;
        }
        else if(temp->nextArr[curlevel]->data == data)      //search의 경우 훨씬 간단합니다. 같은 방법을 쓰면서 target data를 가지는 node를 단 하나라도 발견하면 바로 그 pointer를 return해주면 됩니다.
        {
//            cout << data << endl;
            temp = temp->nextArr[curlevel];
            return temp;
        }
        else
        {
            temp = temp->nextArr[curlevel];
            curlevel = temp->level;
        }
    }
    
    cout << "There is no sNode which has the data. " << endl;       //마찬가지로 못찾은 경우 error문구를 띄우고 NULL을 return해줍니다.
    
    return NULL;
}

void skiplist::result(int inrt, int del, int srch)
{
    int size = this->size();        //LinkedList를 새로히 만들어 skiplist가 가진 data를 모두 push해줍니다. 이 때 사용한 push함수는 data를 오름차순으로 넣어주는 함수입니다.(skiplist의 insert함수와 목적이 같습니다.)
    float gap;
    
    sNode* temp = Head->nextArr[0];
    
    time_t starttime = 0, endtime = 0;
    
    LinkedList* List = new LinkedList();
    
    for(int i = 0; i < size; i++)
    {
        List->push(temp->data);
        temp = temp->nextArr[0];
    }
        
    cout << "Linked List Result: " << endl;     //그리고 각각의 함수의 시작과 끝의 clock을 재고 그 차이를 출력하도록 했습니다. 만약  gap = (float)(endtime - starttime)/CLOCKS_PER_SEC를 사용한다면 시간으로 출력할 수 있습니다.
    
    starttime = clock();
    List->push(inrt);
    endtime = clock();
    
//    gap = (float)(endtime - starttime)/CLOCKS_PER_SEC;
     gap = (float)(endtime - starttime);
    cout << "insert:\t" << gap << endl;
    
    starttime = clock();
    List->delete_node(List->locate_data(del));
    endtime = clock();
    
    gap = (float)(endtime - starttime);
    cout << "delete:\t" << gap << endl;
    
    starttime = clock();
    List->locate_data(srch);
    endtime = clock();
    
    gap = (float)(endtime - starttime);
    cout << "search:\t" << gap << endl;
    
    delete List;

    cout << endl << "/*******************************/" << endl << endl;

    cout << "Skip List Result: " << endl;
    
    starttime = clock();
    insert(inrt);
    endtime = clock();
    
    gap = (float)(endtime - starttime);
    cout << "insert:\t" << gap << endl;
    
    starttime = clock();
    delete_node(del);
    endtime = clock();
    
    gap = (float)(endtime - starttime);
    cout << "delete:\t" << gap << endl;
    
    starttime = clock();
    search(srch);
    endtime = clock();
    
    gap = (float)(endtime - starttime);
	cout << "search:\t" << gap << endl << endl;
}

bool skiplist::IsEmpty()        // skiplist가 empty인지 아닌지 확인해주는 함수입니다. delete와 search 그리고 size 모두 이 함수를 사용하지 않더라도 error checking이 되기 때문에 사용하지 않았습니다.
{
    if(Head->nextArr[0] == NULL)
        return true;
    else
        return false;
}

int skiplist::size()        //현재 skiplist에 얼마만큼의 node가 들어있는지 알려줍니다.
{
    sNode* temp = Head->nextArr[0];
    int size = 0;
    while(temp != NULL)
    {
        size++;
        temp = temp->nextArr[0];
    }
    return size;
}

void skiplist::print()
{
    if(IsEmpty()==true)         //IsEmpty함수를 사용해 error checking 해줍니다. 만약 node가 하나도 없다면 error문구를 띄우고 return해줍니다.
    {
        cout << "There is no node in skiplist" << endl;
        return;
    }
    
    sNode* temp = Head;

    while(temp != NULL)         //현재 가지고 있는 data를 출력하고 pointer를 *로 표시하여 출력합니다.
    {
        int lvl = temp->level;
        cout << temp->data << "\t";
        
        cout << "[" ;
        for(int i = 0; i < lvl + 1; i++)
        {
            cout << "*";
            
            if(i != lvl)
                cout << "   ";
        }
        cout << "]";
        
        if(temp == Head)        //dummy도 출력하면 보기 편할것 같아서 dummy부터 출력합니다. 다만 dummy는 dummy라는것을 알려줍니다.
        {
            cout << "\t\t" << "It's Dummy!!";
        }
        
        temp = temp->nextArr[0];
        cout << endl;
    }
    cout << endl;
    return;
}

void skiplist::result2(int inrt, int del, int srch)		/*result함수와 매우 비슷합니다 다만 LinkedList를 새로 만들어서
														쓰지 않고 skiplist를 LinkedList처럼 동작하게 하여 성능을 비교합니다.
														LinkedList의 insert, delete 함수 모두 하나하나 비교해가면서 
														찾아간다는 점에서 search2와 그 동작이 동일합니다. 지우거나 새로운 node를
														만들어 추가하는 동작은 매우 적은 시간이 걸리니 무시해도 된다고 가정하였습니다.
														그러므로 insert나 delete모두 search2함수를 사용해 비교하였습니다.*/
{
	float gap;

	time_t starttime = 0, endtime = 0;

	cout << "Linked List Result: " << endl;     

	starttime = clock();
	search2(inrt);							//다만 여기서 LinkedList동작을 할 때 실제로 insert나 delete를 하는 것은 아닙니다.
	endtime = clock();

	//    gap = (float)(endtime - starttime)/CLOCKS_PER_SEC;
	gap = (float)(endtime - starttime);
	cout << "insert:\t" << gap << endl;

	starttime = clock();
	search2(del);
	endtime = clock();

	gap = (float)(endtime - starttime);
	cout << "delete:\t" << gap << endl;

	starttime = clock();
	search2(srch);
	endtime = clock();

	gap = (float)(endtime - starttime);
	cout << "search:\t" << gap << endl;

	cout << endl << "/*******************************/" << endl << endl;

	cout << "Skip List Result: " << endl;

	starttime = clock();
	insert(inrt);
	endtime = clock();

	gap = (float)(endtime - starttime);
	cout << "insert:\t" << gap << endl;

	starttime = clock();
	delete_node(del);
	endtime = clock();

	gap = (float)(endtime - starttime);
	cout << "delete:\t" << gap << endl;

	starttime = clock();
	search(srch);
	endtime = clock();

	gap = (float)(endtime - starttime);
	cout << "search:\t" << gap << endl << endl;

}

void skiplist::search2(int data)		//result2를 위한 search2함수 입니다. skiplist가 마치 LinkedList인 것 처럼 행동합니다.
{
	sNode* temp = Head;

	while (temp->nextArr[0])			//nextArr[0]이 NULL이 될 때 까지 search합니다.
	{
		if (temp->nextArr[0]->data == data)		//data가 같은게 존재하면 return됩니다.
		{
			return;
		}
		else if (temp->nextArr[0]->data < data)		// target data보다 temp->nextArr[0]->data가 작다면 nextArr[0]으로 temp를 이동시킵니다.
		{
			temp = temp->nextArr[0];
		}
		else				//그 외의 경우 return합니다.
		{
			return;
		}
	}		//계속 옮기다가 NULL이 되어서 while문을 빠져나오면 return합니다.
	return;
}

void skiplist::AvgPtr()
{
    sNode* temp = Head->nextArr[0];
    float sum = 0;
    float i = 0;
    
    while(temp)
    {
        sum += temp->level + 1;
        temp = temp->nextArr[0];
        i++;
    }
    
    float avg = sum/i;
    
    cout << avg << endl;
}

