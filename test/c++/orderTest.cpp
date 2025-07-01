
#include <iostream>
#include <string>
#include <vector>
#include <cassert>

// Minimal Order class implementation for testing
class Order {
    std::string customer;
    std::vector<std::pair<std::string, double>> items;
    bool isPaid = false;
public:
    Order(const std::string& c) : customer(c) {}
    std::string getCustomer() const { return customer; }
    void addItem(const std::string& name, double price) { items.emplace_back(name, price); }
    int itemCount() const { return static_cast<int>(items.size()); }
    double total() const {
        double sum = 0.0;
        for (const auto& item : items) sum += item.second;
        return sum;
    }
    void pay() { isPaid = true; }
    bool paid() const { return isPaid; }
};

// --- Unit Tests ---
void testOrderCreation() {
    Order o("Alice");
    assert(o.getCustomer() == "Alice");
    assert(o.itemCount() == 0);
    assert(o.total() == 0.0);
    assert(!o.paid());
}

void testAddItemAndTotal() {
    Order o("Bob");
    o.addItem("Book", 12.5);
    o.addItem("Pen", 1.5);
    assert(o.itemCount() == 2);
    assert(o.total() == 14.0);
}

void testPayment() {
    Order o("Charlie");
    o.addItem("Notebook", 5.0);
    assert(!o.paid());
    o.pay();
    assert(o.paid());
}

int main() {
    testOrderCreation();
    testAddItemAndTotal();
    testPayment();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}