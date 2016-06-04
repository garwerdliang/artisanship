complex squareComplex(complex num) {
    complex result;
    result.a = num.a*num.a - num.b*num.b;
    result.b = 2 * num.a * num.b;
    return result;
}

complex addComplex(complex num1, complex num2) {
    complex result;
    result.a = num1.a + num2.a;
    result.b = num1.b + num2.b;
    return result;
}

int escapeSteps (double x, double y) {
    complex c;
    c.a = x;
    c.b = y;

    complex z;
    z.a = 0;
    z.b = 0;

    int result = 0;

    int i = 1;
    while (i < 256){
        z = addComplex(squareComplex(z), c);
        if (z.a*z.a + z.b*z.b > 4) {
            result = i;
            break;
        }
        i++;
    }
    result = i;
    return result;
}
