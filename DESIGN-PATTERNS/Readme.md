# DESIGN PATTERNS

Design patterns are typical solutions to common problems in software design. They represent best practices used by experienced developers to solve recurring problems in software design. Here are some of the most commonly used design patterns categorized into three main types: Creational, Structural, and Behavioral.

# CREATIONAL 
These patterns deal with object creation mechanisms, trying to create objects in a manner suitable to the situation.

__Singleton__: Ensures a class has only one instance and provides a global point of access to it.

__Factory Method__: Defines an interface for creating an object but lets subclasses alter the type of objects that will be created.

__Abstract Factory__: Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

__Builder__: Separates the construction of a complex object from its representation so that the same construction process can create different representations.

__Prototype__: Specifies the kinds of objects to create using a prototypical instance, creating new objects by copying this prototype.

# STRUCTURAL
These patterns deal with object composition or the way to realize relationships between entities.

__Adapter__: Allows incompatible interfaces to work together by converting the interface of a class into another interface the client expects.

__Decorator__: Adds additional responsibilities to an object dynamically, providing a flexible alternative to subclassing for extending functionality.

__Facade__: Provides a unified interface to a set of interfaces in a subsystem, making the subsystem easier to use.

__Proxy__: Provides a surrogate or placeholder for another object to control access to it.

__Bridge__: Separates an object’s interface from its implementation, allowing the two to vary independently.

__Composite__: Composes objects into tree structures to represent part-whole hierarchies, letting clients treat individual objects and compositions uniformly.

__Flyweight__: Reduces the cost of creating and manipulating a large number of similar objects by sharing common parts of state among multiple objects.

# BEHAVIOURAL
These patterns deal with object interaction, defining how objects and classes interact and how responsibilities are distributed among them.

__Observer__: Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

__Strategy__: Defines a family of algorithms, encapsulates each one, and makes them interchangeable, allowing the algorithm to vary independently from clients that use it.

__Command__: Encapsulates a request as an object, thereby allowing users to parameterize clients with queues, requests, and operations.

__Chain of Responsibility__: Allows an object to pass the request along a chain of potential handlers until the request is handled.

__Mediator__: Defines an object that encapsulates how a set of objects interact, promoting loose coupling by keeping objects from referring to each other explicitly.

__Iterator__: Provides a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

__State__: Allows an object to alter its behavior when its internal state changes, appearing as if it changed its class.

__Template Method__: Defines the skeleton of an algorithm in the superclass but lets subclasses override specific steps of the algorithm without changing its structure.

__Visitor__: Represents an operation to be performed on elements of an object structure, allowing new operations to be defined without changing the classes of the elements on which it operates.

__Memento__: Without violating encapsulation, captures and externalizes an object’s internal state so that the object can be restored to this state later.

__Interpreter__: Given a language, defines a representation for its grammar along with an interpreter that uses the representation to interpret sentences in the language.

Understanding and applying these design patterns can help improve the flexibility, maintainability, and scalability of your software design.