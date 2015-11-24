#include "LinkedList.h"
#include "ScoreBoard.h"

int main()
{
	string subjectArray[3] = {"math", "physics", "biology"};
	string studentArray[3] = {"John", "Tom", "Bob"};
	ScoreBoard* myClass = new ScoreBoard();

	
	myClass->set_subjects(&subjectArray[0], 3);
	myClass->set_students(&studentArray[0], 3);
	
	myClass->insert_score("John", "math", 80);
	myClass->insert_score("John", "biology", 60);
	myClass->insert_score("Tom", "biology", 90);
	myClass->insert_score("Tom", "math", 70);
	myClass->insert_score("Tom", "physics", 70);
	myClass->insert_score("Bob", "math", 85);
	myClass->insert_score("John", "physics", 95);
	myClass->insert_score("Bob", "physics", 77);
	myClass->insert_score("Bob", "biology", 92);

	cout << "===============================" << endl;
	myClass->print();
	cout << "===============================" << endl << endl;

	cout << myClass->get_top_student_in_subject("math") << " has the highest score in math: " << myClass->get_max_score_of_subject("math") << "." << endl;
	cout << myClass->get_top_student() << " is the best student in the class." << endl;
	cout << "The average score in the class is " << myClass->get_average_of_class() << "." << endl;
	cout << endl;
	
	myClass->transfer("Bob");
	cout << "==== After Bob transferred ====" << endl;
	myClass->print();
	cout << "===============================" << endl << endl;

	myClass->abolish_subject("math");
	cout << "== After math was abolished ===" << endl;
	myClass->print();
	cout << "===============================" << endl << endl;
	
	return 0;
}

/*
 * practice main
 *

 int main()
{
	LinkedList* a = new LinkedList();
	
	a->push_back("A", 100);
	a->push_back("B", 500);
	a->push_front("C", 300);
	Node* p = a->locate_data(100);
	a->insert("D", 200, p);
	p = a->locate_str("D");
	a->insert("E", 50, p);
	a->push_front("F", 250);
	p = a->locate_str("E");
	a->delete_node(p);
	a->print();
	cout << endl;

	a->selection_sort(true);
	a->print();
	cout << endl;

	a->selection_sort(false);
	a->print();
	cout << endl;

	return 0;
}
*/
