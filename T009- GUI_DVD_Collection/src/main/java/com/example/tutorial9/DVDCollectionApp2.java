
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
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;

import java.util.ArrayList;

public class DVDCollectionApp2  extends Application {

    // Attributes
    private DVDCollection model;

    // Constructor
    public DVDCollectionApp2() {
        model = DVDCollection.example1();
    }

    // Starting the primary stage
    public void start(Stage primaryStage) {

        // Create a new Pane
        Pane  aPane = new Pane();


        // Create the labels and relocating the top-left corner
        Label label1 = new Label("DVDs");
        label1.relocate(10, 10);

        Label label2 = new Label("Title");
        label2.relocate(10, 202);

        Label label3 = new Label("Year");
        label3.relocate(10, 242);

        Label label4 = new Label("Length");
        label4.relocate(120, 242);


        // Create the TextFields and relocating their top-left corner and its size
        TextField tField = new TextField();
        tField.relocate(50, 200);
        tField.setPrefSize(500, 30);

        TextField yField = new TextField();
        yField.relocate(50, 240);
        yField.setPrefSize(55, 30);

        TextField lField = new TextField();
        lField.relocate(180, 240);
        lField.setPrefSize(45, 30);


        // Create the lists and  relocating their top-left corner and setting its size
        ListView<DVD>    tList = new ListView<DVD>();
        tList.relocate(10, 40);
        tList.setPrefSize(540, 150);
        DVD[] ts = model.getDVDList();
        tList.setItems(FXCollections.observableArrayList(ts));      // filling up the ListView object with an array of only non-null DVDs


        // Create the buttons with a button pane and relocating its top-left corner
        DVDButtonPane buttonPane = new DVDButtonPane();
        buttonPane.relocate(250, 240);


        // Event handler for the "ADD" button
        buttonPane.getB1().setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {

                // trying to "ADD"
                try {

                    // only if all textfields are non-empty
                    if (!tField.getText().isEmpty() && !yField.getText().isEmpty() && !lField.getText().isEmpty()) {

                        // creating a new array list that is one size bigger than the one displayed on the screen
                        int numDVD = tList.getItems().size();

                        int numberOfDVDs = numDVD + 1;

                        DVD[] newDVDList = new DVD[numberOfDVDs];

                        // Adding the DVD attributes (creating a new DVD) with the text-fields data
                        for (int i = 0; i < numberOfDVDs -1; i++) {
                            newDVDList[i] = tList.getItems().get(i);
                            newDVDList[numberOfDVDs -1] = new DVD(tField.getText(), Integer.parseInt(yField.getText()), Integer.parseInt(lField.getText()));
                        }

                        // updating the displayed ListView
                        tList.setItems(FXCollections.observableArrayList(newDVDList));

                    }

                    // However, if any of the text-fields are empty, prompt the user
                    if (tField.getText().isEmpty() || yField.getText().isEmpty() || lField.getText().isEmpty()) {
                        System.out.println("Oops! Please enter all DVD's attributes in order to ADD it (Title and Year and Length).");
                    }
                }

                // If any exceptions happen (mostly due to type conversion error or nullPointers, include a prompt to the user
                catch (Exception E) {
                    System.out.println("Oops! Please only enter numerics/integers for a DVD's Year and Length.");
                }
            }
        });


        // Event handling on the "Delete" Button
        buttonPane.getB2().setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent actionEvent) {

                // If one of the listView's DVD is selected
                if (tList.getSelectionModel().getSelectedItem() != null) {

                    // get the necessary data into variables for easier finding
                    DVD theSelected = tList.getSelectionModel().getSelectedItem();

                    int indexOfTheSelected = tList.getSelectionModel().getSelectedIndex();

                    // Creating a new ArrayList that will get all the items from the currently displayed ListView
                    ArrayList<DVD> currentDVDs = new ArrayList<>();

                    for (DVD d : tList.getItems()) {
                        currentDVDs.add(d);
                    }

                    // and... removing the element of the one selected by the user (with the help of its index)
                    currentDVDs.remove(indexOfTheSelected);

                    // updating the ListView
                    tList.setItems(FXCollections.observableArrayList(currentDVDs));

                    // updating the text-fields, such that when a DVD is deleted, clear out the text-fields (updating)
                    tField.setText(null);
                    yField.setText(null);
                    lField.setText(null);
                }
            }
        });

        // Event handling on the DVD list
        tList.setOnMousePressed(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {

                // if a DVD is selected
                if (tList.getSelectionModel().getSelectedItem() != null) {

                    // set the text-fields with the corresponding DVD's attributes (with the correct type)
                    tField.setText(tList.getSelectionModel().getSelectedItem().getTitle());
                    yField.setText(Integer.toString(tList.getSelectionModel().getSelectedItem().getYear()));
                    lField.setText(Integer.toString(tList.getSelectionModel().getSelectedItem().getDuration()));
                }

                // if a DVD is currently not selected
                if (tList.getSelectionModel().getSelectedItem() == (null)) {

                    // clear out the text-fields
                    tField.setText(null);
                    yField.setText(null);
                    lField.setText(null);
                }
            }
        });


        // Add all the components to the window
        aPane.getChildren().addAll(label1, label2, label3, label4, tField, yField, lField, tList, buttonPane);

        // Setting and showing the primary Stage
        primaryStage.setTitle("My DVD Collection");
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(aPane, 560,280));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
