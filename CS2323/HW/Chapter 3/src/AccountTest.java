import java.util.Scanner;

public class AccountTest {
    
    public static void main(String[] args) {
        Account account1 = new Account("Jane Green", 50.00);
        Account account2 = new Account("John Blue", -7.53);
        
        //display current balance ATM
        Account.displayAccount(account1);
        Account.displayAccount(account2);

        Scanner input = new Scanner(System.in);

        //prompt user for account1 deposit amount
        System.out.print("Enter deposit amount for account1: ");
        double depositAmount = input.nextDouble();  
        System.out.printf("%nadding %.2f to account1 balance%n%n", depositAmount);
        account1.deposit(depositAmount);

        //display balances
        Account.displayAccount(account1);
        Account.displayAccount(account2);
        
        //prompt user for account2 deposit amount
        System.out.print("Enter deposit amount for account2: "); 
        depositAmount = input.nextDouble();
        System.out.printf("%nadding %.2f to account2 balance%n%n", depositAmount);
        account2.deposit(depositAmount);

        //display balances
        Account.displayAccount(account1);
        Account.displayAccount(account2);

        //prompt user for account1 withdraw amount
        System.out.print("Enter withdraw amount for account1: ");
        double withdrawAmount = input.nextDouble();  
        System.out.printf("%nremoving %.2f to account1 balance%n%n", withdrawAmount);
        account1.withdraw(withdrawAmount);

        //display balances
        Account.displayAccount(account1);
        Account.displayAccount(account2);

        //prompt user for account2 withdraw amount
        System.out.print("Enter withdraw amount for account2: "); 
        withdrawAmount = input.nextDouble();
        System.out.printf("%nremoving %.2f to account2 balance%n%n", withdrawAmount);
        account2.withdraw(withdrawAmount);

        //display balances
        Account.displayAccount(account1);
        Account.displayAccount(account2);  
    }
}
