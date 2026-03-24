#include <functional>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "inventory.hpp"
#include "inventory_service.hpp"

namespace {

void expectContains(const std::vector<Book>& result, const Book& expected) {
    for (const Book& book : result) {
        if (book == expected) {
            return;
        }
    }

    throw std::runtime_error("Expected result to contain: " + expected.title);
}

void expectSize(const std::vector<Book>& result, std::size_t expectedSize) {
    if (result.size() != expectedSize) {
        std::ostringstream stream;
        stream << "Expected " << expectedSize << " result(s), got " << result.size();
        throw std::runtime_error(stream.str());
    }
}

void runTest(const std::string& name, const std::function<void()>& test, int& failures) {
    try {
        test();
        std::cout << "[PASS] " << name << '\n';
    } catch (const std::exception& error) {
        ++failures;
        std::cout << "[FAIL] " << name << ": " << error.what() << '\n';
    }
}

}  // namespace

int main() {
    int failures = 0;

    runTest("Search for books with string", []() {
        const std::vector<Book> result = inventoryService.searchForBookWithTitle("The");
        expectSize(result, 3);
        expectContains(result, books()[2]);
        expectContains(result, books()[3]);
        expectContains(result, books()[4]);
    }, failures);

    runTest("Search for available books with string", []() {
        const std::vector<Book> result = inventoryService.searchForAvailableBookWithTitle("The");
        expectSize(result, 1);
        expectContains(result, books()[4]);
    }, failures);

    runTest("Get lent books by customer", []() {
        const std::vector<Book> result = inventoryService.getLentBooksForCustomer(customers()[3]);
        expectSize(result, 2);
        expectContains(result, books()[0]);
        expectContains(result, books()[2]);
    }, failures);

    runTest("Get all overdue books", []() {
        const std::vector<Book> result = inventoryService.getAllOverdueBooks();
        expectSize(result, 2);
        expectContains(result, books()[2]);
        expectContains(result, books()[3]);
    }, failures);

    if (failures > 0) {
        std::cout << failures << " test(s) failed. Check the selected inventory service implementation.\n";
        return 1;
    }

    std::cout << "All tests passed.\n";
    return 0;
}
