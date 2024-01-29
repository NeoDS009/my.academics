
// import the package
package assignment4;

// all imports to allow the needed methods
import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.event.*;
import javafx.scene.input.MouseEvent;
import java.util.List;
import java.util.ArrayList;

// Our controller: the ElectronicStoreApp: works with the model and updates the view
/*
Description:
--> initializes a model: an ElectronicStore
--> Our start() method: once the app starts running (will now start setting up our view and updating it correspondingly whence called)
    --> has many event-handlers for:
      -- two (2) lists (Store's stock list + Current Cart list)
        --> will keep up to date once the update() method is called, and show the updated version of the view to the user
      -- four (4) buttons (the reset + the add + the remove + the complete sale buttons
        --> will become available when their corresponding ListView has a selected item
        --> each have their own event handlers to handle their corresponding actions
            --> they will all be mutating a list/array, and calling the update() method to update the view for the user
      -- three (3) text-fields (the #sales + revenue + $/sale text-fields)
        --> the controller will update them once the < CompleteSale > button is called
 */
public class ElectronicStoreApp extends Application {

    // The model
    ElectronicStore model;
    public ElectronicStoreApp() {model = ElectronicStore.createStore();}


    public void start(Stage primaryStage) {
        Pane aPane = new Pane();

        // initializing and setting up the view
        ElectronicStoreView view = new ElectronicStoreView();
        aPane.getChildren().add(view);
        view.update(model);

        // Update the ListViews with their corresponding data (first things first)
        List<String> popItems = new ArrayList<>();

        for (Product p: model.mostPopularItems()) {
            popItems.add(p.toString());
        }

        view.getPopList().setItems(FXCollections.observableArrayList(popItems));


        // if user presses on an item within the storeStock list
        view.getStoreStockList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {

                // then, we enable the add button
                if (view.getStoreStockList().getSelectionModel().getSelectedIndex() >= 0) {
                    view.getAddToCartButton().setDisable(false);
                }
            }
        });

        // if the add button is pressed
        view.getAddToCartButton().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {

                // if something from the stock list is selected
                if (view.getStoreStockList().getSelectionModel().getSelectedIndex() >= 0) {
                    int iSelected = view.getStoreStockList().getSelectionModel().getSelectedIndex();

                    // if the stockList's product still has stock, then we decrease the stock quantity by 1
                    if (model.getStock()[iSelected].getStockQuantity() > 0) {
                        model.getStock()[iSelected].setStockQuantity(model.getStock()[iSelected].getStockQuantity() - 1);
                        model.getStock()[iSelected].setSoldQuantity(model.getStock()[iSelected].getSoldQuantity() + 1);
                        view.update(model);
                    }

                    // add to the current cart what is selected
                    model.getCurrentCartProducts().add(model.getStock()[iSelected].getSoldQuantity() + " x " + model.getStock()[iSelected].toString());
                    // deleting the previous item added that is the same
                    if (model.getCurrentCartProducts().contains(model.getStock()[iSelected].getSoldQuantity() - 1 + " x " + model.getStock()[iSelected].toString())) {
                        model.getCurrentCartProducts().remove(model.getStock()[iSelected].getSoldQuantity() - 1 + " x " + model.getStock()[iSelected].toString());
                    }

                    // if the stockList's product has 0 quantity left: then we delete that element from the stock
                    if (model.getStock()[iSelected].getStockQuantity() == 0) {

                        // creating an Array that has 1-less product than the stock
                        int stockLenght = model.getNonNullStock().length;

                        Product[] newStock = new Product[stockLenght - 1];

                        List<Product> temp = new ArrayList<>();

                        for (Product p: model.getNonNullStock()) {
                            temp.add(p);
                        }
                        temp.remove(model.getStock()[iSelected]);

                        for (int i = 0; i < temp.size(); i++) {
                            newStock[i] = temp.get(i);
                        }

                        // updating the stock and the view
                        model.getDeletedItems().add(model.getStock()[iSelected]);
                        model.setStock(newStock);

                        view.update(model);

                    }

                    view.getLabel3().setText("Current Cart ($" + model.gettingCurrentCartPrice() + ")");

                    // updating the model again: this makes the button true
                    view.update(model);
                }
            }
        });


        // updating the current cart (event handling on the
        view.getCurStockList().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {

                // if something is selected from the list
                if (view.getCurStockList().getSelectionModel().getSelectedIndex() >= 0) {

                    view.getRemoveFromCartButton().setDisable(false);
                    view.getStoreStockList().getSelectionModel().clearSelection();
                    view.update(model);

                    // if something is selected and the Remove Button is pressed
                    view.getRemoveFromCartButton().setOnMousePressed(new EventHandler<MouseEvent>() {
                        public void handle(MouseEvent mouseEvent) {

                            // initializing some easy-access variables
                            int itemSelected = 0;

                            itemSelected = view.getCurStockList().getSelectionModel().getSelectedIndex();

                            String theOne = view.getCurStockList().getItems().get(itemSelected);

                            Product theProduct = model.getTheProduct(theOne);


                            // updating the product's sold quantity and stock quantity
                            model.getTheProduct(model.getCurrentCartProducts().get(itemSelected)).setSoldQuantity(model.getTheProduct(model.getCurrentCartProducts().get(itemSelected)).getSoldQuantity() - 1);
                            model.getTheProduct(model.getCurrentCartProducts().get(itemSelected)).setStockQuantity(model.getTheProduct(model.getCurrentCartProducts().get(itemSelected)).getStockQuantity() + 1);

                            // getting the product's states inside variables
                            String theSelectedString = model.getCurrentCartProducts().get(itemSelected);

                            Product theSelectedProduct = model.getTheProduct(theSelectedString);

                            int updatedSoldQ = model.getTheProduct( model.getCurrentCartProducts().get(itemSelected)).getSoldQuantity();

                            // add to the current cart what is selected
                            model.getCurrentCartProducts().add((updatedSoldQ + " x " + theSelectedProduct.toString()));

                            // deleting the previous item added that is the same
                            if (model.getCurrentCartProducts().contains((updatedSoldQ+1) + " x " + theSelectedProduct)) {
                                model.getCurrentCartProducts().remove((updatedSoldQ+1) + " x " + theSelectedProduct);
                            }

                            // delete the last stuff
                            if (updatedSoldQ == 0) {
                                model.getCurrentCartProducts().remove((updatedSoldQ) + " x " + theSelectedProduct);
                            }

                            // if we wish to delete an item, and the item is not found in the store's stock: i.e. the item WAS previously sold out
                            // add it back to the stock
                            if (!(view.getStoreStockList().getItems().contains(theSelectedProduct.toString()))) {

                                // with a for loop, create a new stock and fill it up, then set the formal stock to this new stock
                                int counter = 0;    // need to know where to insert the old item (at the end of the array)
                                Product[] newStock = new Product[model.getStock().length+1];        // need to create a new array of size +1
                                for (int i = 0; i < model.getNonNullStock().length; i++) {
                                    newStock[i] = model.getNonNullStock()[i];
                                    counter++;
                                }
                                newStock[counter] = theSelectedProduct;
                                model.setStock(newStock);
                                view.update(model);
                            }

                            // updating the cart price
                            view.getLabel3().setText("Current Cart ($" + model.gettingCurrentCartPrice() + ")");

                            view.update(model);
                        }
                    });
                }
            }
        });


        // letting the complete sale button enabled
        if (model.getCurrentCartProducts().size() > 0) {
            view.getCompleteSaleButton().setDisable(false);
        }

        // Event handling for the CompleteSaleButton
        view.getCompleteSaleButton().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {

                // updating the text-fields
                view.getRevenueTField().setText(model.gettingCurrentCartPrice());
                view.get$SaleTfield().setText(model.getTheAverageRevenuePerSale());
                view.getLabel3().setText("Current Cart ($0.00):");
                view.update(model);


                // re-updating the most popular list again and again after the complete sale button is pressed
                List<String> popItems = new ArrayList<>();

                for (Product p: model.mostPopularItems()) {
                    popItems.add(p.toString());
                }

                view.getPopList().setItems(FXCollections.observableArrayList(popItems));


                // updating the current cart
                List<String> newCart = new ArrayList<>();

                for (String s: model.getCurrentCartProducts()) {
                    newCart.add(s);
                }

                for (String ss: newCart) {
                    model.getCurrentCartProducts().remove(ss);

                }

                //update the # of sales
                int sales = model.getNumSales();

                model.setNumSales(sales+1);
                view.getNumSalesTField().setText(Integer.toString(sales));
                view.update(model);

                // disable the add to cart button
                view.getStoreStockList().getSelectionModel().clearSelection();
                view.update(model);

            }
        });

        // if the reset button is clicked
        view.getResetStoreButton().setOnMousePressed(new EventHandler<MouseEvent>() {
            public void handle(MouseEvent mouseEvent) {

                // create a new E-store app and start the App again
                ElectronicStoreApp newApp = new ElectronicStoreApp();
                newApp.start(primaryStage);

            }
        });

        // setting up the application
        primaryStage.setTitle("Electronic Store Application " + " - " + model.getName());
        primaryStage.setResizable(false);
        primaryStage.setScene(new Scene(aPane));
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
