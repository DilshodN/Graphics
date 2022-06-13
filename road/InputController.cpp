#include "InputController.hpp"

void InputController::keyPressEvent(QKeyEvent *event) {
    int pressedKey = event->key();
    if (lastPressedKey != pressedKey) {
        if (pressedKey == Qt::Key::Key_Up){
            params.camera_pos.setX(params.camera_pos.x() + 0.05);
        }
        swapKeyFlag = true;
    }
    lastPressedKey = pressedKey;
}
