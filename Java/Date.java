public class Date {
    private int year, month, day;

    public Date(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    public String toString() {
        return year + "/" + month + "/" + day;
    }
}
