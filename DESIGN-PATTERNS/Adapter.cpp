#include "Adapter.h"

auto
clientCode(std::shared_ptr<Logger>& logger) -> void {
    logger->log("This is a log message!");
}

int main() {
    std::shared_ptr<ThirdPartyLogger> third_party_logger = std::make_shared<ThirdPartyLogger>();

    std::shared_ptr<Logger> logger = std::make_shared<LoggerAdapter>(third_party_logger);

    clientCode(logger);
    return 0;
}
