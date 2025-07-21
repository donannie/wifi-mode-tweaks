import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID
from esphome.components import switch  # ✅ Import switch module properly

wifi_protocol_ns = cg.esphome_ns.namespace("wifi_protocol")
WiFiProtocolComponent = wifi_protocol_ns.class_(
    "WiFiProtocolComponent", cg.Component, switch.Switch  # ✅ Extend Switch correctly
)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(WiFiProtocolComponent),
})

async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await switch.register_switch(var, config)  # ✅ Register as a switch
