public class DateTest {
    
    public static void main(String[] args) {
        Date date1 = new Date(6, 8, 2020);
        Date date2 = new Date(13, 36, 3022);

        System.out.printf("Date 1 Info%nMonth: %d%nDay: %d%nYear: %d%n%n", 
            date1.getMonth(), date1.getDay(), date1.getYear());

        System.out.printf("Date 2 Info%n%nMonth: %d%nDay: %d%nYear: %d%n%n", 
            date2.getMonth(), date2.getDay(), date2.getYear());

        System.out.println("Fixing Date 2");
        date2.setMonth(12);
        date2.setDay(25);
        date2.setYear(2021);

        System.out.printf("Date 2 Info%nMonth: %d%nDay: %d%nYear: %d%n%n", 
            date2.getMonth(), date2.getDay(), date2.getYear());

        //print date patterns
        System.out.println("Printing Date Format");
        date1.displayDate();
        date2.displayDate();
    }
}
