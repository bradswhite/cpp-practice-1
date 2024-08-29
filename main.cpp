#include <iostream>
#include <string>
using namespace std;

#include "person/person.h"
#include "people/people.h"

int main()
{
        Person example("C", "Plus Plus", 50); 
        example.greet();
        example.shout("howdy sir");

        /*Person person;
        person.greet();
        person.messenger();*/

        People* people = new People();

        people->addPerson("Person", "#1", 1);
        people->addPerson("Person", "#2", 2);
        people->addPerson("Person", "#3", 3);
        people->addPerson();

        people->greet();

        people->messenger();

        delete people;

        return 0;
}
