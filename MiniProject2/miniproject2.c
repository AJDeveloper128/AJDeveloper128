#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a single character
char* encryptChar(char letter) {
  // Allocate memory to store the encrypted character (up to 3 characters
  // because of hexadecimal representation)
  char* encrypted = malloc(3 * sizeof(char));

  if (letter == '\t') {
    // If the character is a tab, encrypt it as "TT"
    strcpy(encrypted, "TT");
  } else if (letter != '\r' && letter != '\n') {
    // If the character is not a carriage return or newline, apply the
    // encryption scheme
    int outChar = letter - 16;
    if (outChar < 32) {
      // If the result is less than 32, adjust it to wrap around
      outChar = (outChar - 32) + 144;
    }
    // Convert the encrypted ASCII value to a 2-digit hexadecimal string
    sprintf(encrypted, "%02X", outChar);
  } else {
    // If the character is a carriage return or newline, keep it as is
    encrypted[0] = letter;
    encrypted[1] = '\0';
  }
  return encrypted;
}

// Function to decrypt a pair of characters
char decryptChars(char letter1, char letter2) {
  if (letter1 == 'T' && letter2 == 'T') {
    // If the input is "TT", decrypt it as a tab
    return '\t';
  } else {
    // Convert the hexadecimal characters back to an integer
    int outChar;

    if (letter1 >= 'A') {
      outChar = (letter1 - 'A' + 10) * 16;
    } else {
      outChar = (letter1 - '0') * 16;
    }

    if (letter2 >= 'A') {
      outChar += letter2 - 'A' + 10;
    } else {
      outChar += letter2 - '0';
    }
    outChar += 16;
    if (outChar > 127) {
      // If the result is greater than 127, adjust it to wrap around
      outChar = (outChar - 144) + 32;
    }
    return (char)outChar;
  }
}

int main(int commandArg, char* argValue[]) {
  // Check if the number of command-line arguments is correct (2 or 3)
  if (commandArg < 2 || commandArg > 3) {
    fprintf(stderr, "Usage: %s [-E|-D] filename\n", argValue[0]);
    return 1;
  }

  int encrypt = 1;
  char* filename = NULL;

  if (commandArg ==
      3) {  // If there are 3 arguments (program name, switch, filename)
    if (strcmp(argValue[1], "-E") == 0) {
      encrypt = 1;  // Set encrypt to 1 for encryption mode
    } else if (strcmp(argValue[1], "-D") == 0) {
      encrypt = 0;  // Set encrypt to 0 for decryption mode
    } else {
      fprintf(stderr, "Invalid switch: %s\n", argValue[1]);
      return 1;
    }
    filename = argValue[2];  // Get the filename from the third argument
  } else {
    filename = argValue[1];  // If there are 2 arguments, the filename is the
                             // second argument
  }

  // Open the input file in read mode ("r")
  FILE* inputFile = fopen(filename, "r");
  if (inputFile == NULL) {  // Check if the file was opened successfully
    fprintf(stderr, "Error opening input file: %s\n", filename);
    return 1;
  }

  // Construct the output filename
  char* outputFilename =
      malloc(strlen(filename) +
             5);  // Allocate memory for the output filename (original length +
                  // 4 for extension + 1 for null terminator)
  strcpy(outputFilename, filename);
  char* period =
      strrchr(outputFilename,
              '.');  // Find the last occurrence of '.' in the filename
  if (period != NULL) {
    *(period + 1) = '\0';
  }
  if (encrypt) {
    strcat(outputFilename, "crp");
  } else {
    strcat(outputFilename, "txt");
  }  // Append the appropriate extension based on
     // encryption/decryption mode

  // Open the output file in write mode ("w")
  FILE* outputFile = fopen(outputFilename, "w");
  if (outputFile == NULL) {  // Check if the file was opened successfully
    fprintf(stderr, "Error creating output file: %s\n", outputFilename);
    fclose(inputFile);
    return 1;
  }

  char line[121];
  while (fgets(line, sizeof(line), inputFile) != NULL) {
    if (encrypt) {
      // If in encryption mode, encrypt each character in the line
      for (int i = 0; line[i] != '\0' && line[i] != '\r' && line[i] != '\n';
           i++) {
        char* encryptedCh = encryptChar(line[i]);  // Encrypt the character
        fputs(encryptedCh, outputFile);
        printf("%s", encryptedCh);
        free(encryptedCh);  // Free the memory allocated for the encrypted
                            // character
      }
    } else {
      // If in decryption mode, decrypt each pair of characters in the line
      for (int i = 0; line[i] != '\0' && line[i] != '\r' && line[i] != '\n';
           i += 2) {
        char decryptedCh =
            decryptChars(line[i], line[i + 1]);  // Decrypt the characters
        fputc(decryptedCh, outputFile);
        printf("%c", decryptedCh);
      }
    }
    // Preserve carriage returns and newlines in the output
    if (strchr(line, '\r') != NULL || strchr(line, '\n') != NULL) {
      if (strchr(line, '\r') != NULL) {
        fputs("\r", outputFile);
      } else {
        fputs("\n", outputFile);
      }
      printf("\n");
    }
  }

  fclose(inputFile);
  fclose(outputFile);
  free(outputFilename);

  if (encrypt) {
    printf("\nEncrypted file %s successfully.\n", filename);
  } else {
    printf("\nDecrypted file %s successfully.\n", filename);
  }
  return 0;
}