#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
  public:
    string firstName;
    string lastName;
    int age;

    Person() {
      askInfo();
    }

    Person(string firstName, string lastName, int age)
    {
      this->firstName = firstName;
      this->lastName = lastName;
      this->age = age;
    }

    void greet()
    {
      cout << "Hello, " << firstName << " " << lastName << "!" << endl;
      cout << "You are " << age << " years old!" << endl;
    }

    using speech_fn_t = void (Person::*)(string);

    void messenger()
    {
      string msg;
      
      vector<speechUtils> utils;
      utils.push_back(make_speech_util(&Person::shout, "What do you want to shout? "));
      utils.push_back(make_speech_util(&Person::whisper, "What do you want to whisper? "));

      cin.ignore();
      for (speechUtils& util : utils)
      {
        cout << util.prompt;
        getline(cin, msg);
        speak(util.fn, msg);
        msg = "";
      }
      cout << "Thanks for playing!" << endl;
    }

    void speak(speech_fn_t speechFn, string msg)
    {
      (this->*speechFn)(msg);
    }

    void shout(string message)
    {
      for (char &c: message)
        c = c & ~' ';
      cout << message << "!!!" << endl;
    }
    
    void whisper(string message)
    {
      for (char &c: message)
        c = c | ' ';
      cout << message << "." << endl;
    }

  private:
    struct speechUtils
    {
      speech_fn_t fn;
      string prompt;
    };
    speechUtils make_speech_util(speech_fn_t fn, string prompt)
    {
      speechUtils util = { fn, prompt };
      return util;
    }

    void askInfo()
    {
      ask(&Person::firstName, "What is your first name? ");
      ask(&Person::lastName, "What is your last name? ");
      ask(&Person::age, "What is your age? ");
    }

    template <typename V>
    void ask(V Person::*value, string prompt)
    {
      cout << prompt << endl;
      cin >> this->*value;
    }

};

class People
{
  public:
    vector<Person> peopleArr;
    
    People() {}

    void addPerson()
    {
      Person person;
      peopleArr.push_back(person);
    }
    void addPerson(string firstName, string lastName, int age)
    {
      Person person(firstName, lastName, age);
      peopleArr.push_back(person);
    }

    void greet()
    {
      for (Person person : peopleArr)
      {
        person.greet();
      }
    }

    void messenger()
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

};

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
