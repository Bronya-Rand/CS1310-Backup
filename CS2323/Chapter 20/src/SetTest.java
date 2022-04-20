public class SetTest {

    public static void main(String[] args) {
        String[] colors = { "red", "white", "blue", "green", "gray", "orange", "tan", "white", "cyan",
                "peach", "gray", "orange" };

        int size = colors.length;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (colors[i].equalsIgnoreCase(colors[j])) {
                    System.out.println("Found a duplicate " + colors[i]);
                }
            }
        }
    }
}
