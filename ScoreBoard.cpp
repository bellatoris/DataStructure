//
//  ScoreBoard.cpp
//  homework1
//
//  Created by Doogie's mac on 2015. 9. 22..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include "ScoreBoard.h"
#include <string>

Student::Student()
{
    scoreList = new LinkedList();       //Student를 만들 때 scoreList를 dynamic allocation해준다.
}

Student::~Student()
{
    if(scoreList != NULL)               //Dynamic allocation된 scoreList를 파괴한다.
        delete scoreList;
}

ScoreBoard::ScoreBoard(): numOfSubjects(0), numOfStudents(0), studentArray(NULL), subjectArray(NULL) //ScoreBoard를 만들 때 초기화해준다.
{
}

ScoreBoard::~ScoreBoard()               //Dynamic allocation 된 studentArray와 subjectArray를 파괴한다.
{
    if(studentArray != NULL)
        delete [] studentArray;
    if(subjectArray != NULL)
        delete [] subjectArray;
}

void ScoreBoard::set_subjects(string* subjectArray, int numOfSubjects)  //ScoreBoard의 subjectArray를 dynamic allocation 해주고 numOfSubjects값을 받아온다.
{
    this->numOfSubjects = numOfSubjects;
    this->subjectArray = new string[numOfSubjects];
    for(int i = 0; i < numOfSubjects; i++)
    {
        this->subjectArray[i] = subjectArray[i];
    }
}

void ScoreBoard::set_students(string* studentNameArray, int numOfStudents)  //ScoreBoard의 studentArray를 dynamic allocation 해주고 numOfStudents값을 받아온다.

{
    this->numOfStudents = numOfStudents;
    this->studentArray = new Student[numOfStudents];
    for(int i = 0 ; i < numOfStudents; i++)
    {
        this->studentArray[i].name = studentNameArray[i];
    }
}

void ScoreBoard::insert_score(string name, string subjectName, int score)
{
    int i;

    if(numOfStudents == 0)
    {
        cout << "You did not insert Subject Array or Student Array!" << endl;       //만약 StudentArray를 입력하지 않고 점수를 입력하려 하면 error문구를 띄운다.
        return;
    }
    
    for(i = 0; i < numOfStudents; i++)                  //string과 일치하는 이름을 가진 studentArray의 요소를 찾고 그러한 이름을 가진 요소가 없을 경우 error문구를 띄운다.
    {
        if(studentArray[i].name == name)
            break;
        
        if(i == numOfStudents - 1)
            {
                cout << "You insert wrong student Name!" << endl;
                return;
            }
    }
    
    if(studentArray[i].scoreList->locate_str(subjectName) != NULL)      //동일한 과목에 두번 점수를 입력하려 하면 error문구를 띄우고 return한다.
    {
        cout << "You insert score on same subject already. " << endl;
        return;
    }
    else
        studentArray[i].scoreList->push_front(subjectName, score);      //처음 입력하는 과목이라면 점수와 과목을 Student의 scoreList에 넣는다.
}

int ScoreBoard::get_max_score_of_subject(string subjectName)            //subject의 최고값을 가진 Student의 이름과 그 점수를 출력한다.
{
    int max = -1;
    Node* temp;
    
    for(int i = 0; i < numOfStudents; i++)
    {
        temp = studentArray[i].scoreList->locate_str(subjectName);      //Student의 scoreList에 subjectName과 일치하는 Node가 존재하는지 찾는다.
        if(temp != NULL && max < temp->data)                            //존재하고, 그 data가 현재 최고값보다 크다면 max에 그 data를 넣는다.
            max = temp->data;
    }
    
//    if(max == -1)
//        cout << "There is no student who takes the course." << endl; //적어도 한명의 Student가 이 subject의 점수를 가지고 있다고 가정한다.
    
    cout << "The best score on " << subjectName << " is " << max << endl;
    
    return max;
}
Node* ScoreBoard::get_max_score_of_student(string name)                //name과 일치하는 멤버 name을 가진 Student가 존재한다고 가정한다. 또한 max score는 하나라고 가정한다.
{
    int i;
    int max = -1;
    Node* temp = NULL;
    Node* score;
    
    for(i = 0; i < numOfStudents; i++)
    {
        if(studentArray[i].name == name)
            break;
    }
        
    for(int j = 0; j < numOfSubjects; j++)
    {
        score = studentArray[i].scoreList->locate_str(subjectArray[j]);
        if(score != NULL && max < score->data)
        {
            max = score->data;
            temp = score;
        }
    }
    
    cout << name << "'s the best score is " << temp->data << endl;
    
    return temp;                                                        //가장 높은 점수를 가진 Node를 반환한다.
}
string ScoreBoard::get_top_student_in_subject(string subjectName)       //가장 높은 subject 점수를 가진 Student는 한명이라고 가정한다.
{
    int max = get_max_score_of_subject(subjectName);
    string topguy = "NULL";
    Node* temp;
    
//    if(max == -1)
//    {
//        cout << "There is no student who takes the course" << endl;   //해당 subject의 점수를 적어도 한명의 student는 가지고 있다고 가정한다.
//        return "NULL";
//    }
    
    for(int i = 0; i < numOfStudents; i++)
    {
        temp = studentArray[i].scoreList->locate_str(subjectName);
        if(temp != NULL && temp->data == max)                           //max와 Student가 가진 subject 점수가 같다면 그 학생의 이름을 반환한다.
        {
//            if(topguy != "NULL")
//            {
//                cout << "There are more than two people who have top score. I'll return first guy name" << endl;
//                
//                cout << "And his name is " << topguy << " and his score is " << max << endl;
//                return topguy;
//            }
            topguy = studentArray[i].name;
            break;
        }
    }
    
    cout << "The guy who has the best score about "<< subjectName << " in this class is " << topguy << " and his score is " << max << endl;
    
    return topguy;
}
string ScoreBoard::get_top_student()
{
    string topguy = "NULL";
    float max = 0;
    
    for(int i = 0; i < numOfStudents; i++)
    {
        float temp = get_average_of_student(studentArray[i].name);
        if(max < temp)
        {
            max = temp;
            topguy = studentArray[i].name;
        }
    }
    
    cout << "The best guy in this class is " << topguy << " and his scrore is " << max << endl;
    
    return topguy;
}

float ScoreBoard::get_average_of_subject(string subjectName)
{
    float sum = 0;
    int numOfguys = 0;
    Node* temp;
    
    for(int i = 0; i < numOfStudents; i++)
    {
        temp = studentArray[i].scoreList->locate_str(subjectName);
        if(temp != NULL)
        {
            sum += temp->data;
            numOfguys++;
        }
    }
    
    if(numOfguys == 0)
    {
        cout << "You insert wrong subject name!" << endl;           //해당 subject를 가진 Student가 없다면 error문구 출력
        return -1;
    }
    
    return sum/numOfguys;
}

float ScoreBoard::get_average_of_student(string name)
{
    int i;
    float sum = 0;
    int numOfsub = 0;
    Node* temp;
    
    for(i = 0; i < numOfStudents; i++)
    {
        if(studentArray[i].name == name)
            break;
        if(i == numOfStudents - 1)
        {
            cout << "You insert wrong student name! " << endl;      //해당 Student없다면 error문구 출력
            return -1;
        }
    }
    
    for(int j = 0; j < numOfSubjects; j++)       //해당 Student의 scoreList에서 점수가 존재하는 subject만을 사용하여 평균값을 계산한다.
    {
        temp = studentArray[i].scoreList->locate_str(subjectArray[j]);
        if(temp != NULL)
        {
            sum += temp->data;
            numOfsub++;
        }
    }
    
    if(numOfsub == 0)           //해당 Student가 어떠한 점수도 가지고 있지 않다면 error문구를 띄운다.
    {
        cout << name << " takes no course." << endl;
        return -1;
    }
    else
        return sum/numOfsub;
}

float ScoreBoard::get_average_of_class()
{
    int numOfsub = 0;
    float sum = 0;
    
    for(int i = 0; i < numOfSubjects; i++)
    {
        float avg = get_average_of_subject(subjectArray[i]);
        if(avg != -1)
        {
            sum += avg;
            numOfsub++;
        }
    }
    
    cout << "Averge score of class is " << sum/numOfsub << endl;
    
    return sum/numOfsub;
}

void ScoreBoard::transfer(string name)              // 해당하는 Student를 없앤후 studentArray를 reallocation한다.
{
    
    Student* temp = new Student[numOfStudents - 1];
    
    for(int i = 0, j = 0; i < numOfStudents; i++, j++)
    {
        if(studentArray[i].name != name)
        {
            temp[j].scoreList = new LinkedList;
            
            temp[j].name = studentArray[i].name;
            
            for(int k = 0; k < numOfSubjects; k++)
            {
                Node* nTemp = studentArray[i].scoreList->locate_str(subjectArray[k]);
                
                if(nTemp!= NULL)
                    temp[j].scoreList->push_front(nTemp->str, nTemp->data);   //scoreList를 deep copy한다.
            }
        }
        else j--;
    }
    numOfStudents--;
    
    delete [] studentArray;
    
    studentArray = temp;
}

void ScoreBoard::abolish_subject(string subjectName)            //해당하는 subject를 없앤후 subjectArray를 reallocation한다.
{
    string* temp = new string[numOfSubjects - 1];
    
    for(int i = 0, j = 0; i < numOfSubjects; i++, j++)
    {
        if(subjectArray[i] != subjectName)
            temp[j] = subjectArray[i];
        else j--;
    }
    
    for(int k = 0; k < numOfStudents; k++)                      //Student들의 scroeList에서 해당하는 Node를 모두 지운다.
    {
        studentArray[k].scoreList->delete_node(studentArray[k].scoreList->locate_str(subjectName));
    }
    
    numOfSubjects--;
    
    delete [] subjectArray;
    
    subjectArray = temp;
}


void ScoreBoard::print()
{
    Node* temp;
    
    cout << "\t";
    for(int i = 0; i < numOfSubjects; i++)
    {
        cout << "\t" << subjectArray[i];
    }
    cout << endl;
    
    for(int i = 0; i < numOfStudents; i++)
    {
        cout << studentArray[i].name << "\t";
        
        for(int j = 0; j < numOfSubjects; j++)
        {
            temp = studentArray[i].scoreList->locate_str(subjectArray[j]);
            if(temp != NULL)
                cout << temp->data << "\t";
            else
                cout << "\t";
        }
        
        cout << endl;
    }
    cout << endl;
}
