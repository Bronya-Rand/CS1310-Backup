package com.example;

import java.math.BigDecimal;
import java.text.NumberFormat;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

public class CollegeLoanCalculator {

    private static final NumberFormat currency = NumberFormat
            .getCurrencyInstance();

    @FXML
    private TextField amountTextField;

    @FXML
    private Button calculateButton;

    @FXML
    private TextField fifteenYearTextField;

    @FXML
    private TextField fiveYearTotal;

    @FXML
    private TextField interestTextField;

    @FXML
    private TextField tenYearTextField;

    @FXML
    private TextField thirtyTextField;

    @FXML
    private Label tipPercentageLabel;

    @FXML
    private TextField twentyFiveTextField;

    @FXML
    private TextField twentyYearTextField;

    @FXML
    void calculateButtonPress(ActionEvent event) {
        BigDecimal amount = new BigDecimal(amountTextField.getText());
        BigDecimal interest = new BigDecimal(interestTextField.getText());
        BigDecimal totalWithInterest = amount.multiply(interest);
        
        BigDecimal five = totalWithInterest.divide(new BigDecimal(60.0));
        BigDecimal ten = totalWithInterest.divide(new BigDecimal(120.0));
        BigDecimal fifteen = totalWithInterest.divide(new BigDecimal(180.0));
        BigDecimal twenty = totalWithInterest.divide(new BigDecimal(240.0));
        BigDecimal twentyFive = totalWithInterest.divide(new BigDecimal(300.0));
        BigDecimal thirty = totalWithInterest.divide(new BigDecimal(360.0));

        fiveYearTotal.setText(currency.format(five));
        tenYearTextField.setText(currency.format(ten));
        fifteenYearTextField.setText(currency.format(fifteen));
        twentyYearTextField.setText(currency.format(twenty));
        twentyFiveTextField.setText(currency.format(twentyFive));
        thirtyTextField.setText(currency.format(thirty));
    }

}
