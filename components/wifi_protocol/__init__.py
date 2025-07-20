import esphome.codegen as cg
import esphome.config_validation as cv

wifi_protocol_ns = cg.esphome_ns.namespace("wifi_protocol")
WiFiProtocolComponent = wifi_protocol_ns.class_("WiFiProtocolComponent", cg.Component)

CONFIG_SCHEMA = cv.Schema({}).extend({})

async def to_code(config):
    var = cg.new_Pvariable("wifi_protocol_component", WiFiProtocolComponent())
    await cg.register_component(var, config)
