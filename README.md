# 42-GNL, by Maxime Rochedy

Here is my implementation of the **Get Next Line (GNL)** project, a fundamental project from the 42 curriculum. The goal of this project is to implement a function that reads a line from a file descriptor until a newline character or the end of the file. This repository contains my full implementation of **GNL**, which received the maximum score of 125/100.

Here, you'll find a carefully crafted version, that was evaluated by three different students, as well as the **Moulinette** correction tool. While every effort was made to ensure the code is bug-free, errors may still exist. Your feedback is highly appreciated!

<img width="198" alt="125/100 grade" src="https://github.com/user-attachments/assets/708486c1-c045-40d6-ab0c-e5dc3650a50d">

## About the Project

The **Get Next Line (GNL)** function is a key utility in many coding projects that require reading from a file or input line by line. The function you will find here reads from any file descriptor and returns the next line, allowing developers to handle input efficiently.

This repository provides a **complete implementation** of the **Get Next Line** project from 42, bonuses included. It was coded by **Maxime Rochedy**, under the login **mrochedy**, as part of the 42 program, using linked lists of characters. This project challenges you to work with memory management, file descriptors, and buffer handling.

Please note that while this code is provided for **learning purposes**, you should not copy it for your own submissions. Using this repository responsibly will help you better understand file descriptor management and buffer usage in C programming. Please respect the 42 school's policies on plagiarism.

## Getting Started

To use this library in your own projects, you need to clone the repository and add a main function to it.

```bash
git clone https://github.com/mrochedy/42-GNL.git
```

Here's a basic example of how you might use **Get Next Line** in a C program:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

You can then compile the program like so:

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
```

## Contributing

If you have any suggestions, questions, or issues, feel free to open an issue or contribute via pull requests.

If this repository has helped you in your own **Get Next Line (GNL)** project, please consider giving it a ⭐️ **star** ⭐ to show your support!

Thank you for visiting and happy coding!
