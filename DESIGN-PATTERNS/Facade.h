#ifndef FACADE_H
#define FACADE_H
#include <iostream>

/*
 * Facade is a structural design pattern which provides a simplified interface to a library, a framework or a complex set of classes.
 * Benefits:
       Reduces the complexity of client code.
       Decouples the client from the subsystem, which can make the system more modular and easier to maintain.
 * Use Case: Useful when you have a complex system with many interdependent classes, and you want to provide a simpler API for clients
   to interact with it.
 * Example :
   Imagine a home theater system with various components like a DVD player, projector, and sound system. Instead of having clients
   interact with each component separately, you create a HomeTheaterFacade that provides simple methods like watchMovie()
   or endMovie() to manage the entire system.
 */

class DVDPlayer {
public:
    static auto on() -> void {
        std::cout << "DVD Player running !\n";
    }
    static auto off() -> void {
        std::cout << "DVD Player off!\n";
    }
    static auto play(const std::string& movie) -> void {
        std::cout << movie << " is playing!\n";
    }

};

class Projector {
public:
    static auto on() -> void {
        std::cout << "Projector On!\n";
    }
    static auto off() -> void {
        std::cout << "Projector Off!\n";
    }
    static auto connected() -> void {
        std::cout << "Projector is connected to DVD Player!\n";
    }
};

class SoundSystem {
public:
    static auto on() -> void {
        std::cout << "Sound system running!\n";
    }
    static auto off() -> void {
        std::cout << "Sound system off!\n";
    }
    static auto connected() -> void {
        std::cout << "System connected to DVDPlayer!\n";
    }
};



class HomeTheatorFacade {
public:
    ~HomeTheatorFacade() = default;
    static auto watchMovie(const std::string& movie) -> void {
        DVDPlayer::on();
        Projector::on();
        Projector::connected();
        SoundSystem::on();
        SoundSystem::connected();
        DVDPlayer::play(movie);
    }

    static auto endMovie() -> void {
        DVDPlayer::off();
        SoundSystem::off();
        Projector::off();
    }

};



#endif //FACADE_H
