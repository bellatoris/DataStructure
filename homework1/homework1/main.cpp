
//
//  main.cpp
//  homework1
//
//  Created by Doogie's mac on 2015. 9. 22..
//  Copyright © 2015년 Doogie's mac. All rights reserved.
//

#include <iostream>
#include <string>
#include <random>
#include "ScoreBoard.h"

int main()
{
    ScoreBoard* a = new ScoreBoard();
    
    random_device rng;

    a->print();
        
    string name[] = {"Doogie", "Geonho", "AminPark", "Yongseok", "Sehyun"};
    
    string subject[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
    
    a->set_students(name, 5);
    
    a->print();
    
    a->set_subjects(subject, 9);
    
    a->print();
    
    a->get_average_of_student("Doogie");
    
    
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            a->insert_score(name[i], subject[rng()%9], rng()%100);
        }
    }
    
    a->insert_score("do", subject[rng()%9], rng()%100);
    a->insert_score("Doogie", "haha", rng()%100);
    
    a->print();

    a->get_max_score_of_subject("A");
    a->get_max_score_of_student("Doogie");
    a->get_top_student_in_subject("B");
    a->get_top_student();
    a->get_average_of_subject("I");
    a->get_average_of_student("Sehyun1");
//    a->get_average_of_class();

    a->transfer("Geonho");
    a->transfer("Doogie");

    a->print();
    
    a->abolish_subject("A");
    
    a->print();

    delete a;
    
    return 0;
}