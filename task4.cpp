#include <iostream>
using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amt) = 0;
};

class CreditCard : public PaymentMethod {
private:
    string cardNo;

public:
    CreditCard(string cn) {
        cardNo = cn;
    }

    void processPayment(double amt) override {
        if (cardNo.length() == 16) {
            cout << "Credit Card Payment of $" << amt << " processed successfully." << endl;
        } else {
            cout << "Invalid card number. Payment failed." << endl;
        }
    }
};

class DigitalWallet : public PaymentMethod {
private:
    double bal;

public:
    DigitalWallet(double b) {
        bal = b;
    }

    void processPayment(double amt) override {
        if (bal >= amt) {
            bal -= amt;
            cout << "Digital Wallet Payment of $" << amt << " processed successfully." << endl;
            cout << "Remaining Balance: $" << bal << endl;
        } else {
            cout << "Insufficient wallet balance. Payment failed." << endl;
        }
    }
};

int main() {
    CreditCard c1("1234567890123456");
    DigitalWallet w1(500);

    cout << "Payment System:" << endl;

    c1.processPayment(200);
    w1.processPayment(300);
    w1.processPayment(250);

    return 0;
}
