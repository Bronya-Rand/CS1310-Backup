import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class TimeApp {
    public static void main(String[] args) throws Exception {
        Time2 t1 = new Time2(12, 59, 59);
        Time2 t2 = new Time2(13, 55, 37);
        Time2 t3 = new Time2(7, 8, 9);

        System.out.println(t1.toString());

        List<Time2> timeList = new ArrayList<>();
        timeList.add(t1);
        timeList.add(t2);
        timeList.add(t3);

        Collections.sort(timeList, new TimeComparator());

        for (Time2 time2 : timeList) {
            System.out.println(time2);
        }
    }
}
