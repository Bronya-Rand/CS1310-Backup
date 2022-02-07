public class Student {
    
    private String stuID;
    private String stuName;
    private static String uniName = "StMU";

    public Student(String stuID, String stuName) {
        this.stuID = stuID;
        this.stuName = stuName;
    }

    public void setStuID(String stuID) {
        this.stuID = stuID;
    }

    public void setStuName(String stuName) {
        this.stuName = stuName;
    }

    public String getStuID() {
        return stuID;
    }

    public String getStuName() {
        return stuName;
    }

    public static void setUniName(String uni) {
        uniName = uni;
    }

    public static String getUniName() {
        return uniName;
    }

    public String toString() {
        return (stuID + " " + stuName + " " + uniName);
    }
}
