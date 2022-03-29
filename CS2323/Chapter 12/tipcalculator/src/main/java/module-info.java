module com.tipcalculator {
    requires javafx.controls;
    requires javafx.fxml;

    opens com.tipcalculator to javafx.fxml;
    exports com.tipcalculator;
}
