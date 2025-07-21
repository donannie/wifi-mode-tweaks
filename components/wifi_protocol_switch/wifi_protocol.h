#pragma once
#include "esphome/core/component.h"
#include "esphome/components/switch/switch.h"

namespace esphome {
namespace wifi_protocol_switch {

class WiFiProtocolComponent : public esphome::Component, public esphome::switch_::Switch {
 public:
  void setup() override;
  void write_state(bool state) override;
};

}  // namespace wifi_protocol_switch
}  // namespace esphome
