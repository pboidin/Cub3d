# Cub3d
This project is inspired by the world famous game of the same name, considered to be the first FPS ever developed. It will allow you to explore the ray-casting technique. Your objective is to make a dynamic view within a maze, in which you will have to find your way.

# Description
You must create a 3D graphic representation "representation that we could have in a labyrinth using a labyrinth using a subjective view. You create this representation using the principles of principles of ray-casting mentioned earlier.

The constraints are as follows:
- You must use the minilibX. Either in the version available on your OS, or from its sources. If you decide to work with the sources, the same rules as libft apply as those written above in the Common Instructions part.
- The window management must be perfect : minimization management, passing another window, etc
- You have to display different textures (you have the choice) depending on if the walls are facing north, south, east, west.
- Your program must be able to have different colors for the floor and ceiling
- The program displays the image in a window and follows the following rules:<br/>
  ◦ The left and right arrow keys on the keyboard must allow rotation of the camera (look left and right)<br/>
  ◦ The keys W, A, S and D must allow to move the camera (move the character)<br/>
  ◦ Pressing the ESC key should close the window and exit the program properly<br/>
  ◦ Clicking on the red cross in the window should close the window and exit the program cleanly\n
  ◦ The use of images from the minilibX is highly recommended.<br/>
- Your program must take as first argument a scene description file with extension .cub<br/>
  ◦ The map must be composed of only these 6 characters: 0 for empty spaces, 1 for walls, and N,S,E or W which represent the starting position of the player and its orientation.<br/>
    This simple map must be valid:<br/>
        111111<br/>
        100101<br/>
        101001<br/>
        1100N1<br/>
        111111<br/>
  ◦ The map must be closed/enclosed with walls, otherwise the program must return an error.<br/>
  ◦ Apart from the map description, each type of element can be separated by one or more empty lines.<br/>
  ◦ The map description will always be last in the file, the rest of the elements can be in any order.<br/>
  ◦ Except for the map itself, the information in each element can be separated by one or more space(s).<br/>
  ◦ The map must be parsed in accordance with what is presented in the file. Spaces are a valid part of the map, it is up to you to manage them properly. You should be able to parse any kind of map, as long as it follows the map rules.<br/>

  ◦ For each element, the first character is the identifier (one or two characters), followed by all the element-specific information in a such as :
    - North texture :
      NO ./path_to_the_north_texture
    - identifier : NO
    - path to the north texture
    
    - South texture :
      SO ./path_to_the_south_texture
    - identifier : SO
    - path to the south texture
    
    - West texture :
      WE ./path_to_the_west_texture
    - identifier : WE
    - path to the west texture

    - East texture :
      EA ./path_to_the_east_texture
    - identifier : EA
    - path to the east texture

    - Ground color:
      F 220,100,0
    - identifier: F
    - colors R,G,B range [0,255] : 0, 255, 255

    - Ceiling color :
      C 225,30,0
    - ID: C
    - colors R,G,B range [0,255] : 0, 255, 255
