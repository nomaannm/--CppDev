#ifndef OBSERVER_H
#define OBSERVER_H
#include<vector>
#include<algorithm>
#include<iostream>
/*
 * The Observer design pattern is a behavioral pattern used to create a subscription mechanism to allow multiple objects (observers)
 * to listen and react to events or changes in another object (the subject). It's useful when you want to establish a one-to-many
 * relationship between objects, so that when the state of one object changes, all its dependents are notified and updated automatically.
 *
 * Components
    Subject: The object that maintains a list of observers and notifies them of any changes. It usually has methods to attach, detach,
    and notify observers.
    Observer: The interface or abstract class that defines the update method, which is called when the subject's state changes.
    ConcreteSubject: A concrete implementation of the Subject that holds the state and notifies observers of changes.
    ConcreteObserver: A concrete implementation of the Observer that reacts to changes in the ConcreteSubject.

 * Key Points
    Decoupling: The Observer pattern decouples the subject from the observers, allowing you to add or remove observers without changing
    the subject's code.
    Dynamic Updates: Observers are notified dynamically when the subject's state changes, making it suitable for real-time applications.
    Flexibility: You can have multiple observers listening to the same subject, and you can also have a single observer listening to
    multiple subjects.
 */



template<typename T>
//Observer
class IObserverDisplay {
public:
    virtual void update(T temperature, T humidity, T pressure) const = 0;
    virtual ~IObserverDisplay() = default;
};

template<typename T>
//Subject
class WeatherStation {
private:
    std::vector<IObserverDisplay<T>*> displays{};
    T temperature;
    T humidity;
    T pressure;
public:
    void attach(IObserverDisplay<T>* display ) {
        displays.push_back(display);
    }

    void detach(IObserverDisplay<T>* display) {
        displays.erase(std::remove(displays.begin(), displays.end(), display), displays.end());
    }

    void notify() const noexcept {
        std::cout << "Notifying Observers!\n";
        for(const auto& display : displays) {
            display->update(temperature, humidity, pressure);
        }
    }

    void setMeasurement(T temp, T humid, T press) {
        temperature = temp;
        humidity = humid;
        pressure = press;
    }
};

//Concrete Observers
template<typename T>
class PhoneApp : public IObserverDisplay<T> {
public:
    void update(T temperature, T humidity, T pressure) const override {
        std::cout << "PhoneApp - Temperature: " << temperature
                  << "°C, Humidity: " << humidity
                  << "%, Pressure: " << pressure << " hPa" << std::endl;
    }
};

template<typename T>
class WebDashboard : public IObserverDisplay<T> {
public:
    void update(T temperature, T humidity, T pressure) const override {
        std::cout << "WebDashboard - Temperature: " << temperature
                  << "°C, Humidity: " << humidity
                  << "%, Pressure: " << pressure << " hPa" << std::endl;
    }
};

template<typename T>
class LEDDisplay : public IObserverDisplay<T> {
public:
    void update(T temperature, T humidity, T pressure) const override {
        std::cout << "LEDDisplay - Temp: " << temperature
                  << "°C, Humidity: " << humidity
                  << "%, Pressure: " << pressure << " hPa" << std::endl;
    }
};



#endif //OBSERVER_H
