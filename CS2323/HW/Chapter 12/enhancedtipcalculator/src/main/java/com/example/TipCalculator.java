package com.example;

import java.math.BigDecimal;
import java.math.RoundingMode;
import java.text.NumberFormat;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;

public class TipCalculator {

    private static final NumberFormat currency = NumberFormat
            .getCurrencyInstance();

    @FXML
    private Button calculateButton;

    @FXML
    private TextField partyAmountTextField;

    @FXML
    private TextField partyPeopleTextField;

    @FXML
    private TextField partySplitTotalTextField;

    @FXML
    void calculateButtonPress(ActionEvent event) {
        BigDecimal amount = new BigDecimal(partyAmountTextField.getText());
        BigDecimal people = new BigDecimal(partyPeopleTextField.getText());
        // used from Java Docs
        BigDecimal splitTotal = amount.divide(people, 2, RoundingMode.HALF_UP);

        partySplitTotalTextField.setText(currency.format(splitTotal));
    }
}
