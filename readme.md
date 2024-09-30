# MyGame Build Instructions

### Requirements:

- You must have all necessary libraries (e.g., SDL2, GLAD, Freetype, etc.) located in the `Q:/include` folder.
- You must have Visual Studio tools downloaded on windows (the commands will be run on x64 Native tools)

### Steps to Build and Run:

1. **Switch to the Q: Drive**

   Open the command prompt and switch to the `Q:` drive by typing:

Q:

2. **Build and Run the Game**

To clean, build, and run your project, execute the following commands:

clean && build && mygame

- `clean` removes any previously compiled files.
- `build` compiles the project.
- `mygame` runs the executable after building.

3. **Update the github**

To update the github, add the files, commit changes, and push to origin.
This can all be done with this command:

git add . && git commit -m "Your commit message here" && git push origin main

### Note:

Ensure that your development environment is properly configured to locate the necessary include paths and libraries stored in the `Q:/include` folder.
