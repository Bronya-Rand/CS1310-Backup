package com.example;

public abstract class Content {
    private String title;
    private String author;
    private String publisher;
    private int year;

    public Content(String title, String author, String publisher, int year) {
        if (year < 2010 || year > 2022) {
            throw new IllegalArgumentException(
                    "Year must be after 2010 and existed till 2022.");
        }
        this.title = title;
        this.author = author;
        this.publisher = publisher;
        this.year = year;
    }

    public String getTitle() {
        return title;
    }

    public String getAuthor() {
        return author;
    }

    public String getPublisher() {
        return publisher;
    }

    public int getYear() {
        return year;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public void setYear(int year) {
        if (year < 2010 || year > 2022) {
            throw new IllegalArgumentException(
                    "Year must be after 2010 and existed till 2022.");
        }
        this.year = year;
    }

    public abstract String toString();
}
