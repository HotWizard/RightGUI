#include "include/RightGUI.hpp"
#include <cstdlib>

int main(void){
    RightGUI::ApplicationSettings::SetName("test");
    RightGUI::ApplicationSettings::SetVersion(RightGUI::version(0, 0, 1));
    RightGUI::init();
    
    return EXIT_SUCCESS;
}
