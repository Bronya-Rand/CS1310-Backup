import java.util.Scanner;

public class AlexaTest {

    public static void main(String[] args){
        AlexaApp alexaApp = new AlexaApp();

        Device echo_dot = new Device(Device.DeviceType.ECHO_DOT, "my echo dot");

        alexaApp.addDevice(echo_dot);

        System.out.println("Now ready to use. You can say \"Alexa add quantity item_name to shopping list\"\n" +
                "Replace quantity and item_name with a digit and an item from the current inventory\n"+
                "To terminate on macOs enter <Ctrl> d\n" +
                "To terminate on windows enter <Ctrl> z");

        Scanner input = new Scanner(System.in);
        while(input.hasNext()){
            echo_dot.listen(input.nextLine());
        }
    }

}
