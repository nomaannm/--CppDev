#include "Observer.h"


int main() {
    WeatherStation<float> weatherStation{};

    PhoneApp<float> phoneApp;
    WebDashboard<float> webDashboard;
    LEDDisplay<float> ledDisplay;

    weatherStation.attach(&phoneApp);
    weatherStation.attach(&webDashboard);
    weatherStation.attach(&ledDisplay);

    weatherStation.setMeasurement(22.5f, 65.0f, 1013.0f);
    weatherStation.setMeasurement(25.0f, 60.5f, 1012.0f);

    return 0;
}