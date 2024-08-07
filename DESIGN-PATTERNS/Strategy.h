#ifndef STRATEGY_H
#define STRATEGY_H
#define INTERFACE class
#include<string>
#include<iostream>
#include <memory>

/*
 * Strategy is a behavioral design pattern that lets you define a family of algorithms, put each of them into
 * a separate class, and make their objects interchangeable.
 * The Strategy pattern suggests that you take a class that does something specific in a lot of different ways and
 * extract all of the algorithms into separate classes called strategies.
 * The original class, called context, must have a field for storing a reference to one of the strategies. The context
 * delegates the work to a linked strategy object instead of executing it on its own
 * References : www.refactoringguru.com
 */

INTERFACE PaymentStrategy {
    public:
        virtual void pay(const int& amount) const = 0;
        virtual ~PaymentStrategy() = default;
};

class CreditcardPayment final : public PaymentStrategy {
private:
    int _standingAmount = 1014;
public:
    void pay(const int& amount) const override {
        std::cout << "Paid " << amount << "$ through credit card, now total standing amount is " << _standingAmount + amount  << "$\n";
    }

};

class Paypal final : public PaymentStrategy {
private:
    int _wallet_balance = 200;
public:
    void pay(const int& amount) const override {
        std::cout << "Paid " << amount << "$ through paypal, remaining balance : " << _wallet_balance-amount << "$\n";
    }
};

class PaymentContext {
private:
    std::unique_ptr<PaymentStrategy> _strategy;
public:
    explicit PaymentContext(std::unique_ptr<PaymentStrategy> strategy) : _strategy(std::move(strategy)) {}

    void setStrategy(std::unique_ptr<PaymentStrategy> strategy) {
        _strategy = std::move(strategy);
    }

    void execPayment(const int& amount) const  {
        _strategy->pay(amount);
    }

};



#endif //STRATEGY_H
