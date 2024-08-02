#ifndef PROXY_H
#define PROXY_H
#include <iostream>
#include <string>
#include <utility>

/*
 * The Proxy pattern provides an intermediary object to control access to another object. It can be used for various purposes such as
 * lazy initialization, access control, logging, or remote access.
 *
 * Subject: Defines the interface for the real object and the proxy.
 * RealSubject: The actual object that the proxy controls.
 * Proxy: Intermediary object that manages access to the RealSubject.
 */

class Video {
public:
       virtual ~Video() = default;
       virtual void render() const = 0;
};

class HighResolutionVideo final : public Video {
private:
       std::string filename;
public:
       explicit HighResolutionVideo(std::string  file) : filename(std::move(file)){
              loadVideo();
       }

       void loadVideo() const {
              std::cout << "Loading video from " << filename << "\n";
       }

       void render() const override {
              std::cout << "Rendering high resolution video into : " << filename << "\n";
       }

};

class Proxy : public Video {
private:
       mutable HighResolutionVideo* high_resolution_video_;
       std::string filename;
public:
       explicit Proxy(std::string _filename) : high_resolution_video_(nullptr), filename(std::move(_filename)) {}



       void render() const override {
              if(!high_resolution_video_) {
                     high_resolution_video_ = new HighResolutionVideo(filename);
              }
              high_resolution_video_->render();
       }
};



#endif //PROXY_H
