package com.example;

public class Magazine extends Content {

    public Magazine(String title, String author, String publisher, int year) {
        super(title, author, publisher, year);
    }

    @Override
    public String toString() {
        return String.format("Magazine: %s", super.getTitle());
    }

}
