#pragma once

#include <optional>
#include <string>

struct Customer {
    std::string name;
};

struct Book {
    std::string title;
    std::optional<Customer> lendTo;
    std::optional<int> lendWeeksAgo;
};
