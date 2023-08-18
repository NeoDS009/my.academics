
/*
Comments on the package (com.example.tutorial9):
Sorry if I haven't yet fixed this package and the path to this current source code, but if this package is this
    here, I just wanted to point out that it was automatically created when a "New Project with JavaFX as Generator"
    is initialized. For the path itself (T009- GUI_DVD_Collection > src > main > java > com > example > tutorial9), I tried many
    a times to relocate it (only put it under the "src" file), but it could not be done, as it would only become a
    java-text-file (can't be a "Java Class").

 */
package com.example.tutorial9;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button;

public class DVDCollectionApp1  extends Application {
    public void start(Stage primaryStage) {

        // Create a pane
        Pane  aPane = new Pane();


        // Create the labels (Set text >> relocate its top-left corner coord. >> set the size >> add it to the pane)
        Label label1 = new Label("Title");
        label1.relocate(10, 10);
        label1.setPrefSize(200, 20);
        aPane.getChildren().add(label1);

        Label label2 = new Label("Year");
        label2.relocate(220, 10);
        label2.setPrefSize(60, 20);
        aPane.getChildren().add(label2);

        Label label3 = new Label("Length");
        label3.relocate(290, 10);
        label3.setPrefSize(60, 20);
        aPane.getChildren().add(label3);


        // Create the lists
        String[]    titles = {"Star Wars", "Java is cool", "Mary Poppins", "The Green Mile"};
        String[]    years = {"1978", "2002", "1968", "1999"};
        String[]    lengths = {"124", "93", "126", "148"};

        // Steps: (1. instantialize) >> (2. Fill the ListView with the Arrays) >> (3-4. Set the location and size) >> (5. Add it to the pane)
        ListView<String> titlesList = new ListView<>();
        titlesList.setItems(FXCollections.observableArrayList(titles));
        titlesList.relocate(10, 40);
        titlesList.setPrefSize(200, 150);
        aPane.getChildren().add(titlesList);

        ListView<String> yearsList = new ListView<>();
        yearsList.setItems(FXCollections.observableArrayList(years));
        yearsList.relocate(220, 40);
        yearsList.setPrefSize(60, 150);
        aPane.getChildren().add(yearsList);

        ListView<String> lengthsList = new ListView<>();
        lengthsList.setItems(FXCollections.observableArrayList(lengths));
        lengthsList.relocate(290, 40);
        lengthsList.setPrefSize(60, 150);
        aPane.getChildren().add(lengthsList);



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
        Button b1 = new Button("Add");
        b1.setText("Add");
        b1.setAlignment(Pos.CENTER);
        b1.setStyle("-fx-font: 12 arial; -fx-base: rgb(0,100,0); " + "-fx-text-fill: rgb(255,255,255);");
        b1.relocate(10,200);
        b1.setPrefSize(95, 30);

        Button b2 = new Button("Delete");
        b2.setText("Delete");
        b2.setAlignment(Pos.CENTER);
        b2.setStyle("-fx-font: 12 arial; -fx-base: rgb(100,0,0); " + "-fx-text-fill: rgb(255,255,255);");
        b2.relocate(115, 200);
        b2.setPrefSize(95, 30);

        Button b3 = new Button("Stats");
        b3.setText("Stats");
        b3.setAlignment(Pos.CENTER);
        b3.setStyle("-fx-font: 12 arial; -fx-base: rgb(222, 222, 222); " + "-fx-text-fill: rgb(0,0,0);");
        b3.relocate(290, 200);
        b3.setPrefSize(60, 30);

        // Initialize the ButtonsPane
        DVDButtonPane buttonsPane = new DVDButtonPane();
        buttonsPane.relocate(30, 200);                       // locate it's top-left corner
        aPane.getChildren().add(buttonsPane);                      // Add it to this pane


        // Creating a scene and showing it
        Scene myScene = new Scene(aPane, 360, 240);           // Create a scene that contains this Pane
        primaryStage.setTitle("My DVD Collections");                // set the title of the scene (window display)
        primaryStage.setResizable(false);                           // Non-resizable
        primaryStage.setScene(myScene);                             // set the scene for the stage
        primaryStage.show();                                        // show the stage
    }

    public static void main(String[] args) {
        launch(args);
    }
}
