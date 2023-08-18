
// import the package
package assignment4;

// import needed imports for the additional methods
import javafx.collections.FXCollections;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import java.util.*;

// our view: ElectronicStoreView --> works with the controller (updates correspondingly)
/*
Description:
--> private attributes: many of them, describing and setting up the ElectronicStoreView
--> getters: for the private attributes: help with encapsulation
--> update() method: regarding the current the state of the controller, adapt and update correspondingly once this method is called
--> constructor() method: places all the private attribute/components onto the view, to be shown by the controller
 */
public class ElectronicStoreView extends Pane implements StoreViewUpdate{

    // attributes
    private ListView<String> PopList, StoreStockList, CurStockList;
    private TextField NumSalesTField, RevenueTField, $SaleTfield;
    private Label label1, label2, label3, label4, label5, label6, label7;
    private Button ResetStoreButton, AddToCartButton, RemoveFromCartButton, CompleteSaleButton;


    // getters
    public ListView<String> getPopList() {return PopList;}
    public ListView<String> getStoreStockList() {return StoreStockList;}
    public ListView<String> getCurStockList() {return CurStockList;}
    public TextField getNumSalesTField() {return NumSalesTField;}
    public TextField getRevenueTField() {return RevenueTField;}
    public TextField get$SaleTfield() {return $SaleTfield;}
    public Button getResetStoreButton() {return ResetStoreButton;}
    public Button getAddToCartButton() {return AddToCartButton;}
    public Button getRemoveFromCartButton() {return RemoveFromCartButton;}
    public Button getCompleteSaleButton() {return CompleteSaleButton;}
    public Label getLabel3() {return label3;}

    // the update() method: updates the interface shown to the user
    public void update(ElectronicStore model) {

        // get a copy of the list of the current store's stock
        Product[] listOfStock = model.getNonNullStock();

        // instantiate and initialize new ArrayLists to contain the ListViews
        List<String> MostPopularItems, StoreStock, CurrentCart;
        MostPopularItems = new ArrayList<>();
        StoreStock = new ArrayList<>();
        CurrentCart = new ArrayList<>();

        // got the store stock arrayList!
        for (int i = 0; i < listOfStock.length; i++) {
            StoreStock.add(listOfStock[i].toString());
        }

        for (int i = 0; i < 3; i++) {
            MostPopularItems.add(model.getStock()[i].toString());
        }

        // get the current Cart stuff
        if (model.getCurrentCartProducts().size() > 0) {
            for (int i = 0; i < model.getCurrentCartProducts().size(); i++) {
                CurrentCart.add(model.getCurrentCartProducts().get(i));
            }
        }

        // Update the ListViews with their corresponding data
        StoreStockList.setItems(FXCollections.observableArrayList(StoreStock));
        CurStockList.setItems(FXCollections.observableArrayList(CurrentCart));


        // updating the buttons (initially)
        AddToCartButton.setDisable(true);
        if (StoreStockList.getSelectionModel().getSelectedIndex() >= 0) {
            AddToCartButton.setDisable(false);
        }

        RemoveFromCartButton.setDisable(true);
        if (CurStockList.getSelectionModel().getSelectedIndex() >= 0) {
            RemoveFromCartButton.setDisable(false);

        }

        CompleteSaleButton.setDisable(true);
        if (model.getCurrentCartProducts().size() > 0) {
            CompleteSaleButton.setDisable(false);
        }
    }

    // Creating the components in the Pane
    public ElectronicStoreView() {

        // Initialize the Labels and place them
        label1 = new Label("Store Summary:");
        label1.relocate(10, 5);
        label1.setPrefSize(220, 40);
        label1.setAlignment(Pos.CENTER);
        label1.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label2 = new Label("Store Stock:");
        label2.relocate(240, 5);
        label2.setPrefSize(350, 40);
        label2.setAlignment(Pos.CENTER);
        label2.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label3 = new Label("Current Cart ($0.00):");
        label3.relocate(615, 5);
        label3.setPrefSize(360, 40);
        label3.setAlignment(Pos.CENTER);
        label3.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label4 = new Label("# Sales:");
        label4.relocate(10, 50);
        label4.setPrefSize(95, 35);
        label4.setAlignment(Pos.CENTER_RIGHT);
        label4.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label5 = new Label("Revenue:");
        label5.relocate(10, 90);
        label5.setPrefSize(95, 35);
        label5.setAlignment(Pos.CENTER_RIGHT);
        label5.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label6 = new Label("$ / Sale:");
        label6.relocate(10, 130);
        label6.setPrefSize(95, 35);
        label6.setAlignment(Pos.CENTER_RIGHT);
        label6.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        label7 = new Label("Most Popular Items");
        label7.relocate(10, 170);
        label7.setPrefSize(220, 35);
        label7.setAlignment(Pos.CENTER);
        label7.setStyle("-fx-font: 14 arial; -fx-text-fill: rgb(0, 0, 0);");

        // Create the text-fields
        NumSalesTField = new TextField();
        NumSalesTField.relocate(110, 50);
        NumSalesTField.setPrefSize(120, 35);

        RevenueTField = new TextField();
        RevenueTField.relocate(110, 90);
        RevenueTField.setPrefSize(120, 35);

        $SaleTfield = new TextField();
        $SaleTfield.relocate(110, 130);
        $SaleTfield.setPrefSize(120, 35);

        // updating the text-fields
        NumSalesTField.setText("0");
        RevenueTField.setText("0.00");
        $SaleTfield.setText("N/A");

        // Create the lists
        PopList = new ListView<>();
        PopList.relocate(10, 210);
        PopList.setPrefSize(220, 205);

        StoreStockList = new ListView<>();
        StoreStockList.relocate(240, 50);
        StoreStockList.setPrefSize(360, 365);

        CurStockList = new ListView<>();
        CurStockList.relocate(615, 50);
        CurStockList.setPrefSize(360, 365);


        // Create the buttons
        ResetStoreButton = new Button("Reset Store");
        ResetStoreButton.setStyle("-fx-font: 14 arial; -fx-base: rgb(235, 235, 235); -fx-text-fill: rgb(0, 0, 0);");
        ResetStoreButton.relocate(30, 420);
        ResetStoreButton.setPrefSize(180, 60);

        AddToCartButton = new Button("Add to Cart");
        AddToCartButton.setStyle("-fx-font: 14 arial; -fx-base: rgb(235, 235, 235); -fx-text-fill: rgb(0, 0, 0);");
        AddToCartButton.relocate(330, 420);
        AddToCartButton.setPrefSize(180, 60);

        RemoveFromCartButton = new Button("Remove from Cart");
        RemoveFromCartButton.setStyle("-fx-font: 14 arial; -fx-base: rgb(235, 235, 235); -fx-text-fill: rgb(0, 0, 0);");
        RemoveFromCartButton.relocate(615, 420);
        RemoveFromCartButton.setPrefSize(180, 60);

        CompleteSaleButton = new Button("Complete Sale");
        CompleteSaleButton.setStyle("-fx-font: 14 arial; -fx-base: rgb(235, 235, 235); -fx-text-fill: rgb(0, 0, 0);");
        CompleteSaleButton.relocate(795, 420);
        CompleteSaleButton.setPrefSize(180, 60);


        getChildren().addAll(PopList, StoreStockList, CurStockList, NumSalesTField, RevenueTField, $SaleTfield, label1, label2, label3, label4, label5, label6, label7, ResetStoreButton, AddToCartButton, RemoveFromCartButton, CompleteSaleButton);

        setPrefSize(1000, 500);
    }
}
