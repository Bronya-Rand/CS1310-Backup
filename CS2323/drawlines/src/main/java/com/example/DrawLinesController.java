package com.example;

import java.security.SecureRandom;
import java.util.ArrayList;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.paint.Color;

public class DrawLinesController {

    private final SecureRandom random = new SecureRandom();

    @FXML
    private Canvas canvas;

    // @FXML
    // void drawLinesButtonPressed(ActionEvent event) {
    // // get the graphics context, which is used to draw on canvas
    // GraphicsContext gc = canvas.getGraphicsContext2D();
    // // creating the first line starting at (0,0)
    // gc.strokeLine(0, 0, canvas.getWidth(), canvas.getHeight());

    // gc.strokeLine(canvas.getWidth(), 0, 0, canvas.getHeight());
    // }

    @FXML
    void drawLinesButtonPressed(ActionEvent event) {
        // get the graphics context, which is used to draw on canvas
        GraphicsContext gc = canvas.getGraphicsContext2D();
        ArrayList<MyLines> list = new ArrayList<>();

        int canvasHeight = (int) canvas.getHeight();
        int canvasWidth = (int) canvas.getWidth();

        for (int i = 0; i < 10; i++) {
            double x1 = random.nextInt(canvasWidth);
            double y1 = random.nextInt(canvasHeight);
            double x2 = random.nextInt(canvasWidth);
            double y2 = random.nextInt(canvasHeight);

            Color color = Color.rgb(random.nextInt(256), random.nextInt(256),
                    random.nextInt(256));
            list.add(new MyLines(x1, y1, x2, y2, color));
        }

        for (MyLines line : list) {
            line.draw(gc);
        }
    }
}