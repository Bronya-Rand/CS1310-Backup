package com.example;

public class Book extends Content {

    public Book(String title, String author, String publisher, int year) {
        super(title, author, publisher, year);
    }

    @Override
    public String toString() {
        return String.format("Book: %s", super.getTitle());
    }

}
