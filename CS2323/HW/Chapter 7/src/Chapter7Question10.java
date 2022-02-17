public class Chapter7Question10 {
    
    public static void main(String[] args) {
        Employee sm1 = new Employee(5000);
        Employee sm2 = new Employee(3405);
        
        calcutateTotal(sm1);
        calcutateTotal(sm2);

        printTable();
    }

    public static void calcutateTotal(Employee emp) {
        int total = (int)(200 + (emp.getCommissionTotal() * .09));

        if (total > 200 && total < 300) {
            Employee.counters[0]++;
        }
        else if (total >= 300 && total < 400) {
            Employee.counters[1]++;
        }
        else if (total >= 400 && total < 500) {
            Employee.counters[2]++;
        }
        else if (total >= 500 && total < 600) {
            Employee.counters[3]++;
        }
        else if (total >= 600 && total < 700) {
            Employee.counters[4]++;
        }
        else if (total >= 700 && total < 800) {
            Employee.counters[5]++;
        }
        else if (total >= 800 && total < 900) {
            Employee.counters[6]++;
        }
        else if (total >= 900 && total < 1000) {
            Employee.counters[7]++;
        }
        else if (total >= 1000) {
            Employee.counters[8]++;
        }
    }

    public static void printTable() {
        System.out.printf("$200-299: %d%n", Employee.counters[0]);
        System.out.printf("$300-399: %d%n", Employee.counters[1]);
        System.out.printf("$400-499: %d%n", Employee.counters[2]);
        System.out.printf("$500-599: %d%n", Employee.counters[3]);
        System.out.printf("$600-699: %d%n", Employee.counters[4]);
        System.out.printf("$700-799: %d%n", Employee.counters[5]);
        System.out.printf("$800-899: %d%n", Employee.counters[6]);
        System.out.printf("$900-999: %d%n", Employee.counters[7]);
        System.out.printf(">$1000: %d%n", Employee.counters[8]);
    }
}
