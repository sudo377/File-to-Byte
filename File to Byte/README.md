# File to Byte converts

A simple C utility that converts any binary file into a C header (`.h`) containing a byte array.

## Features

* Convert **any binary file** into a C header.
* Supports all file types:

  * `.ttf`
  * `.png`
  * `.jpg`
  * `.bmp`
  * `.wav`
  * `.dll`
  * `.exe`
  * ...and any other binary file.
* Outputs a ready-to-use C array (`unsigned char[]`).
* Generates the size of the embedded data.
* Lightweight and written in standard C.

## Example

When you run the program:

```text
[+] Enter file path >>
```

Enter the path to your file:

```text
C:\Users\JohnDoe\Desktop\logo.png
```

The program creates an `output.h` file containing:

```c
#pragma once

unsigned char data[] = {
    0x89, 0x50, 0x4E, 0x47,
    0x0D, 0x0A, 0x1A, 0x0A,
    ...
};

unsigned int data_size = 12345;
```