#include "inventory_service.hpp"

#include <vector>

std::vector<Book> InventoryService::searchForBookWithTitle(const std::string& query) const {
    (void) query;
    // TODO: Return every book whose title contains the query string.
    return {};
}

std::vector<Book> InventoryService::searchForAvailableBookWithTitle(const std::string& query) const {
    (void) query;

    // TODO: Return matching books that are not currently lent out.
    return {};
}

std::vector<Book> InventoryService::getLentBooksForCustomer(const Customer& customer) const {
    (void) customer;

    // TODO: Return books currently lent to the provided customer.
    return {};
}

std::vector<Book> InventoryService::getAllOverdueBooks() const {
    // TODO: Return books whose lending age is greater than maxLendingPeriodInWeeks.
    return {};
}

const InventoryService inventoryService {};
