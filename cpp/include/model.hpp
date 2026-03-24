#pragma once

#include <optional>
#include <string>

struct Customer {
    std::string name;

    bool operator==(const Customer& other) const {
        return name == other.name;
    }
};

struct Book {
    std::string title;
    std::optional<Customer> lendTo;
    std::optional<int> lendWeeksAgo;

    bool operator==(const Book& other) const {
        return title == other.title;
    }
};
