#ifndef TASK8_INPUTCONTROLLER_HPP
#define TASK8_INPUTCONTROLLER_HPP
#include "Params.h"
#include <unordered_set>
#include <QKeyEvent>


class InputController final{
public:
    InputController(Params& p){
        params = p;
    }
    void keyPressEvent(QKeyEvent *event);

    bool swapKeyFlag = false;

private:
    std::unordered_set<int> pressedKeys;
    int lastPressedKey = 0x00;
    Params params;
};


#endif
