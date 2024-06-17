# QuadTree data structure implementation for collision detection 

## Demo 
![](https://github.com/rick-n-shawty/QuadTree/blob/main/QuadTreeVid.gif)
#
Performance demo can be viewed![here: ](https://youtu.be/pj_C5bQpkV4)

## What is a QuadTree?
QuadTree is a recusive data structure that is used for spatial partitioning. It is particularly 
useful when it comes to collision detection. It works by recursively dividing space into four quadrants. This allows to go from time complexity of n^2 to nlog(n) in particle simulations.   

## Potential improvements 
Currently in the update(float dt) in Canvas.cpp, I am rebuilding all the children of the quadtree on every frame. Try to think of a better way to implement it and feel free to make a pull request '_'

## Getting Started on macOS

