# 0x11. C - printf

## Compilation

Your code will be compiled this way:

$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c

- As a consequence, be careful not to push any c file containing a main function in the root directory of your project (you could have a test folder containing all your tests files including main functions)
- Our main files will include your main header file (main.h): #include main.h

Group Project done by myself due to unforseen circumstances.                                                                    
                                                                                    
0. Write a function that produces output according to a format. 
    Prototype: int _printf(const char *format, ...);
        Returns: the number of characters printed (excluding the null byte used to end output to strings)
        write output to stdout, the standard output stream
        format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
        c
        s
        %
        You don’t have to reproduce the buffer handling of the C library printf function
        You don’t have to handle the flag characters
        You don’t have to handle field width
        You don’t have to handle precision
        You don’t have to handle the length modifiers
                                                                                
                                                                                    
1. Handle the following conversion specifiers:
    d
    i
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers

2. Handle the following custom conversion specifiers:  
    b: the unsigned int argument is converted to binary
    alex@ubuntu:~/c/printf$ cat main.c
    #include "main.h"

    /**
    * main - Entry point
    *
    * Return: Always 0
    */    
    int main(void)
    {
        _printf("%b\n", 98);
        return (0);
    }
    alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
    alex@ubuntu:~/c/printf$ ./a.out
    1100010
    alex@ubuntu:~/c/printf$                            
                                                                                    
3. Handle the following conversion specifiers:  
    u
    o
    x
    X
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers
                                                                                    
4. Use a local buffer of 1024 chars in order to call write as little as possible.      
                                                                                    
5. Handle the following custom conversion specifier:  
    S : prints the string.
    Non printable characters (0 < ASCII value < 32 or >= 127) are printed this way: \x, followed by the ASCII code value in hexadecimal (upper case - always 2 characters)
    alex@ubuntu:~/c/printf$ cat main.c
    #include "main.h"

    /**
    * main - Entry point
    *
    * Return: Always 0
    */
    int main(void)
    {
        _printf("%S\n", "Best\nSchool");
        return (0);
    }
    alex@ubuntu:~/c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
    alex@ubuntu:~/c/printf$ ./a.out
    Best\x0ASchool
    alex@ubuntu:~/c/printf$                                 
                                                                                    
6.  Handle the following conversion specifier: 
    p.  
    You don’t have to handle the flag characters
    You don’t have to handle field width
    You don’t have to handle precision
    You don’t have to handle the length modifiers                                     
                                                                                    
7.  Handle the following flag characters for non-custom conversion specifiers:     
    +
    space
    #
                                                                                    
8. Handle the following length modifiers for non-custom conversion specifiers:
    l
    h
    Conversion specifiers to handle: d, i, u, o, x, X                                
                                                                                    
9. Handle the field width for non-custom conversion specifiers.                        
                                                                                    
10. Handle the precision for non-custom conversion specifiers.                          
                                                                                    
11. Handle the 0 flag character for non-custom conversion specifiers.                   
                                                                                    
12. Handle the - flag character for non-custom conversion specifiers.                   
                                                                                    
13. Handle the following custom conversion specifier:
    r : prints the reversed string                                   
                                                                                    
14. Handle the following custom conversion specifier:                                   
                                                                                    
15. *                                                                               
All the above options work well together. 
