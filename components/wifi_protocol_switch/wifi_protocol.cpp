#include "wifi_protocol.h"
#include "esp_wifi.h"  // ✅ Required for esp_wifi_set_protocol()

namespace esphome {
namespace wifi_protocol_switch {

void WiFiProtocolComponent::setup() {
  // Optional: log current Wi-Fi mode or do something at startup
}

void WiFiProtocolComponent::write_state(bool state) {
  ESP_LOGI("wifi_protocol", "Dummy switch toggled: %s", state ? "ON" : "OFF");

  wifi_interface_t iface = WIFI_IF_STA;

  if (state) {
    // ✅ Enable 802.11b/g only
    esp_wifi_set_protocol(iface, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G);
  } else {
    // 🔄 Reset to all protocols (b/g/n)
    esp_wifi_set_protocol(iface, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G | WIFI_PROTOCOL_11N);
  }

  // Update switch state in ESPHome
  this->publish_state(state);
}

}  // namespace wifi_protocol_switch
}  // namespace esphome

