# 📡 ESPHome Component: `wifi_protocol_switch`

Force your ESP32 into **802.11b/g-only mode** using a simple switch in ESPHome. Designed for advanced Wi-Fi debugging, compatibility testing, and network tuning.

---

![ESPHome](https://img.shields.io/badge/ESPHome-2025.7.2-blue?logo=esphome)
![Platform](https://img.shields.io/badge/Platform-ESP32-lightgrey)
![Protocol](https://img.shields.io/badge/WiFi-b%2Fg--only-critical)
![License](https://img.shields.io/badge/License-MIT-green)

---

## 💡 Features

- 🖱️ Toggle switch to set Wi-Fi protocol in real time
- 📉 Drops bitrate to ~54 Mbps (b/g-only)
- 🔄 Restores b/g/n support when switched off
- 🧠 Clean reconnection after protocol change
- 🔧 Modular external component format

---

## ⚙️ Installation

In your ESPHome YAML file:

```yaml
external_components:
  - source: github://donannie/wifi-mode-tweaks@main
    refresh: 0s
    components: [wifi_protocol_switch]

switch:
  - platform: wifi_protocol_switch
    id: wifi_proto_switch
    name: "Wi-Fi Mode Switch"
```

> ✅ `refresh: 0s` ensures your ESPHome build pulls the latest version every time.

---

## 🗂️ File Structure

```
components/
└── wifi_protocol_switch/
    ├── switch.py
    ├── __init__.py
    ├── wifi_protocol.h
    └── wifi_protocol.cpp
```

---

## 🐍 Python Interface

### `__init__.py`

Defines schema and links ESPHome to C++ logic:

```python
CONFIG_SCHEMA = switch.switch_schema(WiFiProtocolComponent)
```

### `switch.py`

Required ESPHome loader:

```python
from .__init__ import (
    WiFiProtocolComponent,
    CONFIG_SCHEMA,
    to_code,
)
```

---

## 💻 C++ Implementation

### `wifi_protocol.cpp`

```cpp
void WiFiProtocolComponent::write_state(bool state) {
  wifi_interface_t iface = WIFI_IF_STA;

  if (state) {
    esp_wifi_set_protocol(iface, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G);
  } else {
    esp_wifi_set_protocol(iface, WIFI_PROTOCOL_11B | WIFI_PROTOCOL_11G | WIFI_PROTOCOL_11N);
  }

  this->publish_state(state);
}
```

This function runs when the switch is toggled. It enforces protocol modes on the ESP32 at runtime.

---

## 🧪 Behavior

| Switch State | Wi-Fi Mode | Bitrate | Notes |
|--------------|------------|---------|-------|
| ON           | 802.11b/g  | ~54 Mbps | May trigger API disconnect |
| OFF          | b/g/n      | Up to 72 Mbps | Normal operation |

ESPHome automatically re-establishes connection after protocol toggling.

---

## 🧠 Optional Enhancements

- Call `esp_wifi_disconnect()` → `set_protocol()` → `esp_wifi_connect()` for smoother transitions
- Use `esp_wifi_get_protocol()` to confirm current mode
- Auto reboot after toggling if stability is critical

---

## 🛠 Requirements

- ESP32 board
- ESPHome 2025.7.2+
- GitHub-hosted external_components structure

---

## 🙌 Credits

Created with ❤️ by [@donannie](https://github.com/donannie). Contributions, issues, and pull requests welcome!

---

## 📄 License

[MIT](LICENSE)

