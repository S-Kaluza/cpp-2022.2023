class main {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }

    // funkcja obliczająca tablicę wartości funkcji kwadratowej dla podanego
    // przedziału oraz x-min i x-max oraz rozłożonego na 361 punktów
    public static double[] kwadratowa(double a, double b, double c, double x_min, double x_max) {
        double[] tab = new double[361];
        double x = x_min;
        double dx = (x_max - x_min) / 360;
        for (int i = 0; i < 361; i++) {
            tab[i] = a * x * x + b * x + c;
            x += dx;
        }
        return tab;
    }

    // funkcja obliczająca tablicę wartości funkcji trygonometrycznej dla podanego
    // przedziału oraz x-min i x-max oraz rozłożonego na 361 punktów
    public static double[] trygonometryczna(double a, double b, double c, double x_min, double x_max) {
        double[] tab = new double[361];
        double x = x_min;
        double dx = (x_max - x_min) / 360;
        for (int i = 0; i < 361; i++) {
            tab[i] = a * Math.sin(b * x + c);
            x += dx;
        }
        return tab;
    }
    // funkcja obliczająca tablicę wartości funkcji logarytmicznej dla podanego
    // przedziału oraz x-min i x-max oraz rozłożonego na 361 punktów

}