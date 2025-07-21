#include "wifi_protocol.h"
#include "esphome/core/log.h"
#include "esp_wifi.h"

namespace esphome {
namespace wifi_protocol_switch {

static const char *TAG = "wifi_protocol";

void WiFiProtocolComponent::setup() {
  ESP_LOGI(TAG, "WiFiProtocolComponent initialized");
  esp_err_t result = esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G);
  if (result == ESP_OK) {
    ESP_LOGI(TAG, "Successfully set Wi-Fi to b/g only");
  } else {
    ESP_LOGW(TAG, "Failed to set Wi-Fi protocol: %d", result);
  }
}

void WiFiProtocolComponent::write_state(bool state) {
  ESP_LOGI(TAG, "Dummy switch toggled: %s", state ? "ON" : "OFF");
  publish_state(state);
}

}  // namespace wifi_protocol_switch
}  // namespace esphome
