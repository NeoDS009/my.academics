
/*
Comments on the package (com.example.tutorial9):
Sorry if I haven't yet fixed this package and the path to this current source code, but if this package is this
    here, I just wanted to point out that it was automatically created when a "New Project with JavaFX as Generator"
    is initialized. For the path itself (T009- GUI_DVD_Collection > src > main > java > com > example > tutorial9), I tried many
    a times to relocate it (only put it under the "src" file), but it could not be done, as it would only become a
    java-text-file (can't be a "Java Class").

 */
package com.example.tutorial9;

public class DVD implements Comparable {
    private   String    title;
    private   int       year;
    private   int       duration;

    public DVD () { this ("",0,0); }
    public DVD (String newTitle, int y, int minutes) {
        title = newTitle;
        year = y;
        duration = minutes;
    }

    public int compareTo(Object obj) {
        if (obj instanceof DVD) {
            DVD aDVD = (DVD)obj;
            return title.compareTo(aDVD.title);
        }
        return 0;
    }

    public String getTitle() { return title; }
    public int getDuration() { return duration; }
    public int getYear() { return year; }
    public void setTitle(String t) { title = t; }
    public void setDuration(int d) { duration = d; }
    public void setYear(int y) { year = y; }

    public String toString() {
        return ("DVD (" + year + "): \"" + title + "\" with length: " + duration + " minutes");
    }
}