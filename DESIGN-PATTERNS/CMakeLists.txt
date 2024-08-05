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

)