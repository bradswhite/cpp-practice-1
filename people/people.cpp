#include "people.h"

People::People() {}

void People::addPerson()
{
  Person person;
  peopleArr.push_back(person);
}
void People::addPerson(string firstName, string lastName, int age)
{
  Person person(firstName, lastName, age);
  peopleArr.push_back(person);
}

void People::greet()
{
  std::for_each(peopleArr.begin(), peopleArr.end(), [](Person person)
  {
    person.greet();
  });

  /*for (Person person : peopleArr)
  {
    person.greet();
  }*/
}

void People::messenger()
{
  string firstName;
  string lastName;
  cout << "What is your full name? ";
  cin >> firstName;
  cin >> lastName;

  vector<Person>::iterator person = std::find_if(peopleArr.begin(), peopleArr.end(), [firstName, lastName](Person p)
  {
    return firstName == p.firstName && lastName == p.lastName;
  });
  person->greet();
}
