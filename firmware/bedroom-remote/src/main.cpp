#include "ProjectConfig.h"
#include <HomeRemoteProtocol/HomeRemoteProtocol.h>
#include <WaveshareS3Touch/WaveshareS3Touch.h>

WaveshareS3Touch::Board board;

void setup() {
    board.begin();

    // Milestone 2 will initialize ESP-NOW and send HELLO + STATE_REQUEST.
    // Milestone 3 will initialize the final LVGL interface.
}

void loop() {
    board.update();
}
