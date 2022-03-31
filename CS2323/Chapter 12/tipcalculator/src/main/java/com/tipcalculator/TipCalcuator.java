package com.tipcalculator;

import java.math.BigDecimal;
import java.text.NumberFormat;
import java.util.Currency;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;

public class TipCalcuator {

    private static final NumberFormat currency = NumberFormat
            .getCurrencyInstance();
    private static final NumberFormat percent = NumberFormat
            .getPercentInstance();
    private BigDecimal tipPercentage = new BigDecimal(0.15);

    @FXML
    private TextField amountTextField;

    @FXML
    private Button calculateButton;

    @FXML
    private Label tipPercentageLabel;

    @FXML
    private Slider tipPercentageSlider;

    @FXML
    private TextField tipTextField;

    @FXML
    private TextField totalTextField;

    @FXML
    void calculateButtonPress(ActionEvent event) {

        BigDecimal amount = new BigDecimal(amountTextField.getText());
        BigDecimal tip = amount.multiply(tipPercentage);
        BigDecimal total = amount.add(tip);

        tipTextField.setText(currency.format(tip));
        totalTextField.setText(currency.format(total));
    }

    public void initialize() {
        tipPercentageSlider.valueProperty()
                .addListener(new ChangeListener<Number>() {
                    @Override
                    public void changed(
                            ObservableValue<? extends Number> observableValue,
                            Number oldValue, Number newValue) {
                        tipPercentage = BigDecimal
                                .valueOf(newValue.intValue() / 100.0);
                        tipPercentageLabel
                                .setText(percent.format(tipPercentage));
                    }
                });
    }
}
