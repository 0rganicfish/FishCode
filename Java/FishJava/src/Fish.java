public class Fish {

    public static void main(String[] args) {
        int i = Integer.MAX_VALUE;
        int j = Integer.MAX_VALUE;

        int k = i + j;
        System.out.printf("""
                i(%d) + j(%d) = %d%n
                """, i, j, k);
    }

}

//    public static int add(int... numbers) {
//        int sum = 0;
//
//        for (int num : numbers) {
//            sum += num;
//        }
//        System.out.println(Arrays.toString(numbers));
//        return sum;
//    }
//
//
//    public static String fun(String key, int value) {
//        return String.format("""
//                {
//                    key: %s,
//                    value: %d
//                }""", key, value);
//    }

//static class User {
//        private int a, b;
//        private String name;
//
//        public User() {
//        }
//
//        public User(int _a, int _b, String _name) {
//            a = _a;
//            b = _b;
//            name = _name;
//        }
//
//        public String toString() {
//            return String.format("""
//                    {
//                        name: %s,
//                        value: %d,
//                        fish: %d
//                    }""", name, a, b);
//        }
//
//    }
