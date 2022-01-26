import java.util.Scanner;

/*
Java Programming Language
Written by Azariel Del Carmen
Date Jan 26
This class will contain the main method instantiate an object of class Account
*/

public class AccountApp {

    public static void main(String[] args) {
        //instantiating object from class Account
        Account zlAccount = new Account();
        System.out.println(zlAccount.getName());
        System.out.println(zlAccount.getAmount());

        zlAccount.setName("Zhongli");
        zlAccount.setAmount(100.0);

        System.out.printf("Name: %s, Amount: %.2f%n", zlAccount.getName(), zlAccount.getAmount());

        Account yunAccount = new Account();

        Scanner input = new Scanner(System.in);

        System.out.println("Enter a value for account name:");
        //yunAccount.setName(input.nextLine());
        String name = input.next();
        yunAccount.setName(name);

        System.out.println(yunAccount.getName());
        
        //While it can be seen on some IDEs, calling static like this is not preferred
        yunAccount.printDummy(); 

        //This is preferred
        Account.printDummy(); 
        
    }   
    
}
