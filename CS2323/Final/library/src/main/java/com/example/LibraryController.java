package com.example;

import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;

public class LibraryController {

    @FXML
    private TextField publisherTextField;

    @FXML
    private TextField authorTextField;

    @FXML
    private ListView<Content> contentListView;

    @FXML
    private TextField titleTextField;

    @FXML
    private TextField yearTextField;

    @FXML
    private ToggleGroup contentToggleGroup;

    @FXML
    private RadioButton magazineRadioButton;

    @FXML
    private RadioButton bookRadioButton;

    private final ObservableList<Content> contents = FXCollections
            .observableArrayList();

    private String contentType = "book";
    private final ContentFactory contentClass = new ContentFactory();

    @FXML
    void newContentButtonClicked(ActionEvent event) {
        bookRadioButton.setSelected(false);
        magazineRadioButton.setSelected(false);
        // FILL HERE
        // CLEAR ALL THE TEXTBOXES
        titleTextField.clear();
        authorTextField.clear();
        publisherTextField.clear();
        yearTextField.clear();
    }

    @FXML
    void addContentButtonClicked(ActionEvent event) {
        // FILL HERE
        // get the userdata for the toggleGroup and assign it to contentType
        // Create an object (i.e., instance) of class Content using the factory
        // class
        // Add the object to the instance variable contents
        // bind the contentListView to the contents
        contentType = (String) contentToggleGroup.getSelectedToggle()
                .getUserData();

        switch (contentType) {
        case "book":
            contents.add(contentClass.getContent(contentType,
                    titleTextField.getText(), authorTextField.getText(),
                    publisherTextField.getText(),
                    Integer.valueOf(yearTextField.getText())));
            break;
        case "magazine":
            contents.add(contentClass.getContent(contentType,
                    titleTextField.getText(), authorTextField.getText(),
                    publisherTextField.getText(),
                    Integer.valueOf(yearTextField.getText())));
            break;
        default:
            throw new IllegalArgumentException(
                    contentType + " is not a valid content type");
        }
        contentListView.setItems(contents);
    }

    public void initialize() {

        // setting user data on radioButton controls
        bookRadioButton.setUserData("book");
        magazineRadioButton.setUserData("magazine");

        // FILL HERE
        // Add a new content to the listview
        contents.add(contentClass.getContent("book", "Java How to Program",
                "Deitel", "Deitel", 2017));

        contentListView.setItems(contents);

        // When listView selection changes, show the content information in the
        // gridpane
        contentListView.getSelectionModel().selectedItemProperty()
                .addListener(new ChangeListener<Content>() {
                    @Override
                    public void changed(
                            ObservableValue<? extends Content> observableValue,
                            Content oldContent, Content newContent) {
                        if (newContent.getClass().getName().contains("Book")) {
                            bookRadioButton.setSelected(true);
                            magazineRadioButton.setSelected(false);
                        } else {
                            // FILL HERE
                            bookRadioButton.setSelected(false);
                            magazineRadioButton.setSelected(true);
                        }
                        // FILL HERE
                        // Set the TextFields' text to the Content's information
                        titleTextField.setText(newContent.getTitle());
                        authorTextField.setText(newContent.getAuthor());
                        publisherTextField.setText(newContent.getPublisher());
                        yearTextField.setText(
                                Integer.toString(newContent.getYear()));
                    }
                });

    }

}
