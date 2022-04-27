
public class PairTest {

    public static void main(String[] args) {
        Integer t1 = 2;
        String t2 = "hi world";
        Double newT1 = 3.14;
        Pair pair1 = new Pair(t1, t2);
        System.out.println(pair1.getElementOne());
        System.out.println(pair1.getElementTwo());
        pair1.setElementOne(newT1);
        System.out.println(pair1.getElementOne());
    }
}
