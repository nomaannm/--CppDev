#include "Strategy.h"


int main() {
    auto context = PaymentContext(std::make_unique<CreditcardPayment>());
    context.execPayment(100);

    context.setStrategy(std::make_unique<Paypal>());
    context.execPayment(250);

    return 0;
}