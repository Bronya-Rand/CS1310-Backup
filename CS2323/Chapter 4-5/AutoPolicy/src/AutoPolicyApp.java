/*
Azariel Del Carmen
Java Programming Language
Date: Jan 31
This class is the main class of AutoPolicy
*/

public class AutoPolicyApp {

    public static void main(String[] args) {
        AutoPolicy policy1 = new AutoPolicy(111, 
            "Toyota Tacoma", "MA");
        
        if (policy1.isNoFaultState()) {
            System.out.printf("Policy %d is in no fault state.%n", policy1.getAccountNumber());
        }
    }
}
