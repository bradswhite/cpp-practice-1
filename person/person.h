#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person
{
  public:
    string firstName;
    string lastName;
    int age;

    Person();
    Person(string firstName, string lastName, int age);

    void greet();

    using speech_fn_t = void (Person::*)(string);
    
    struct speechUtils {
      speech_fn_t fn;
      string prompt;
    };

    void messenger();

    void speak(speech_fn_t speechFn, string msg);
   
    void shout(string message);

    void whisper(string message);

  private:
    speechUtils make_speech_util(speech_fn_t fn, string prompt);

    void askInfo();

    template <typename V>
    void ask(V Person::*value, string prompt);
    
};

#endif
