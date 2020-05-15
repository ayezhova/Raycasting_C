# Raycasting_C
Using C and a graphics library to recreate Wolfenstein 3D's graphic rendering of maps, for 42's Cube3D project.

Minilibx is a graphic's program provided by 42. My code files are within srcs. To run files, first `make` minilibx, then, from the srcs folder, use the following command to compile the code:
>cc -I ../minilibx_macos/ test.c -L ../minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

Depending on the operating system you are using, minilibx may not compile. Other versions of milibx are available here: https://github.com/pbondoer/MinilibX

## The goal of the project:
To end up with a program that allows a user to move along a map, which appears to be 3D.
<br/>
### Progress:
Date         | Update                                                                 | Next Goal
------------ | ---------------------------------------------------------------------- | ----------------
05/15/20     | Created 'drawline' function, which draws a straight line on the window | Respond to user's key presses. Specifically, when user presses the space key, draw an additional line slightly above the current line
