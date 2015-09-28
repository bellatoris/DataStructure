//
//  ScoreBoard.h
//  homework1
//
//  Created by Doogie's mac on 2015. 9. 22..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//


#ifndef ScoreBoard_H_
#define ScoreBoard_H_

#include "LinkedList.h"

class Student
{
public:
	string name;
	LinkedList* scoreList;

	Student();
	~Student();
};

class ScoreBoard
{
public:
	ScoreBoard();
	~ScoreBoard();

	void set_subjects(string* subjectArray, int numOfSubjects);
	void set_students(string* studentNameArray, int numOfStudents);
	void insert_score(string name, string subjectName, int score);
	
	int get_max_score_of_subject(string subjectName);
	Node* get_max_score_of_student(string name);
	string get_top_student_in_subject(string subjectName);
	string get_top_student();
	float get_average_of_subject(string subjectName);
	float get_average_of_student(string name);
	float get_average_of_class();
	
	void transfer(string name);
	void abolish_subject(string subjectName);
	void print();
private:
	string* subjectArray;
	int numOfSubjects;
	Student* studentArray;
	int numOfStudents;
};


#endif /* ScoreBoard_h */