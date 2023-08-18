
/*
Our <Desktop> class
It consists to define the attributes of a <Desktop> object
It is also able to be called with initial arguments, 4 of them to be exact: CPU, RAM, storage, SSD
It also displays a string when the <Desktop> object is directly called (by the .toString) method (two different outputs, depending if it has an SSD or not)
 */
public class Desktop {
    double CPU;
    int RAM;
    int storage;
    boolean SSD;
    public Desktop(double initCPU, int initRAM, int initStorage, boolean initSSD) {         // the constructor
        CPU = initCPU;
        RAM = initRAM;
        storage = initStorage;
        SSD = initSSD;
    }
    public String toString() {                                                             // the .toString method

        if (SSD == false) {

            return "Desktop PC with " + this.CPU + "ghz CPU, " + this.RAM + "GB RAM, " + this.storage + "GB HDD drive.";
        }
        else {
            return "Desktop PC with " + this.CPU + "ghz CPU, " + this.RAM + "GB RAM, " + this.storage + "GB SSD drive.";
        }
    }
}