#pragma once
#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace wifi_protocol_switch {  // ✅ Match your renamed component folder and Python namespace

class WiFiProtocolComponent : public esphome::Component, public esphome::switch_::Switch {
 public:
  void setup() override;  // Called when ESPHome boots
  void write_state(bool state) override;  // Called when switch is toggled
};

}  // namespace wifi_protocol_switch
}  // namespace esphome
