#include "Bridge.h"

int main() {
    Renderer* openglrenderer = new OpenGlRendererImpl();
    auto* circle =  new Circle(openglrenderer);
    circle->draw();

    Renderer* directxrenderer = new DirectXRendererImpl();
    auto* square = new Square(directxrenderer);
    square->draw();

    delete openglrenderer;
    delete directxrenderer;
    delete circle;
    delete square;



}