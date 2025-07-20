import esphome.codegen as cg
import esphome.config_validation as cv

wifi_protocol_ns = cg.esphome_ns.namespace("wifi_protocol")
WiFiProtocolComponent = wifi_protocol_ns.class_("WiFiProtocolComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(WiFiProtocolComponent),
})

async def to_code(config):
    var = cg.new_Pvariable(config[cg.CONF_ID])
    await cg.register_component(var, config)
