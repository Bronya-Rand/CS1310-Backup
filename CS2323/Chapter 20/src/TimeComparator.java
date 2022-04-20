import java.util.Comparator;

public class TimeComparator implements Comparator<Time2> {

    @Override
    public int compare(Time2 o1, Time2 o2) {
        int hourDifference = o1.getHour() - o2.getHour();
        if (hourDifference != 0) {
            return hourDifference;
        }

        int minuteDifference = o1.getMinute() - o2.getMinute();
        if (minuteDifference != 0) {
            return minuteDifference;
        }

        int secondDifference = o1.getSecond() - o2.getSecond();
        return secondDifference;
    }

}
