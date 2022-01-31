/*
Azariel Del Carmen
Java Programming Language
Date: Jan 31
This class defines the attributes and functionalities of
auto policy 
*/

public class AutoPolicy {
    
    private int accountNumber;
    private String makeAndModel;
    private String state;

    AutoPolicy(int accNum, String makeModel, String st) {
        accountNumber = accNum;
        makeAndModel = makeModel;
        state = st;
    }

    public int getAccountNumber() {
        return accountNumber;
    }

    public String getMakeModel() {
        return makeAndModel;
    }

    public String getState() {
        return state;
    }

    public void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    public void setMakeModel(String makeModel) {
        makeAndModel = makeModel;
    }

    public void setState(String st) {
        state = st;
    }

    public boolean isNoFaultState() {
        if (state == "MA" || state == "PA" || state == "NJ" || state == "NY") {
            return true;
        }
        return false;
    }

}
