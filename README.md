# Welcome!

A real-time 3D rotating cube rendered entirely with ASCII characters in your terminal. No graphics libraries required.

## About
This project creates a captivating visual experience by rendering a rotating 3D cube using only ASCII characters in the terminal. Inspired by a YouTube tutorial on terminal-based 3D rendering, this implementation showcases how classic computer graphics principles can create compelling animations with minimal resources.

## ✨ Features

- Real-time 3D rendering in terminal using only ASCII characters</li>
- Smooth rotation animation with customizable speed</li>
- Perspective projection for realistic 3D depth</li>
- ASCII-based shading for enhanced visual depth</li>
- Zero dependencies - pure C implementation</li>
- Cross-platform compatibility (Linux, macOS, Windows with appropriate terminal)</li>

## Visual Experience
The cube appears to rotate smoothly in 3D space, with each face represented by a different ASCII character, creating a distinctive visual pattern that clearly shows the cube's geometry and rotation. The perspective projection adds depth, making closer edges appear larger than distant ones.


## How it works
The program uses fundamental 3D graphics techniques:
1. **3D Coordinates** - Defines 8 vertices of a cube in 3D space
2. **Rotation Matrices** - Applies mathematical transformations to rotate the cube around X, Y, and Z axes
3. **Perspective Projection** - Converts 3D coordinates to 2D screen space with depth perception
4. **ASCII Rendering** - Maps 3D points to terminal characters, creating the illusion of a solid object
5. **Frame Loop** - Continuously updates rotation angles and re-renders for smooth animation

**Algorithm Complexity:**
- Time Complexity: O(n²) per frame, where n is the cube resolution
- Space Complexity: O(w × h) for the screen buffer and z-buffer

## 🙏 Acknowledgments
- Inspired by terminal-based 3D rendering tutorials
- Based on classic computer graphics principles
- Thanks to the YouTube tutorial for the educational foundation

## 🤝 Contributing
Contributions are welcome! Feel free to:
- Report bugs
- Suggest features
- Submit pull requests
- Improve documentation

### Watch the video!
<a href="https://www.youtube.com/watch?v=p09i_hoFdd0" target="_blank">
  <img src="https://img.youtube.com/vi/p09i_hoFdd0/maxresdefault.jpg" width="400"/></a>
  
&copy; 2025 GitHub &bull; [Code of Conduct](https://www.contributor-covenant.org/version/2/1/code_of_conduct/code_of_conduct.md)
