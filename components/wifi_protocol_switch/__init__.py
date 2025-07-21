import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID, CONF_NAME
from esphome.components import switch  # ✅ Pull in switch behavior

wifi_protocol_switch_ns = cg.esphome_ns.namespace("wifi_protocol_switch")

WiFiProtocolComponent = wifi_protocol_switch_ns.class_(

    "WiFiProtocolComponent", cg.Component, switch.Switch
)

CONFIG_SCHEMA = switch.SWITCH_SCHEMA.extend({
    cv.GenerateID(): cv.declare_id(WiFiProtocolComponent),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await switch.register_switch(var, config)
