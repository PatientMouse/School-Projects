# Project 1: Queue<anon>

* Author(s): Andrew Gerber with code from Buff
* Class: CS452
* Semester: Fall 2021

## Overview

    This is a warm up project for cs452 where we are implimenting a general-purpose list module which is made from a doubley-ended 
    doubly-linked list of anonymous pointers. The data is anonymous so that the list can be used in future projects.

## Compiling and Using

To compile and run this program, from the directory type in terminal:
    $make clean
    $make
    then to run it it depends on the executable name it could be the directory name or deq. it will be the only executable in the folder

    This is will run the main.c file using my deq.c, to compare it to Buffs code make try and ./try is used. This used a top level make file
    given you are in our pub directory. 
	
## Discussion

    I had to refresh my memory on doubley-ended doubly-linked list using geeksforgeeks overview. It took me some tim to understand what
    ht and np really were doing but after that I cruised. I had to go back during testing because i realized i forgot some circumstances.

    NOTE: I chose to use warn instead of error for the out of bounds etc. I can easyly change these for other projects, I wanted to be able to test w/o it exit(1)ing.

## Testing

    I tested this program by hard coding in print statments and printing the rep list after the given edit using the deq call.

## Extra Credit

No extra credit in this project.

## Sources used

    Code from Professor Buff
    GeeksforGeeks Overview of queues 
    