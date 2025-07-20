#pragma once
#include "esphome/core/component.h"

namespace esphome {
namespace wifi_protocol {

class WiFiProtocolComponent : public Component {
 public:
  void setup() override;
};

}  // namespace wifi_protocol
}  // namespace esphome
