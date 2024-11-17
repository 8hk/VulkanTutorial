#pragma once
#define GLFW_INCLUDE_VULKAN

/*
LVE means = Little Vulkan Engine
*/
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
using namespace std;
namespace lve
{
    class LveWindow
    {
    private:
        void initWindow();
        const int width;
        const int height;
        string windowName;
        GLFWwindow *window;
    public:
        LveWindow(int w,int h,string name);
        ~LveWindow();

       LveWindow(const LveWindow&) = delete;
       LveWindow &operator = (const LveWindow &) = delete;
       
       bool shouldClose();
       bool validateInputs();
    };
    
    
    
} // namespace lve

