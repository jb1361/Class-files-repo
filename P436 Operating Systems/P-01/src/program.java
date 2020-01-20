import java.util.Date;

public class program {
    public static void main (String[] args) {
        System.out.println("Justin Butler");
        System.out.println(new Date());
        System.out.println(System.getProperty("java.version"));
        System.out.println(System.getProperty("os.name"));
        System.out.println(Runtime.getRuntime().maxMemory() + " Bytes");
        System.out.println(Runtime.getRuntime().freeMemory() + " Bytes");
        System.out.println(Runtime.getRuntime().totalMemory() + " Bytes");
        System.out.println(System.getProperty("os.arch"));
        System.out.println(System.getProperty("user.dir"));
    }
}
