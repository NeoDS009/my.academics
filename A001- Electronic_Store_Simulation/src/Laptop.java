
/*
Our <Laptop> class
It consists to define the attributes of a <Laptop> object
It is also able to be called with initial arguments, 5 of them to be exact: CPU, RAM, storage, SSD, screen
It also displays a string when the <Laptop> object is directly called (by the .toString) method (two different outputs)
 */
public class Laptop {

    double CPU;
    int RAM;
    int storage;
    boolean SSD;
    int screen;
    public Laptop(double initCPU, int initRAM, int initStorage, boolean initSSD, int initScreen) {          // the constructor
        CPU = initCPU;
        RAM = initRAM;
        storage = initStorage;
        SSD = initSSD;
        screen = initScreen;
    }
    public String toString() {                                                                              // the .toString method

        if (SSD == false) {

            return screen + '"' + " Laptop PC with " + this.CPU + "ghz CPU, " + this.RAM + "GB RAM, " + this.storage + "GB HDD drive.";
        }
        else {
            return screen + '"' + " Laptop PC with " + this.CPU + "ghz CPU, " + this.RAM + "GB RAM, " + this.storage + "GB SSD drive.";
        }
    }
}