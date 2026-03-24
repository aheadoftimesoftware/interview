#include "inventory.hpp"

#include <optional>
#include <vector>

const std::vector<Customer>& customers() {
    static const std::vector<Customer> customerList = {
        {"Max Muster"},
        {"Martina Muller"},
        {"Sarah Kopf"},
        {"Thomas Mann"}
    };

    return customerList;
}

const std::vector<Book>& books() {
    static const std::vector<Book> bookList = {
        {"Do Androids Dream of Electric Sheep?", customers()[3], 1},
        {"Everything I Never Told You", std::nullopt, std::nullopt},
        {"Are You There, Vodka? It's Me, Chelsea", customers()[3], 5},
        {"The Devil Wears Prada", customers()[2], 10},
        {"The Curious Incident of the Dog in the Night-Time", std::nullopt, std::nullopt}
    };

    return bookList;
}
