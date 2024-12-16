Encryption/Decryption Utility Mini Project 2

Author: Abigail Jackson

About: 
This program uses files to encrypt and decrypt strings. 

Built With:
C programming language & Standard C libraries 

Getting Started:
1. Compile the code: Save the code as a c file (e.g., `miniproject2.c`) and compile it using a C compiler like GCC:
   gcc miniproject2.c -o miniproject2
2. Then make it an executable file to run the code in your terminal
    gcc miniproject2.c -o miniproject2.exe
3. Run your code in the terminal to encrypt or decrypt files:
    to encrypt:
    ./miniproject2.exe -E message.txt
    (executable -E text file)
    to decrypt
    ./miniproject2.exe -D message.crp
    (executable -D encrypted text file)


Testing: 
1. Testing encryption: 
to test encryption but the following string into your txt file. "Hello There how are you?<CR>My name is Sean Clarke.<tab>I like software!<CR>"
you should get the output in the crp file to look like "38555C5C5F80445855625580585F678051625580695F652F<CR>
3D69805E515D55805963804355515E80335C51625B558ETT39805C595B5580635F56646751625581<CR>"

2. Testing decrpytion: 
to test decrpytion but the following string into your crp file. "4458596380555E5362696064595F5E80635358555D55805963806062556464698067555962548E<CR>
39635E87648059642F812F<CR>" you should get the output in the txt file to look like "Then the decrypted file is:
This encryption scheme is pretty weird. <CR>
Isn’t it?!? <CR>"
