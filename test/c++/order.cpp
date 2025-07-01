#include <iostream>
#include <string>
#include <vector>
#include <cassert>

class Order {
public:
    Order(const std::string& customer) : customerName(customer), isPaid(false) {}

    void addItem(const std::string& item, double price) {
        items.push_back(item);
        prices.push_back(price);
    }

    double total() const {
        double sum = 0.0;
        for (double price : prices) {
            sum += price;
        }
        return sum;
    }

    void pay() {
        isPaid = true;
    }

    bool paid() const {
        return isPaid;
    }

    std::string getCustomer() const {
        return customerName;
    }

    size_t itemCount() const {
        return items.size();
    }

private:
    std::string customerName;
    std::vector<std::string> items;
    std::vector<double> prices;
    bool isPaid;
};
