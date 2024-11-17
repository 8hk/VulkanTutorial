# VulkanTutorial

Following the [Vulkan (c++) Game Engine Tutorials](https://www.youtube.com/playlist?list=PL8327DO66nu9qYVKLDmdLW_84-yE4auCR) from [Brendan Galea](https://www.youtube.com/@BrendanGalea)

New branch is going to be created for each tutorial.
I've used Vulkan and CMake for the whole project.
I did not follow Brendan completely, I've updated the code if it is needed. 

## Branches

Each branch is going to be added in following sections

### 1st Tutorial

In this tutorial, new window has been created by using GLFW. 
You can access the branch from [here](https://github.com/8hk/VulkanTutorial/tree/tutorial_1)

### 2nd Tutorial

In this tutorial,  

1. Fragment and vertex files are generated,
1. SPIR-V files are generated for fragment and vertex files by using glscl tool.
1. Create pipeline (the classes to read frag and vert files.)

You can access the branch from [here](https://github.com/8hk/VulkanTutorial/tree/tutorial_2)

compile.bat file is not uploaded.

Example usage for windows:
```
D:\Tools\VulkanSDK\1.3.296.0\Bin\glslc.exe shaders\simple_shader.vert -o shaders\simple_shader.vert.spv
```
TODOs:
1. Update pipeline class wrt RAII. 
2. Update path retrieval logic at first_app.hpp