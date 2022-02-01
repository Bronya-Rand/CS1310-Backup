public class Account {
    private String name;
    private double balance;

    public Account(String name, double balance) {
        this.name = name;
        if (balance > 0.0) {
            this.balance = balance;
        }
    }

    public void deposit(double depositAmount) {
        if (depositAmount > 0.0) {
            balance = balance + depositAmount;
        }
    }

    public double getBalance() {
        return balance;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void withdraw(double withdrawAmount) {
        if (balance - withdrawAmount < 0.0) {
            System.out.println("Withdraw amount exceeded account balance.");
        }
        else {
            balance -= withdrawAmount;
        }
    }

    public static void displayAccount(Account acc) {
        System.out.printf("%s balance: $%.2f%n", acc.getName(), 
            acc.getBalance());
    }
}
