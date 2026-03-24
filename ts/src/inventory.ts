import { subWeeks } from "date-fns";
import { Customer} from "./model";


export const customers: Customer[] = [
    {name: "Max Muster"},
    {name: "Martina Müller"},
    {name: "Sarah Kopf"},
    {name: "Thomas Mann"}
]


export const books: Book[] = [
    {title: "Do Androids Dream of Electric Sheep?", lendTo: customers[3], lendAt: subWeeks(new Date(), 1)},
    {title: "Everything I Never Told You", lendTo: null, lendAt: null},
    {title: "Are You There, Vodka? It’s Me, Chelsea", lendTo: customers[3], lendAt: subWeeks(new Date(), 5)},
    {title: "The Devil Wears Prada", lendTo: customers[2], lendAt: subWeeks(new Date(), 10)},
    {title: "The Curious Incident of the Dog in the Night-Time", lendTo: null, lendAt: null},
]