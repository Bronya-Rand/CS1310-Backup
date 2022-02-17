public class Substring {
    
    public static void main(String[] args) {
        String code = "public static void main(String[] args)";
        String subString1 = code.substring(7);
        System.out.println(subString1);

        String subString2 = code.substring(7, 13);
        System.out.println(subString2);

        code = code.concat(subString2);
        System.out.println(code);
    }
}
