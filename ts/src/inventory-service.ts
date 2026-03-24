import { Book, Customer } from "./model";

interface IInventoryService {
  readonly maxLendingPeriodInWeeks: number;

  searchForBookWithTitle: (query: string) => Book[];

  searchForAvailableBookWithTitle: (query: string) => Book[];

  getLentBooksForCustomer: (customer: Customer) => Book[];

  getAllOverdueBooks: () => Book[];
}

class InventoryService implements IInventoryService {
  readonly maxLendingPeriodInWeeks: number = 4;
}

export const inventoryService = new InventoryService();
