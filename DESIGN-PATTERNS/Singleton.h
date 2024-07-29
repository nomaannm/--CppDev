#ifndef SINGLETON_H
#define SINGLETON_H
#include<cassert>
#include <iostream>

/*
 * Singleton: Ensures a class has only one instance and provides a global point of access to it.
 * USE CASES : Renderer, Random Number Generator, Protagonist of a video game, etc.
 */


class Singleton {
private:
      //Made it private so as the class shouldn't get instantiated many times.
      Singleton()= default;
      static Singleton _singleton;

      // We have to delete the copy constructor to avoid creation of multiple instances.
      Singleton(const Singleton& copy) = delete;

public:
      static Singleton& getSingletonInstance() {
          return _singleton;
      }
      void Test() {
          std::cout << "Only Instance Running!\n";
      }

};



#endif //SINGLETON_H
