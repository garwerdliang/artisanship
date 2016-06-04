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

void serveBMP (int socket, double x, double y, double zoomLevel) {
   char* message;
   // first send the http response header

   // (if you write stings one after another like this on separate
   // lines the c compiler kindly joins them togther for you into
   // one long string)
   message = "HTTP/1.0 200 OK\r\n"
                "Content-Type: image/bmp\r\n"
                "\r\n";
   printf ("about to send=> %s\n", message);
   write (socket, message, strlen (message));
   writeHeader(socket);
   // now send the BMP
   double w = 2;

   double distancePixel = pow(w, -zoomLevel);

   double startx = x - ((SIZE_X/2)-1) * distancePixel;
   double starty = y - ((SIZE_Y/2)-1) * distancePixel;

   int row = 0;
   int col = 0;

   unsigned char red, blue, green;
   int steps = 0;

     while (row < SIZE_Y){
      col = 0;
      while (col < SIZE_X){
         steps = escapeSteps(startx, starty);

         if (steps == 0){
            red = 0;
            blue = 0;
            green = 0;
         }else{
            red = stepsToRed (steps);
            blue = stepsToBlue (steps);
            green = stepsToGreen (steps);
         //colour stuff goes here
         }
         write (socket, &blue, sizeof blue);
         write (socket, &green, sizeof green);
         write (socket, &red, sizeof red);
         startx = startx + distancePixel;
         col++;
      }
      startx = x - ((SIZE_X/2)-1) * distancePixel;
      starty = starty + distancePixel;
      row++;
}


