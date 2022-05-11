package com.example;

public class ContentFactory {

    public Content getContent(String contentType, String title, String author,
            String publisher, int year) {
        switch (contentType) {
        case "book":
            return new Book(title, author, publisher, year);
        case "magazine":
            return new Magazine(title, author, publisher, year);
        default:
            throw new IllegalArgumentException(
                    contentType + " is not a valid content type");
        }
    }
}
