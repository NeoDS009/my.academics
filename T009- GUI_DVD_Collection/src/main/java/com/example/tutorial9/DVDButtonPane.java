

/*
Comments on the package (com.example.tutorial9):
Sorry if I haven't yet fixed this package and the path to this current source code, but if this package is this
    here, I just wanted to point out that it was automatically created when a "New Project with JavaFX as Generator"
    is initialized. For the path itself (T009- GUI_DVD_Collection > src > main > java > com > example > tutorial9), I tried many
    a times to relocate it (only put it under the "src" file), but it could not be done, as it would only become a
    java-text-file (can't be a "Java Class").

 */
package com.example.tutorial9;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;


public class DVDButtonPane extends Pane {


    // Attributes
    private Button b1 = new Button("Add");
    private Button b2 = new Button("Deleted");


    // Getters
    public Button getB1() {
        return b1;
    }
    public Button getB2() {
        return b2;
    }


    public DVDButtonPane() {
        //Create an inner pane and set its style
        //This will hold all our components
        Pane aPane = new Pane();    // instantializing a pane
        aPane.setStyle("-fx-background-color: white; " + "-fx-padding: 4 4;"); // setting the color of the pane


        // Create the buttons
        /*
        Steps:
        1 - Set the text on the button
        2 - Align the text
        3 - Set the style of the text and for the button itself
        4 - Set its top-left corner location
        5 - Set the size of the button
        6 - Add it on the pane
         */

        b1.setText("Add");
        b1.setAlignment(Pos.CENTER);
        b1.setStyle("-fx-font: 12 arial; -fx-base: rgb(0,100,0); " + "-fx-text-fill: rgb(255,255,255);");
        b1.relocate(0,0);
        b1.setPrefSize(90, 30);
        aPane.getChildren().add(b1);

        b2.setText("Delete");
        b2.setAlignment(Pos.CENTER);
        b2.setStyle("-fx-font: 12 arial; -fx-base: rgb(100,0,0); " + "-fx-text-fill: rgb(255,255,255);");
        b2.relocate(100, 0);
        b2.setPrefSize(90, 30);
        aPane.getChildren().add(b2);

        Button b3 = new Button("Stats");
        b3.setText("Stats");
        b3.setAlignment(Pos.CENTER);
        b3.setStyle("-fx-font: 12 arial; -fx-base: rgb(222, 222, 222); " + "-fx-text-fill: rgb(0,0,0);");
        b3.relocate(210, 0);
        b3.setPrefSize(90, 30);
        aPane.getChildren().add(b3);

        getChildren().add(aPane);

    }
}
