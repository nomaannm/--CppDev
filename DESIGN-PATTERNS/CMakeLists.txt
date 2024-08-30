cmake_minimum_required(VERSION 3.10)

add_library(design_patterns STATIC
            Visitor.cpp
        Singleton.cpp
        FactoryMethod.cpp
        AbstractFactory.cpp
        Builder.cpp
        Prototype.cpp
        Adapter.cpp
        Decorator.cpp
        Facade.cpp
        Proxy.cpp
        Bridge.cpp
        Flyweight.cpp
        Observer.cpp
        Strategy.cpp
        Command.cpp
        Command.h
        ChainOfResponsibility.cpp
        ChainOfResponsibility.h
        Mediator.cpp
        Mediator.h
        Iterator.cpp
        Iterator.h
        State.cpp
        State.h
        TemplateMethod.cpp
        TemplateMethod.h
        Memento.cpp
        Memento.h

)