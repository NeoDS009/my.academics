
/*
Our <Fridge> class
It consists to define the attributes of a <Fridge> object
It is also able to be called with initial arguments, 3 of them to be exact: size, freezer, color
It also displays a string when the <Fridge> object is directly called (by the .toString) method (2 different outpyts, depending if it has a freezer or not)
 */
public class Fridge {

    double size;
    boolean freezer;
    String color;
    public Fridge(double initSize, boolean initFreezer, String initColor) {             // the constructor
        size = initSize;
        freezer = initFreezer;
        color = initColor;
    }
    public String toString() {                                                          // the .toString method

        if (freezer == false) {
            return size + " cubic foot Fridge " + "(" + color + ")";
        }
        else {
            return size + " cubic foot Fridge with Freezer " + "(" + color + ")";
        }
    }
}