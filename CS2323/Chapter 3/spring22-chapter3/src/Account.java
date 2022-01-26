/*
Java Programming Language
Written by Azariel Del Carmen
Date Jan 26
This program defines an account class
*/

public class Account {

    private String name; //instance variable
    private double amount;

    //default constructor
    public Account() {

    }

    public Account(String name) {
        this.name = name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public double getAmount() {
        return amount;
    }

    public static void printDummy() {
        System.out.println("Static method Dummy!");
    }

}
