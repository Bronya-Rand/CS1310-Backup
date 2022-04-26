public class Pair<F, S> {

    private F elementOne;
    private S elementTwo;

    public Pair(F elementOne, S elementTwo) {
        this.elementOne = elementOne;
        this.elementTwo = elementTwo;
    }

    public void setElementOne(F elementOne) {
        this.elementOne = elementOne;
    }

    public void setElementTwo(S elementTwo) {
        this.elementTwo = elementTwo;
    }

    public F getElementOne() {
        return elementOne;
    }

    public S getElementTwo() {
        return elementTwo;
    }
}
