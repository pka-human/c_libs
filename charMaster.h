int Char2Int(char strc[]) {
    bool negative = false;
    int outputValue = 0;
    int stringLength = 0;
    while (strc[stringLength] != '\0') {  // count the number of characters in the string
        stringLength++;
    }
    for (int i = 0; i < stringLength; i++) {
        if (strc[i] == '-') {
            negative = true;  // remember that the input string is negative
        } else if (strc[i] >= '0' && strc[i] <= '9') {
            outputValue = outputValue * 10 + (strc[i] - '0');  // convert the character to an integer and add it to the output value
        } else {
            return 0;  // return 0 if the input string is invalid
        }
    }
    if (negative) {
        outputValue *= -1;  // make the output value negative if necessary
    }
    return outputValue;
}

char* Int2Char(int inputNumber) {
    static char resultString[17] = { '\0' };  // Define the character array as a static local variable
    char revc[17]; // Reverse buffer
    // Convert the integer to a string
    int it = 0, rev_it = 0; //forvard and revers iterator
    if (inputNumber < 0) { // Add negative as needed
        resultString[it++] = '-'; inputNumber = -inputNumber;
    }
    while (inputNumber) {
        revc[rev_it++] = '0' + inputNumber % 10;
        inputNumber /= 10;
    }
    while (rev_it) { // copy from reverse to string
        resultString[it++] = revc[--rev_it];
    }
    return resultString; // return a pointer to the character array
}
