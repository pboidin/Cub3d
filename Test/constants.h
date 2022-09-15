#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

/*
** General
*/

# define VALID_CHARS "012NSEW "
# define SCALE 64
# define VIEW_ANGLE 60

/*
** Keycodes
*/

# ifndef OS
#  define K_ESC 53
#  define K_W 13
#  define K_A 0
#  define K_S 1
#  define K_D 2
#  define K_LEFT_ARROW 123
#  define K_RIGHT_ARROW 124
# else
#  define K_ESC 65307
#  define K_W 122
#  define K_A 113
#  define K_S 115
#  define K_D 100
#  define K_LEFT_ARROW 65361
#  define K_RIGHT_ARROW 65363
# endif

/*
** X11 Events
*/

# ifndef OS
#  define DESTROY_NOT 17
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOT 131072
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# else
#  define DESTROY_NOT 33
#  define KEY_PRESS 02
#  define KEY_RELEASE 03
#  define M_DESTROY_NOT 0
#  define M_KEY_PRESS 1
#  define M_KEY_RELEASE 2
# endif

#endif