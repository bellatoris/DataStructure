//
//  skiplist.hpp
//  homework2-1
//
//  Created by Doogie's mac on 2015. 10. 10..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

/************************************************************************************
*
* visual studio 2013은 license가 종료되어 이제 2015만 무료로 깔 수 있어 제 개인컴퓨에는 2015를 
* 설치 하였습니다.만약 조교님 컴퓨터에 2013이 깔려있다면 컴파일시 오류가 발생합니다. 
* 이 때 프로젝트 항목 -> 속성 -> 구성속성 -> 일반항에서 플랫폼 도구집합을 v140이 아닌
* 설치되어있는 버전에 맞게 바꿔주시면 컴파일이 가능합니다.
*
*************************************************************************************/

/************************************************************************************
 *
 * header파일 변경한 부분은 주석을 달았습니다.
 * 제일 아래 node level은 0으로 가정하였습니다.
 *
 * 즉 문제에서 max node level = 3 이라 하였는데 이 경우 제 skiplist에서는
 * skiplist를 생성할 때 skiplist(4)로 하여야 최대 node level이 3이 됩니다.
 * 그러나 이 경우 pointer의 갯수는 4개가 됩니다.
 *
 * 만약 최대 pointer 갯수를 3개로 하는 것이 문제의 의도 였다면 skiplist를 생성할 때
 * skiplist(3)혹은 skpilist()로 하시면 됩니다.
 *
 * result함수도 구현했고 매우 잘 동작합니다. 다만 skiplist의 insert의 경우 random함수를
 * 계속 function call을 해야하기 때문에 overhead가 존재해 그냥 linkedlist보다 나은
 * 속도를 보이기위해서는 input수를 50000개 이상 maxSize = log(input)으로 해주어야 합니다.
 * 다만 그럴경우 linkedlist에 push를 input갯수 만큼 insert해주어야 해서 출력이 나오는데
 * 시간이 꽤 많이 필요할 수 있습니다.
 *
 * (xcode에서 컴파일 했을 때 뚜렷한 차이를 보였지만 visual studio는 최적화를
 * 너무 잘해주어서 50000개로는 차이를 볼 수 없었습니다. 아마 500000개나 그 이상의 input
 * 을 넣어야 차이를 볼 수 있을 것 같습니다.)
 *
 *
 ************************************************************************************/
/************************************************************************************
*
* 앞서 그냥 result함수로는 성능 비교가 너무 시간이 오래걸린다 생각하여 result2함수를 만들었습니다.
* 이 result2함수는 새로운 LinkedList를 만들지 않고 이미 존재하는 skiplist의 level 0 구간을
* 사용하여 마치 LinkedList인 것 처럼 행동하게 만들어 그 성능을 비교합니다. 
* LinkedList에서 insert나 delete모두 search함수와 running time이 모두 동일합니다.
* 그 점을 착안하여 result2함수를 만들었습니다. 
* result2함수의 경우 input을 1000000정도로 하여도 무리없이 동작하며 그 성능을 잘 비교할 수 있습니다.
*
*************************************************************************************/

#ifndef skiplist_hpp
#define skiplist_hpp

#include <iostream>
#include <random>

#include "LinkedList.h"

using namespace std;

class sNode: public Node    //한 node안에 여러 pointer를 가지게 하기 위해 sNode라는 새로운 class를 만들었습니다.
{
public:
    sNode(int data);
    ~sNode();
    sNode** nextArr;        //next pointer들의 array를 저장하기 위한 double pointer와 현재 node의 level을 저장하기 위한 int level을 넣어놓았습니다.
    int level;
};

class skiplist: public LinkedList
{
public:
//    skiplist();
    skiplist(int max = 3);  // skiplist의 node level의 max값을 initial하게는 3으로 잡아놓았습니다. 그러나 사용자가 변경할 수 있게끔 해놓았습니다.
    ~skiplist();
    void insert(int data);
    void delete_node(int data);
    sNode* search(int data);
    void result(int inrt = 50, int del = 35, int srch = 44);  //result함수를 공지가 나오기 전에 구현해놔서 그냥 놔뒀습니다. result에 테스트하고 싶은 값을 입력할 수 있게끔 해놓았습니다.
    bool IsEmpty();
    int size();
    void print();       //현재 node들의 포인터가 어떻게 연결되어 있고 각 node들의 level이 어떤지 알기 쉽게 print해주는 함수 입니다.
    
	void result2(int inrt = 50, int del = 35, int srch = 44);		//앞서 설명한 result2함수입니다. 이미 존재하는 skiplist를 LinkedList처럼 행동하게 해 그 성능을 비교합니다.
	void search2(int data);		//skiplist가 마치 LinkedList처럼 search하는 함수입니다.
    
    void AvgPtr();

private:
    int maxSize;        //node가 가질 수 있는 max level값을 의미합니다.
    sNode* Head;        //list의 dummy부분을 가리키는 Head pointer입니다.
    sNode** PtrArr;     //insert함수에서 새로운 node의 pointer에 주소값을 넣어 주기 위해 필요한 double pointer입니다. 자세한 설명은 insert함수에 적혀있습니다.
};

#endif /* skiplist_hpp */
