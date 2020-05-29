# Raycasting_C
Using C and a graphics library to recreate Wolfenstein 3D's graphic rendering of maps, for 42's Cube3D project.

Minilibx is a graphic's program provided by 42. My code files are within srcs. To run files, run command `make` within the root folder.

Depending on the operating system you are using, minilibx may not compile. Other versions of milibx are available here: https://github.com/pbondoer/MinilibX

## The goal of the project:
To end up with a program that allows a user to move along a map, which appears to be 3D.
<br/>
### Check Ins:
Date         | Update                                                                 | Next Goal
------------ | ---------------------------------------------------------------------- | ----------------
5/15/20      | Created 'drawline' function, which draws a straight line on the window | Respond to user's key presses. Specifically, when user presses the space key, draw an additional line slightly above the current line
5/15/20      | Added struct containing window and mlx pointers, and added function that listens for user inputs. | User will pass map when running the program. Need to make sure this input is valid. For example - need to check that map is surrounded by walls on all sides
5/19/20      | Added ability to read input from user, the path to a map file when the -m flag is present when running the executable. | Goal of checking validity of map still current, but needs to be broken up into more chunks. Present goal: parse through map, and store information into s_map struct.
5/19/20      | Added a Makefile. Instead of running a long command, can now call `make` within root of directory. Ease of use and debugging.                                                                    | Parse through user inputed map.
5/21/20      | Reading user inputed maps and storing into struct.                     | Check that map string doesn't contain any invalid characters.
5/22/20      | Checking that input map is valid! That all borders are surrounded by 1's, that a player orientation is provided only once and that no invalid characters are used.                           | Check that all other player inputs are also valid. Ex: R is in the form "R # #".
5/24/20      | Checking that user inputs are in a valid form, also converting RGB inputs to a useable int value | Use player inputs in order to open window of player input size, or default if not included, and draw lines in player requested colors, if provided.
5/25/20      | Able to use data stored in struct to affect graphic display.           | Use mlx's image functions in order to display a sprite onto window.
5/26/20      | Using mlx's library to display an image on to the window.              | Scale photos bigger/smaller.
5/28/20      | Able to scale an image down by tenths (90%, 80% .... 10%).             | When image needs to be bigger, rather than scaling it larger, create a tile pattern with the image. Potential future goal: If necessary, add function that scales by hundreds (99%, 98%, .... 1%)
