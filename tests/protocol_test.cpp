#include <cassert>
#include <cstdint>
#include <iostream>

#include "HomeRemoteProtocol/HomeRemoteProtocol.h"

int main() {
    using namespace HomeRemoteProtocol;

    CommandPayload payload{Command::FanSpeed, 66};
    auto packet = makePacket(MessageType::Command, 42, 1, payload);

    assert(validate(packet, MessageType::Command));
    assert(packet.header.sequence == 42);
    assert(packet.header.device_id == 1);
    assert(packet.payload.command == Command::FanSpeed);
    assert(packet.payload.value == 66);

    packet.payload.value = 100;
    assert(!validate(packet, MessageType::Command));

    std::cout << "HomeRemoteProtocol tests passed\n";
    return 0;
}
