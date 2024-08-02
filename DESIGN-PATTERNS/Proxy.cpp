#include "Proxy.h"


int main() {
    Video* video1 = new Proxy("Video1");
    Video* video2 = new Proxy("Video2");

    video1->render();

    video2->render();

    video1->render();

    delete video1;
    delete video2;
}