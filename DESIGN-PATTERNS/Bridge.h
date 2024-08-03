#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>

/*
 * Bridge pattern splits a large class into two separate hierarchies which can be developed independently.
 * Abstraction and Implementation layers, Abstraction is a high level control layer which delegates the work to the implementation layer.
 * This is useful when you want to avoid a permanent binding between an abstraction and its implementation, allowing you to change or
 * extend either side without affecting the other.
 * Abstraction: Defines the interface for the "bridge" part of the pattern. It contains a reference to an implementation object.
 * RefinedAbstraction: Extends the Abstraction and provides a more specific implementation. This class uses the implementation object
   to carry out its operations.
 * Implementor: Defines the interface for the implementation classes. It provides methods that are used by the Abstraction.
 * ConcreteImplementor: Implements the Implementor interface. This class contains the actual implementation of the operations defined
   in the Implementor interface.
 */


//Implementor
struct Renderer {
    virtual void renderCircle() = 0;
    virtual void renderSquare() = 0;
    virtual ~Renderer() = default;
};

//ConcreteImplementors
struct OpenGlRendererImpl : Renderer {
    void renderCircle() override {
        std::cout << "Rendering a circle in OpenGL!\n";
    }
    void renderSquare() override {
        std::cout << "Rendering a square in OpenGL!\n";
    }
};
struct DirectXRendererImpl : Renderer {
    void renderCircle() override {
        std::cout << "Rendering a circle in DirectX!\n";
    }
    void renderSquare() override {
        std::cout << "Rendering a square in DirectX!\n";
    }
};

//Abstraction
class ShapeAbstraction {
protected:
    Renderer* renderer_;
public:
    explicit ShapeAbstraction(Renderer* r) : renderer_(r) {}
    virtual void draw() const = 0;
    virtual ~ShapeAbstraction() = default;
};

//RealAbstractions
class Circle final : public ShapeAbstraction {
public:
    explicit Circle(Renderer* r) : ShapeAbstraction(r){}
    void draw() const override {
        renderer_->renderCircle();
    }
};
class Square final : public ShapeAbstraction {
public:
    explicit Square(Renderer* r) : ShapeAbstraction(r) {}
    void draw() const override {
        renderer_->renderSquare();
    }
};



#endif //BRIDGE_H
