#include "person.h"

using speech_fn_t = void (Person::*)(string);

Person::Person() { askInfo(); }
Person::Person(string firstName, string lastName, int age) : firstName(firstName), lastName(lastName), age(age) {}

void Person::greet()
{
        cout << "Hello, " << firstName << " " << lastName << "!" << endl;
        cout << "You are " << age << " years old!" << endl;
}

void Person::messenger()
{
        string msg;

        speechUtils utils[2] = {
        make_speech_util(&Person::shout, "What do you want to shout? "),
        make_speech_util(&Person::whisper, "What do you want to whisper? ")
        };

        cin.ignore();
        for (speechUtils& util : utils) {
        cout << util.prompt;
        getline(cin, msg);
        speak(util.fn, msg);
        msg = "";
        }
        cout << "Thanks for playing!" << endl;
}

void Person::speak(speech_fn_t speechFn, string msg) { (this->*speechFn)(msg); }

void Person::shout(string message)
{
        for (char &c: message)
                c = c & ~' ';
        cout << message << "!!!" << endl;
}

void Person::whisper(string message)
{
        for (char &c: message)
                c = c | ' ';
        cout << message << "." << endl;
}

Person::speechUtils Person::make_speech_util(speech_fn_t fn, string prompt)
{
        speechUtils util = { fn, prompt };
        return util;
}


void Person::askInfo()
{
        ask(&Person::firstName, "What is your first name? ");
        ask(&Person::lastName, "What is your last name? ");
        ask(&Person::age, "What is your age? ");
}

template <typename V>
void Person::ask(V Person::*value, string prompt)
{
        cout << prompt << endl;
        cin >> this->*value;
}
