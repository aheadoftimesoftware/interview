import {inventoryService} from "../src/inventory-service";
import {books, customers} from "../src/inventory";

describe('Inventory tests', () => {
    test('Search for books with string', () => {
        const result = inventoryService.searchForBookWithTitle("The")
        expect(result).toHaveLength(3)
        expect(result).toContain(books[2])
        expect(result).toContain(books[3])
        expect(result).toContain(books[4])
    })

    test('Search for available books with string', () => {
        const result = inventoryService.searchForAvailableBookWithTitle("The")
        expect(result).toHaveLength(1)
        expect(result).toContain(books[4])
    })

    test('Get lent books by customer', () => {
        const result = inventoryService.getLentBooksForCustomer(customers[3])
        expect(result).toHaveLength(2)
        expect(result).toContain(books[0])
        expect(result).toContain(books[2])
    })

    test('Get all overdue books', () => {
        const result = inventoryService.getAllOverdueBooks()
        expect(result).toHaveLength(2)
        expect(result).toContain(books[2])
        expect(result).toContain(books[3])
    })
})

