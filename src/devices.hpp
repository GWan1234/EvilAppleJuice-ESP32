#include <Arduino.h>

enum PacketType { APPLE_AUDIO, APPLE_SETUP };
struct AppleDevice {
  const char* name;
  uint8_t modelId;
  PacketType type;
};

const AppleDevice ALL_DEVICES[] = {
  // Audio Devices (31 bytes, ID at index 7)
  // These are audio devices: wireless headphones / earbuds
  // It seems these need a shorter range between ESP & iDevice
  {"Airpods", 0x02, APPLE_AUDIO},
  {"Power Beats", 0x03, APPLE_AUDIO},
  {"Beats X", 0x05, APPLE_AUDIO},
  {"Beats Solo 3", 0x06, APPLE_AUDIO},
  {"Beats Studio 3", 0x09, APPLE_AUDIO},
  {"Airpods Max", 0x0a, APPLE_AUDIO},
  {"Power Beats Pro", 0x0b, APPLE_AUDIO},
  {"Beats Solo Pro", 0x0c, APPLE_AUDIO},
  {"Airpods Pro", 0x0e, APPLE_AUDIO},
  {"Airpods Gen 2", 0x0f, APPLE_AUDIO},
  {"Beats Flex", 0x10, APPLE_AUDIO},
  {"Beats Studio Buds", 0x11, APPLE_AUDIO},
  {"Beats Fit Pro", 0x12, APPLE_AUDIO},
  {"Airpods Gen 3", 0x13, APPLE_AUDIO},
  {"Airpods Pro Gen 2", 0x14, APPLE_AUDIO},
  {"Beats Studio Buds Plus", 0x16, APPLE_AUDIO},
  {"Beats Studio Pro", 0x17, APPLE_AUDIO},
  {"Airpods Pro Gen 2 USB-C", 0x24, APPLE_AUDIO},
  {"Beats Solo 4", 0x25, APPLE_AUDIO},
  {"Beats Solo Buds", 0x26, APPLE_AUDIO},
  {"Software update", 0x2e, APPLE_AUDIO},
  {"Powerbeats fit", 0x2f, APPLE_AUDIO},

  // Setup Devices (23 bytes, ID at index 13)
  // These are more general home devices
  // It seems these can work over long distances, especially AppleTV Setup
  {"AppleTV Setup", 0x01, APPLE_SETUP},
  {"Transfer Number", 0x02, APPLE_SETUP},
  {"AppleTV Pair", 0x06, APPLE_SETUP},
  {"Setup New Phone", 0x09, APPLE_SETUP},
  {"Homepod Setup", 0x0b, APPLE_SETUP},
  {"AppleTV Homekit Setup", 0x0d, APPLE_SETUP},
  {"AppleTV Keyboard Setup", 0x13, APPLE_SETUP},
  {"TV Color Balance", 0x1e, APPLE_SETUP},
  {"AppleTV New User", 0x20, APPLE_SETUP},
  {"Vision Pro", 0x24, APPLE_SETUP},
  {"AppleTV Connecting to Network", 0x27, APPLE_SETUP},
  {"AppleTV AppleID Setup", 0x2b, APPLE_SETUP},
  {"AppleTV Wireless Audio Sync", 0xc0, APPLE_SETUP},
};

void generatePacket(const AppleDevice& device, uint8_t* buffer, size_t& outLength);
