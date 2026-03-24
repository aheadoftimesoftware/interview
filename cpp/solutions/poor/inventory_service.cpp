#include "inventory_service.hpp"

#include <string>
#include <vector>

namespace {

bool titleContainsInALongWay(const std::string& title, const std::string& query) {
    // Bad: std::string::find already expresses this intent much more clearly.
    // Good: the logic is still explicit enough to follow if someone steps through it in a debugger.
    if (query.empty()) {
        return true;
    }

    std::size_t outerIndex = 0;

    while (outerIndex < title.size()) {
        std::size_t queryIndex = 0;
        std::size_t titleIndex = outerIndex;

        while (titleIndex < title.size() && queryIndex < query.size()) {
            if (title[titleIndex] != query[queryIndex]) {
                break;
            }

            ++titleIndex;
            ++queryIndex;
        }

        if (queryIndex == query.size()) {
            return true;
        }

        ++outerIndex;
    }

    return false;
}

}  // namespace

std::vector<Book> InventoryService::searchForBookWithTitle(const std::string& query) const {
    // Bad: copying the entire inventory and copying each title is unnecessary work.
    // Good: despite the waste, the method still stays deterministic and testable.
    const std::vector<Book> allBooks = books();
    std::vector<Book> result;

    for (std::size_t index = 0; index < allBooks.size(); ++index) {
        bool shouldAdd = false;
        const std::string titleCopy = allBooks[index].title;

        if (titleContainsInALongWay(titleCopy, query)) {
            shouldAdd = true;
        }

        if (shouldAdd == true) {
            result.push_back(allBooks[index]);
        }
    }

    return result;
}

std::vector<Book> InventoryService::searchForAvailableBookWithTitle(const std::string& query) const {
    // Bad: this takes a two-pass approach and creates extra temporary vectors for no strong reason.
    // Good: breaking the work into steps can sometimes help a beginner understand the filtering process.
    const std::vector<Book> titleMatches = searchForBookWithTitle(query);
    std::vector<Book> result;

    for (std::size_t index = 0; index < titleMatches.size(); ++index) {
        bool bookIsLent = false;

        if (titleMatches[index].lendTo.has_value()) {
            bookIsLent = true;
        }

        if (bookIsLent == false) {
            result.push_back(titleMatches[index]);
        }
    }

    return result;
}

std::vector<Book> InventoryService::getLentBooksForCustomer(const Customer& customer) const {
    // Bad: more unnecessary copying and verbose condition handling than the problem needs.
    // Good: every branch is spelled out, so hidden behavior is limited even if the style is clumsy.
    const std::vector<Book> allBooks = books();
    std::vector<Book> result;

    for (std::size_t index = 0; index < allBooks.size(); ++index) {
        bool shouldAdd = false;

        if (allBooks[index].lendTo.has_value()) {
            const Customer borrowedBy = allBooks[index].lendTo.value();

            if (borrowedBy == customer) {
                shouldAdd = true;
            }
        }

        if (shouldAdd) {
            result.push_back(allBooks[index]);
        }
    }

    return result;
}

std::vector<Book> InventoryService::getAllOverdueBooks() const {
    // Bad: the code repeats the same manual pattern again instead of sharing one small abstraction.
    // Good: the business rule is still technically correct, so the tests protect the behavior.
    const std::vector<Book> allBooks = books();
    std::vector<Book> result;

    for (std::size_t index = 0; index < allBooks.size(); ++index) {
        bool shouldAdd = false;

        if (allBooks[index].lendWeeksAgo.has_value()) {
            const int lendingAge = allBooks[index].lendWeeksAgo.value();

            if (lendingAge > maxLendingPeriodInWeeks) {
                shouldAdd = true;
            }
        }

        if (shouldAdd) {
            result.push_back(allBooks[index]);
        }
    }

    return result;
}

const InventoryService inventoryService {};
