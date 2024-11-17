#pragma once


#include "lve_window.hpp"

namespace lve{
    class FirstApp
    {
    private:
        LveWindow lveWindow{WIDTH,HEIGHT,"Hoi Vulkan"};
    public:
       static constexpr int WIDTH = 800;
       static constexpr int HEIGHT = 600;

       void run();
    };    
}