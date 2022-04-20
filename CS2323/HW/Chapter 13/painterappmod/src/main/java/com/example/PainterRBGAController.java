package com.example;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
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

    @FXML
    private Slider alphaSlider;

    @FXML
    private Slider blueSlider;

    @FXML
    private Pane drawingPane;

    @FXML
    private Slider greenSlider;

    @FXML
    private RadioButton largeRadioButton;

    @FXML
    private RadioButton mediumRadioButton;

    @FXML
    private Slider redSlider;

    @FXML
    private ToggleGroup sizeToggleGroup;

    @FXML
    private RadioButton smallRadioButton;

    @FXML
    private ToggleGroup colorToggleGroup;

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
        // listeners for sliders
        redSlider.valueProperty().addListener(new ChangeListener<Number>() {

            @Override
            public void changed(
                    ObservableValue<? extends Number> observableValue,
                    Number oldValue, Number newValue) {
                red = newValue.intValue();
                brushColor = Color.rgb(red, green, blue, alpha);
            }

        });

        greenSlider.valueProperty().addListener(new ChangeListener<Number>() {

            @Override
            public void changed(
                    ObservableValue<? extends Number> observableValue,
                    Number oldValue, Number newValue) {
                green = newValue.intValue();
                brushColor = Color.rgb(red, green, blue, alpha);
            }

        });

        blueSlider.valueProperty().addListener(new ChangeListener<Number>() {

            @Override
            public void changed(
                    ObservableValue<? extends Number> observableValue,
                    Number oldValue, Number newValue) {
                blue = newValue.intValue();
                brushColor = Color.rgb(red, green, blue, alpha);
            }

        });

        alphaSlider.valueProperty().addListener(new ChangeListener<Number>() {

            @Override
            public void changed(
                    ObservableValue<? extends Number> observableValue,
                    Number oldValue, Number newValue) {
                alpha = newValue.doubleValue();
                brushColor = Color.rgb(red, green, blue, alpha);
            }
        });
    }
}
