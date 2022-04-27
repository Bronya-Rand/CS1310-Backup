package com.example;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;

public class DrawShapesController {

    @FXML
    private Canvas canvas;

    @FXML
    void strokeOvalButtonPressed(ActionEvent event) {
        draw("oval");
    }

    @FXML
    void strokeRectangleButtonPressed(ActionEvent event) {
        draw("rectangle");
    }

    private void draw(String shape) {
        GraphicsContext gc = canvas.getGraphicsContext2D();

        // call a method to clear or clean the canvas
        gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

        switch (shape) {
        case "rectangle":
            for (int i = 1; i <= 10; i++) {
                gc.strokeRect(10 * i, 10 * i, 100 + 10 * i, 100 + 10 * i);
            }
            break;
        case "oval":
            for (int i = 1; i <= 10; i++) {
                gc.strokeOval(10 * i, 10 * i, 100 + 10 * i, 100 + 10 * i);
            }
            break;
        default:
            break;
        }
    }

}
