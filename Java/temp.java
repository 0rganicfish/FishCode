import java.util.*;

public class temp {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int y = cin.nextInt(), m = cin.nextInt(), d = cin.nextInt();
        Date date = new Date(y, m, d);
        System.out.println(date);
        cin.close();
    }
}