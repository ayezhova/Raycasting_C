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
6/06/20      | Added function to create a 'tile' pattern with an image. After providing it with the new width and height, will tile the image starting with the (0, 0) corner. Additionally, added a function that will modify a given image to create a 'trapezoid' shape. When looking at a wall, for example, the wall closest to the play will appear larger, and the wall further away will appear smaller. By specifying an identical start and end length, this function can also be used to scale imaged up. Also, updated some variable names for clarity (line -> line_orig and line2-> line_new)| Need to add more functionality to the trapezoid function. For example, scaling images to have a smaller width than the original image, and allowing for a 'reverse' trapezoid, when the start length is smaller than the end length. Finally, need to update the function in order lengthen shapes close to the viewer and shorten shapes further from the view.
6/08/20      | By passing different sized start height, end height and image widths, able to create trapezoid images that are asceding or descending, and can now scale images down as well.                    | Currently, scaling is done linearly in the trapezoid functions, but images that are closer should appear not only larger but longer as well, and further away objects should be narrower. So, need to adjust the scaling of how often each column of column should be written depending on how far it is from the longest side.
6/24/20      | While researching how to find height of nearby walls found Lode Vandevenne's [raycasting guide](https://lodev.org/cgtutor/raycasting.html), which details how to find the distance of the player to the 'camera plane' which is perpendicular do the direction the player is currently facing. Added struct to my project which uses the map information to set the player's position, direction and camera vectors. | Calculate the height in pixels of the wall the player is currently directly facing.
7/9/20       | Drawing walls as static image to screen. Distance to walls determines height of each wall, with closer walls being displayed as longer lines in image. | Enable keystrokes - so by pressing arrow keys, for example, player is able to move in a direction. Image in window should clear, then recalculate distances of walls, and redraw the new position.
