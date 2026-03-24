#pragma once

#include <string>
#include <vector>

#include "inventory.hpp"

class InventoryService {
public:
    const int maxLendingPeriodInWeeks = 4;

    std::vector<Book> searchForBookWithTitle(const std::string& query) const;
    std::vector<Book> searchForAvailableBookWithTitle(const std::string& query) const;
    std::vector<Book> getLentBooksForCustomer(const Customer& customer) const;
    std::vector<Book> getAllOverdueBooks() const;
};

extern const InventoryService inventoryService;
