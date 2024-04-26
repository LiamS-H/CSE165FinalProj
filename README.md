Open as a clion project

Report:

This project is a simple tetris clone with the display
implemented in opengl and the control logic implemented by me.
There are two "libaries" which are part of the codebase representing
the game logic and an abstract ui class used for rendering.

The tetris game has a few quality of life features such as the hud
and the piece being displayed at the bottom before it drops. The
pieces have all the basic movements implemented, they can move down
and they can rotate. They have a `validate()` function which is
used to verify that a given move has been valid.

The main game logic revolves around the base `piece` class which
is a parent of all pieces to be rendered. The base `piece` class
defines the logic of being a piece, while the children define
their own shapes and modify the virtual function `rotate()` with
any logic specific to their shape. During rendering, the pieces
are upcasted to `piece *` pointers in order to be rendered and
check for collision. There is another instance of upcasting in the
UI library, where the primitive `graphic` defines two pure virtual 
functions necessary for being a graphic object. The window
object (a derivative of graphic) renders the list of graphics
stored in a vector by upcasting them to `graphic`.
