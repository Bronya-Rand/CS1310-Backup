public class Time {
    private int hour;
    private int minute;
    private int second;

    public Time(int hour, int minute, int second) {
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0
                || second > 59) {
            throw new IllegalArgumentException(
                    "Hour, minute, and/or second sent is invalid.");
        }
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public void setHour(int hour) {
        if (hour < 0 || hour > 23) {
            throw new IllegalArgumentException("Hour sent is invalid.");
        }
        this.hour = hour;
    }

    public void setMinute(int minute) {
        if (minute < 0 || minute > 59) {
            throw new IllegalArgumentException("Hour sent is invalid.");
        }
        this.minute = minute;
    }

    public void setSecond(int second) {
        if (second < 0 || second > 59) {
            throw new IllegalArgumentException("Hour sent is invalid.");
        }
        this.second = second;
    }

    public String toString() {
        return String.format("%d:%d:%d %s%n",
                ((hour == 0 || hour == 12) ? 12 : hour % 12), minute, second,
                (hour < 12) ? "AM" : "PM");
    }
}
