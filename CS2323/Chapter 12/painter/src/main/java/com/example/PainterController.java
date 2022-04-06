package com.example;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;

public class PainterController {

    // enum for presenting pen sizes
    private enum PenSize {
        SMALL(2), MEDIUM(4), LARGE(6);

        private final int radius;

        PenSize(int radius) {
            this.radius = radius;
        }

        public int getRadius() {
            return radius;
        }
    }

    /// instance variables associated with GUI controls
    @FXML
    private RadioButton blackRadioButton;

    @FXML
    private RadioButton redRadioButton;

    @FXML
    private RadioButton greenRadioButton;

    @FXML
    private RadioButton blueRadioButton;

    @FXML
    private RadioButton smallRadioButton;

    @FXML
    private RadioButton mediumRadioButton;

    @FXML
    private RadioButton largeRadioButton;

    @FXML
    private Pane drawingPane;

    @FXML
    private ToggleGroup colorToggleGroup;

    @FXML
    private ToggleGroup sizeToggleGroup;

    private PenSize radius = PenSize.MEDIUM;
    private Paint brushColor = Color.BLACK;

    // Any controller has an initialize method
    // As soon as the main method calls the controller, this initialize
    // method will be called
    public void initialize() {
        blackRadioButton.setUserData(Color.BLACK);
        redRadioButton.setUserData(Color.RED);
        greenRadioButton.setUserData(Color.GREEN);
        blueRadioButton.setUserData(Color.BLUE);

        smallRadioButton.setUserData(PenSize.SMALL);
        mediumRadioButton.setUserData(PenSize.MEDIUM);
        largeRadioButton.setUserData(PenSize.LARGE);
    }

    @FXML
    void clearButtonPressed(ActionEvent event) {
        drawingPane.getChildren().clear();
    }

    @FXML
    void colorRadioButtonSelected(ActionEvent event) {
        brushColor = (Paint) colorToggleGroup.getSelectedToggle().getUserData();
    }

    @FXML
    void drawingAreaMouseDragged(MouseEvent event) {
        Circle newCircle = new Circle(event.getX(), event.getY(),
                radius.getRadius(), brushColor);
        drawingPane.getChildren().add(newCircle);
    }

    @FXML
    void sizeRadioButtonSelected(ActionEvent event) {
        radius = (PenSize) sizeToggleGroup.getSelectedToggle().getUserData();
    }

    @FXML
    void undoButtonPressed(ActionEvent event) {
        int count = drawingPane.getChildren().size();

        if (count > 0) {
            drawingPane.getChildren().remove(count - 1);
        }
    }

}
