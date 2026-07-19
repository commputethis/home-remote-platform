#pragma once

#include <array>
#include <cstdint>

namespace ProjectConfig {

inline constexpr char ProjectName[] = "Home Remote Platform";
inline constexpr char DeviceName[] = "Bedroom Remote";
inline constexpr char Author[] = "Commputethis";
inline constexpr char EducationalProgram[] = "The Maker's Space";
inline constexpr char FirmwareVersion[] = "0.1.0";
inline constexpr std::uint32_t FirmwareVersionPacked = 0x000100;
inline constexpr std::uint16_t DeviceId = 1;

inline constexpr std::array<std::uint8_t, 6> BridgeMac{
    0x94, 0x51, 0xDC, 0x96, 0x8F, 0x20,
};

inline constexpr std::uint8_t EspNowChannel = 1;  // Verify against bridge Wi-Fi channel.

inline constexpr std::uint8_t MinimumBrightness = 2;
inline constexpr std::uint8_t MaximumBedroomBrightness = 18;
inline constexpr std::uint32_t DimTimeoutMs = 8'000;
inline constexpr std::uint32_t SleepTimeoutMs = 45'000;
inline constexpr std::uint8_t BatteryWarningPercent = 15;
inline constexpr std::uint8_t BatteryCriticalPercent = 5;

}  // namespace ProjectConfig
