
/*
This is my ElectronicStore;
It contains its main attributes: 9 objects ( 3 desktops, 3 laptops, and 3 fridges),
    all of which has been initialized by the <ElectronicStore> method.
It also contains a <printStock> method, in which it prints all and every <.toString> name of those objects (defined in their specific java classes)
It also contains a <searchStock> method, in which it consists of a bunch of if statements to verify if the given string argument
    is a part of one of the <.toString> objects' names (where it is case-insensitive).
 */

public class ElectronicStore {

    String name;

    public String storeName (String initName) {
        name = initName;
        return name;
    }

    Desktop d1, d2, d3;         // Variables to store their corresponding objects
    Laptop l1, l2, l3;
    Fridge f1, f2, f3;

    public ElectronicStore() {                                                  // the Constructor
        d1 = new Desktop(3.5, 8, 500, false);
        d2 = new Desktop(3.0, 16, 250, true);
        d3 = new Desktop(4.2, 32, 500, true);

        l1 = new Laptop(3.1, 32, 500, true, 15);
        l2 = new Laptop(2.5, 8, 250, false, 13);
        l3 = new Laptop(4.2, 16, 500, false, 16);

        f1 = new Fridge(15.6, true, "Gray");
        f2 = new Fridge(10.5, false, "White");
        f3 = new Fridge(22.2, true, "Silver");
    }
    public void printStock() {                  // the printStock method

        System.out.println(d1);
        System.out.println(d2);
        System.out.println(d3);
        System.out.println(l1);
        System.out.println(l2);
        System.out.println(l3);
        System.out.println(f1);
        System.out.println(f2);
        System.out.println(f3);

    }
    /*
    The searchStock method will compare two strings, each and every instances of Desktop, Laptop, and Fridge, with the given argument.
    The toString method of the previous instances will first convert them into their said pre-determined strings,
    then, the toLowerCase method will convert the previous string into lower-case,
    finally, we compared them all with the given argument.
    If one of them matches up, the <truthCounter> will increment by a value of "1".
    If by the end, the <truthCounter> possesses a value that is not "0", then that means that there has been one case found of the
    matching given string argument, thus the method will return <true>, whilst <false> otherwise.
     */
    public boolean searchStock(String x) {          // the searchStock method

        int truthCounter = 0;

        String stuff = x.toLowerCase();

        if (d1.toString().toLowerCase().contains(stuff)) {          // control-flow to search if the argument is contained
            truthCounter++;
        }
        if (d2.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (d3.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (l1.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (l2.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (l3.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (f1.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (f2.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }
        if (f3.toString().toLowerCase().contains(stuff)) {
            truthCounter++;
        }

        if (truthCounter == 0) {                                // verifying if the argument was found or not
            return false;
        }
        else {
            return true;
        }
    }
}