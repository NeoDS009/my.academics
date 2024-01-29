
/*
Comments on the package (com.example.tutorial9):
Sorry if I haven't yet fixed this package and the path to this current source code, but if this package is this
    here, I just wanted to point out that it was automatically created when a "New Project with JavaFX as Generator"
    is initialized. For the path itself (T009- GUI_DVD_Collection > src > main > java > com > example > tutorial9), I tried many
    a times to relocate it (only put it under the "src" file), but it could not be done, as it would only become a
    java-text-file (can't be a "Java Class").

 */
package com.example.tutorial9;

/*
With an added <getDVDList method>
 */
public class DVDCollection {
    public static final int     MAX_DVDS = 100;

    private DVD[]   dvds;
    private int     dvdCount;

    public DVDCollection() { dvds = new DVD[MAX_DVDS]; }

    public DVD[] getDvds() { return dvds; }
    public int getDvdCount() { return dvdCount; }
    public String toString() { return ("DVD Collection of size " + dvdCount); }

    public void add(DVD aDvd) {
        if (dvdCount < MAX_DVDS)
            dvds[dvdCount++] = aDvd;
    }
    public boolean remove(String title) {
        for (int i=0; i<dvdCount; i++) {
            DVD d = dvds[i];
            if (dvds[i].getTitle().equals(title)) {
                dvds[i] = dvds[dvdCount-1];
                dvdCount--;
                return true;
            }
        }
        return false;
    }

    public static DVDCollection example1() {
        DVDCollection c = new DVDCollection();
        c.add(new DVD("If I Was a Student", 2007, 65));
        c.add(new DVD("Don't Eat Your Pencil !", 1984, 112));
        c.add(new DVD("The Exam", 2001, 180));
        c.add(new DVD("Tutorial Thoughts", 2003, 128));
        c.add(new DVD("Fried Monitors", 1999, 94));
        return c;
    }

    // Returning an array of only non-null DVDs with the help of <dvdCount>
    public DVD[] getDVDList() {
        DVD[] arrayOfDVDs = new DVD[dvdCount];
        for (int i = 0; i < dvdCount; i++) {
            arrayOfDVDs[i] = getDvds()[i];
        }
        return arrayOfDVDs;
    }
}