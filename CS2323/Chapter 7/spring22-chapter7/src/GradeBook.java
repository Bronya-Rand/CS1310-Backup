public class GradeBook {
    
    private double[] grades;

    public GradeBook(double[] grades) {
        this.grades = grades;
    }

    public void printGrades() {
        for (double grade: this.grades) {
            System.out.println(grade);
        }
    }

    public double calcHighestGrade() {
        double highest = grades[0];
        for (double grade: this.grades) {
            if (grade > highest) {
                highest = grade;
            }
        }
        return highest;
    }

    public double calcLowestGrade() {
        double lowest = grades[0];
        for (double grade: this.grades) {
            if (grade < lowest) {
                lowest = grade;
            }
        }
        return lowest;
    }

    public double calcAverage() {
        double average = 0;
        for (double grade: this.grades) {
            average += grade;
        }
        return average / (grades.length);
    }
}
