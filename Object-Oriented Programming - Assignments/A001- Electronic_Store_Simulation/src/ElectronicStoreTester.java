
/*
Our <ElectronicStoreTester> class
It contains an import statement of the <Scanner> class, to be able to intake user inputs
    (for the comparison and the later <searchStock> methods)
It contains a <main> method: allowing the code to run and compile
It contains an intialization and calling to the <ElectronicStore>, so we can use its attributes and methods
It contains a <while-loop> to continuously seek for user input:
    where it shall be taken into comparison with the store's all objects (with the <searchStock> method)
It contains an if-else branch structure to identify if the given user input is found amoungst the store's objects,
    and print out an answer matching its way
It contains an evaluator to see if the user input == "quit" and if so, the <while-loop> shall stop
 */

import java.util.Scanner;       //Import the Scanner class to be able to call it and to be able to read user inputs
public class ElectronicStoreTester {
    public static void main(String args[]) {                        // the main class to allow for code to be compiled

        ElectronicStore theStore;

        theStore = new ElectronicStore();                           // instantiate the <ElectronicStore>

        System.out.println("The store includes: ");
 
        theStore.printStock();                                      // print all of the <ElectronicStore>'s objects (with the .printStock method)

        boolean run = true;                                         // a boolean flag (to stop a while loop)

        while (run) {                                               // the <while-loop> to continuously run

            System.out.print("Enter a term to search for: ");

            Scanner userSearch = new Scanner(System.in);

            String toCompare = userSearch.nextLine();

            if ("quit".equals(toCompare)) {                         // a branching if-else to verify if the user wants to quit
                run = false;
            }
            else {                                                  // another branching to print out the correct statement for the argument-matching
                if (theStore.searchStock(toCompare) == true) {
                    System.out.println("A matching item is contained in the store's stock.");
                } else {
                    System.out.println("No items in the store's stock match that term.");
                }
            }
        }
    }
}
