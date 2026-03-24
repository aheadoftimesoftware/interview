#include "inventory_service.hpp"

#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

namespace {

bool titleContains(const Book& book, const std::string& query) {
    return book.title.find(query) != std::string::npos;
}

bool isAvailable(const Book& book) {
    return !book.lendTo.has_value();
}

bool isLentToCustomer(const Book& book, const Customer& customer) {
    return book.lendTo.has_value() && book.lendTo.value() == customer;
}

bool isOverdue(const Book& book, int maxLendingPeriodInWeeks) {
    return book.lendWeeksAgo.has_value() && book.lendWeeksAgo.value() > maxLendingPeriodInWeeks;
}

template <typename Predicate>
std::vector<Book> collectMatchingBooks(Predicate predicate) {
    const std::vector<Book>& inventory = books();
    std::vector<Book> result;
    result.reserve(inventory.size());

    std::copy_if(inventory.begin(), inventory.end(), std::back_inserter(result), predicate);
    return result;
}

}  // namespace

std::vector<Book> InventoryService::searchForBookWithTitle(const std::string& query) const {
    // Good: this names the domain rule once and delegates the shared filtering mechanics.
    // Bad: for such a tiny exercise, this level of abstraction is slightly heavier than the solid version.
    return collectMatchingBooks([&query](const Book& book) {
        return titleContains(book, query);
    });
}

std::vector<Book> InventoryService::searchForAvailableBookWithTitle(const std::string& query) const {
    // Good: the combined predicate reads almost exactly like the requirement sentence.
    // Bad: readers unfamiliar with std::copy_if may need one extra hop to inspect collectMatchingBooks.
    return collectMatchingBooks([&query](const Book& book) {
        return titleContains(book, query) && isAvailable(book);
    });
}

std::vector<Book> InventoryService::getLentBooksForCustomer(const Customer& customer) const {
    // Good: the customer-matching rule is isolated behind a clear helper name.
    // Bad: the extra helper indirection is only worthwhile because we are showcasing a model answer.
    return collectMatchingBooks([&customer](const Book& book) {
        return isLentToCustomer(book, customer);
    });
}

std::vector<Book> InventoryService::getAllOverdueBooks() const {
    // Good: the overdue policy stays centralized, so changing the threshold logic later is safe and obvious.
    // Bad: no major downside here beyond slightly more abstraction than the simplest possible approach.
    return collectMatchingBooks([this](const Book& book) {
        return isOverdue(book, maxLendingPeriodInWeeks);
    });
}

const InventoryService inventoryService {};
