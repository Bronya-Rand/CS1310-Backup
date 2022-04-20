package com.example;

import java.util.HashMap;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Slider;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;

public class PainterRBGAController {

    private int red = 0;
    private int green = 0;
    private int blue = 0;
    private double alpha = 1.0;

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

    private HashMap<Integer, Color> colors = new HashMap<Integer, Color>();

    @FXML
    private Pane drawingPane;

    @FXML
    private RadioButton largeRadioButton;

    @FXML
    private RadioButton mediumRadioButton;

    @FXML
    private ToggleGroup sizeToggleGroup;

    @FXML
    private RadioButton smallRadioButton;

    @FXML
    private RadioButton blackRadioButton;

    @FXML
    private RadioButton blueRadioButton;

    @FXML
    private ToggleGroup colorToggleGroup;

    @FXML
    private RadioButton cyanRadioButton;

    @FXML
    private RadioButton goldRadioButton;

    @FXML
    private RadioButton grayRadioButton;

    @FXML
    private RadioButton greenRadioButton;

    @FXML
    private RadioButton ivoryRadioButton;

    @FXML
    private RadioButton magentaRadioButton;

    @FXML
    private RadioButton orangeRadioButton;

    @FXML
    private RadioButton pinkRadioButton;

    @FXML
    private RadioButton purpleRadioButton;

    @FXML
    private RadioButton redRadioButton;

    @FXML
    private RadioButton yellowRadioButton;

    private PenSize radius = PenSize.MEDIUM;
    private Paint brushColor = Color.BLACK;

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

    public void initialize() {
        colors.put(1, Color.RED);
        colors.put(2, Color.ORANGE);
        colors.put(3, Color.YELLOW);
        colors.put(4, Color.GREEN);
        colors.put(5, Color.BLUE);
        colors.put(6, Color.PURPLE);
        colors.put(7, Color.BLACK);
        colors.put(8, Color.GRAY);
        colors.put(9, Color.MAGENTA);
        colors.put(10, Color.CYAN);
        colors.put(11, Color.PINK);
        colors.put(12, Color.IVORY);
        colors.put(13, Color.GOLD);

        redRadioButton.setUserData(colors.get(1));
        orangeRadioButton.setUserData(colors.get(2));
        yellowRadioButton.setUserData(colors.get(3));
        greenRadioButton.setUserData(colors.get(4));
        blueRadioButton.setUserData(colors.get(5));
        purpleRadioButton.setUserData(colors.get(6));
        blackRadioButton.setUserData(colors.get(7));
        grayRadioButton.setUserData(colors.get(8));
        magentaRadioButton.setUserData(colors.get(9));
        cyanRadioButton.setUserData(colors.get(10));
        pinkRadioButton.setUserData(colors.get(11));
        ivoryRadioButton.setUserData(colors.get(12));
        goldRadioButton.setUserData(colors.get(13));

        smallRadioButton.setUserData(PenSize.SMALL);
        mediumRadioButton.setUserData(PenSize.MEDIUM);
        largeRadioButton.setUserData(PenSize.LARGE);
    }
}
