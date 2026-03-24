#include "inventory_service.hpp"

#include <string>
#include <vector>

namespace {

bool titleContains(const Book& book, const std::string& query) {
    return book.title.find(query) != std::string::npos;
}

}  // namespace

std::vector<Book> InventoryService::searchForBookWithTitle(const std::string& query) const {
    // Good: this solution is direct, const-correct, and easy to verify against the tests.
    // Bad: each public method still repeats the same "loop and push matches" pattern.
    std::vector<Book> result;

    for (const Book& book : books()) {
        if (titleContains(book, query)) {
            result.push_back(book);
        }
    }

    return result;
}

std::vector<Book> InventoryService::searchForAvailableBookWithTitle(const std::string& query) const {
    // Good: the filtering rules stay close to the requirement and remain readable.
    // Bad: this duplicates some title-matching logic instead of sharing a reusable helper.
    std::vector<Book> result;

    for (const Book& book : books()) {
        if (titleContains(book, query) && !book.lendTo.has_value()) {
            result.push_back(book);
        }
    }

    return result;
}

std::vector<Book> InventoryService::getLentBooksForCustomer(const Customer& customer) const {
    // Good: compares the actual domain objects and avoids unnecessary copies.
    // Bad: like the other methods, it is simple but not especially reusable.
    std::vector<Book> result;

    for (const Book& book : books()) {
        if (book.lendTo.has_value() && book.lendTo.value() == customer) {
            result.push_back(book);
        }
    }

    return result;
}

std::vector<Book> InventoryService::getAllOverdueBooks() const {
    // Good: the overdue rule is explicit and mirrors the interview wording.
    // Bad: this still relies on another hand-written loop rather than a shared filter utility.
    std::vector<Book> result;

    for (const Book& book : books()) {
        if (book.lendWeeksAgo.has_value() && book.lendWeeksAgo.value() > maxLendingPeriodInWeeks) {
            result.push_back(book);
        }
    }

    return result;
}

const InventoryService inventoryService {};
