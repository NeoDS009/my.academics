
// import the package
package assignment4;

//Class representing an electronic store
//Has an array of products that represent the items the store can sell
import java.util.ArrayList;
import java.util.List;

/*
Description of the added methods
--> additional attributes + their corresponding getters and/or setters (to improve encapsulation)
--> getNonNullStock(): a method that returns the current stock of the E-store without the null values
--> swap(): a method that swaps the given elements of a list and returns the list with the swapped elements
--> sortAllProductsByPopularity(): a method that uses the swap() method: the smaller the index, the more soldQuantity they have, returns this list to the caller
--> mostPopularItems(): uses the sortAllProductsByPopularity() method and gets the top 3 elements of the list and returns it as a list to the caller
--> getTheProduct(): a method that will return the Product that has the corresponding toString() method attached to it (uses the getNonNullStock() for iteration)
--> gettingTheCurrentCartPrice(): a method that looks into the Current Cart's ListView and calculates the price that it would cost
--> getTheAverageRevenuePerSale(): a method that calculates the textField $/Sale with the revenue and the #Sale
 */
public class ElectronicStore {
    public final int MAX_PRODUCTS = 10; //Maximum number of products the store can have
    private int curProducts;
    private String name;
    private Product[] stock; //Array to hold all products
    private ArrayList<String> currentCartProducts;
    private ArrayList<Product> deletedItems;
    private int numSales;


    // constructor that initializes the needed attributes
    public ElectronicStore(String initName) {
        name = initName;
        stock = new Product[MAX_PRODUCTS];
        curProducts = 0;
        currentCartProducts = new ArrayList<>();
        deletedItems = new ArrayList<>();
        numSales = 1;
    }

    // added getters for easy access and promotion of encapsulation
    public Product[] getStock() {return stock;}
    public String getName() {return name;}
    public int getNumSales() {return numSales;}
    public void setNumSales(int numberOfSales) {this.numSales = numberOfSales;}
    public ArrayList<String> getCurrentCartProducts() {return currentCartProducts;}
    public ArrayList<Product> getDeletedItems() {return deletedItems;}

    // setters
    public void setStock(Product[] stock) {this.stock = stock;}


    //Adds a product and returns true if there is space in the array
    //Returns false otherwise
    public boolean addProduct(Product newProduct) {
        if (curProducts < MAX_PRODUCTS) {
            stock[curProducts] = newProduct;
            curProducts++;
            return true;
        }
        return false;
    }

    // additional method: return a non-null stock
    public Product[] getNonNullStock() {
        // get a copy of the list of the current store's stock
        int nonNull = 0;

        // getting the size of the non-null items
        for (int i = 0; i < stock.length; i++) {
            if (stock[i] != null) {
                nonNull++;
            }
        }

        // create a new array and fill it up from the stock
        Product[] nonNullStock = new Product[nonNull];

        for (int i = 0; i < nonNull; i++) {
            nonNullStock[i] = stock[i];
        }
        return nonNullStock;
    }

    // an additional method: for swapping two given elements of a given list
    private List<Product> swap(List<Product> l, int i, int j) {     ///////////////////////////////
        Product temp = l.get(i);
        l.set(i, l.get(j));
        l.set(j, temp);
        return l;
    }

    // additional method(): to sort all Products by their popularity/sold amount
    private List<Product> sortAllProductsByPopularity() {       ////////////////////////////////

        // initialize a list to store all sorted products
        List<Product> sortedProducts = new ArrayList<>();

        // fill it up by the stock (to be analyzed and manipulated)
        for (int i = 0; i < getNonNullStock().length; i++) {
            sortedProducts.add(stock[i]);
        }

        // initialize a while-loop to initialize a sorting algorithm to sort all products
        boolean run = true;

        while (run) {
            run = false;

            // for the elements, if the first's sold quantity is lesser than the second, swap them
            for (int i = 1; i < sortedProducts.size(); i++) {
                if (sortedProducts.get(i-1).getSoldQuantity() < sortedProducts.get(i).getSoldQuantity()){
                    sortedProducts = swap(sortedProducts, i-1, i);

                    run = true;
                }
            }
        }
        // return a sorted list of products
        return sortedProducts;
    }

    // additional method(): returns the top-3 most popular products of this Electronic Store
    public List<Product> mostPopularItems() {      //////////////////

        // initialize the needed lists
        List<Product> popularItems = new ArrayList<>();
        List<Product> sortedItems = sortAllProductsByPopularity();

        // add 3 element Products to the return list and then return it
        for (int i = 0; i <= 2; i++) {
            popularItems.add(sortedItems.get(i));
        }
        return popularItems;

    }

    // additional method(): returns the product that contains a same toString
    public Product getTheProduct(String theToString) {

        // searching through the current stock's list's items
        for (int j = 0; j < getNonNullStock().length; j++) {
            if (theToString.contains(getNonNullStock()[j].toString())) {
                return getNonNullStock()[j];
            }
        }

        // if it was not found in the current stock (was deleted): search it there
        for (int j = 0; j < getDeletedItems().size(); j++) {
            if (theToString.contains(getDeletedItems().get(j).toString())) {
                return getDeletedItems().get(j);
            }
        }

        // will not be called
        return null;
    }

    // additional method(): getting the current cart price
    public String gettingCurrentCartPrice() {

        double price = 0.0;
        if (getCurrentCartProducts().size() > 0) {
            for (int i = 0; i < getCurrentCartProducts().size(); i++) {

                if (getTheProduct(getCurrentCartProducts().get(i)) != null) {
                    price = price + (getTheProduct(getCurrentCartProducts().get(i)).getSoldQuantity() * getTheProduct(getCurrentCartProducts().get(i)).getPrice());
                }

            }
        }
        return String.format("%1.2f", price);
    }

    // additional method(): getting the $/sale method
    public String getTheAverageRevenuePerSale() {

        // get the revenue price
        double price = Double.parseDouble(gettingCurrentCartPrice());

        // but, we divide the revenue by numSales (where numSales == number of sales)
        return String.format("%1.2f", price/numSales);
    }


    public static ElectronicStore createStore() {
        ElectronicStore store1 = new ElectronicStore("Watts Up Electronics");
        Desktop d1 = new Desktop(100, 10, 3.0, 16, false, 250, "Compact");
        Desktop d2 = new Desktop(200, 10, 4.0, 32, true, 500, "Server");
        Laptop l1 = new Laptop(150, 10, 2.5, 16, true, 250, 15);
        Laptop l2 = new Laptop(250, 10, 3.5, 24, true, 500, 16);
        Fridge f1 = new Fridge(500, 10, 250, "White", "Sub Zero", false);
        Fridge f2 = new Fridge(750, 10, 125, "Stainless Steel", "Sub Zero", true);
        ToasterOven t1 = new ToasterOven(25, 10, 50, "Black", "Danby", false);
        ToasterOven t2 = new ToasterOven(75, 10, 50, "Silver", "Toasty", true);
        store1.addProduct(d1);
        store1.addProduct(d2);
        store1.addProduct(l1);
        store1.addProduct(l2);
        store1.addProduct(f1);
        store1.addProduct(f2);
        store1.addProduct(t1);
        store1.addProduct(t2);
        return store1;
    }
} 