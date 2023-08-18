package assignment4;

import javafx.scene.control.Button;
import javafx.scene.layout.Pane;

public class StoreButtonPane extends Pane{

    // the buttons (private to help with encapsulation)
    private Button ResetStoreButton, AddToCartButton, RemoveFromCartButton, CompleteSaleButton;

    // getters (to help with encapsulation)
    public Button getResetStoreButton() {return ResetStoreButton;}
    public Button getAddToCartButton() {return AddToCartButton;}
    public Button getRemoveFromCartButton() {return RemoveFromCartButton;}
    public Button getCompleteSaleButton() {return CompleteSaleButton;}

    public StoreButtonPane() {
        Pane aButtonPane = new Pane();

        // Create the buttons
        ResetStoreButton = new Button("Reset Store");
        ResetStoreButton.setStyle("-fx-font: 12 arial; -fx-base: rgb(225, 225, 225); -fx-text-fill: rgb(255,255,255);");
        ResetStoreButton.relocate(30, 420);
        ResetStoreButton.setPrefSize(180, 60);

        AddToCartButton = new Button("Add to Cart");
        AddToCartButton.setStyle("-fx-font: 12 arial; -fx-base: rgb(225, 225, 225); -fx-text-fill: rgb(255,255,255);");
        AddToCartButton.relocate(330, 420);
        AddToCartButton.setPrefSize(180, 60);

        RemoveFromCartButton = new Button("Remove from Cart");
        RemoveFromCartButton.setStyle("-fx-font: 12 arial; -fx-base: rgb(225, 225, 225); -fx-text-fill: rgb(255,255,255);");
        RemoveFromCartButton.relocate(615, 420);
        RemoveFromCartButton.setPrefSize(180, 60);

        CompleteSaleButton = new Button("Complete Sale");
        CompleteSaleButton.setStyle("-fx-font: 12 arial; -fx-base: rgb(225, 225, 225); -fx-text-fill: rgb(255,255,255);");
        CompleteSaleButton.relocate(795, 420);
        CompleteSaleButton.setPrefSize(180, 60);

        // Add all four buttons to the pane for easier relocation
        aButtonPane.getChildren().addAll(ResetStoreButton, AddToCartButton, RemoveFromCartButton, CompleteSaleButton);

        getChildren().addAll(aButtonPane);
    }
}
