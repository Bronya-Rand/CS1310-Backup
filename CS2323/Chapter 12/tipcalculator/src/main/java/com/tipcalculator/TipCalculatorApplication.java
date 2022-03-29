package com.tipcalculator;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class TipCalculatorApplication extends Application {

    // Create the GUI and attach it to the scene
    @Override
    public void start(Stage arg0) throws Exception {
        // Get the root of the scene which was our GridPane

        Parent root = FXMLLoader.load(getClass().getResource("TipCalculator.fxml"));
        Scene scene = new Scene(root);
        arg0.setScene(scene);
        arg0.setTitle("Tip Calculator");
        arg0.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
