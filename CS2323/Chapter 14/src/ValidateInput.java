public class ValidateInput {

    public static void main(String[] args) {
        String firstName = "Raiden";
        String lastName = "Ei";
        String address = "1 Ogosho Rd";
        String city = "Inazuma City";
        String zipCode = "21643";
        String state = "INZ";
        String phoneNumber = "210-732-0012";

        if (validateFirstName(firstName)) {
            System.out.println(firstName);
        }

        if (validateLastName(lastName)) {
            System.out.println(lastName);
        }

        if (validateAddress(address)) {
            System.out.println(address);
        }

        if (validateState(state)) {
            System.out.println(state);
        }

        if (validateZIPCode(zipCode)) {
            System.out.println(zipCode);
        }

        if (validatePhoneNumber(phoneNumber)) {
            System.out.println(phoneNumber);
        }
    }

    private static boolean validateFirstName(String firstName) {
        return firstName.matches("[A-Z][a-zA-Z]*");
    }

    private static boolean validateLastName(String lastName) {
        return lastName.matches("[a-zA-Z]+(['-]?\\s?[a-zA-Z]+)*");
        // Francis Damus
        // Smith
    }

    private static boolean validateAddress(String address) {
        // return address.matches("\\d+(\\s[A-Z][a-z]+)+");
        return address.matches("\\d+(\\s\\w+)+");
    }

    private static boolean validateZIPCode(String zipCode) {
        return zipCode.matches("\\d{5}");
    }

    private static boolean validateState(String state) {
        return state.matches("([A-Z]{2}|[A-Z]{3})");
    }

    private static boolean validatePhoneNumber(String phoneNumber) {
        return phoneNumber.matches("\\d{3}-\\d{3}-\\d{4}");
    }
}
