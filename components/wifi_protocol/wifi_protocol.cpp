#include "wifi_protocol.h"
#include "esphome/core/log.h"
#include "esp_wifi.h"

namespace esphome {
namespace wifi_protocol {

static const char *TAG = "wifi_protocol";

void WiFiProtocolComponent::setup() {
  ESP_LOGD(TAG, "Setting Wi-Fi to b/g only");
  esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G);
}

}  // namespace wifi_protocol
}  // namespace esphome

