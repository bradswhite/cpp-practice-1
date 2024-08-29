#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "../person/person.h"

using namespace std;

#ifndef PEOPLE_H
#define PEOPLE_H

class People
{
        public:
                vector<Person> peopleArr;

                People();

                void addPerson();
                void addPerson(string firstName, string lastName, int age);

                void greet();

                void messenger();
};

#endif
