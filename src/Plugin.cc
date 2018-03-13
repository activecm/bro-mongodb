
#include "Plugin.h"
#include "MongoDBWriterBackend.h"
#include "Version.h"

namespace plugin { namespace OCMDev_MongoDBWriter { Plugin plugin; }}

using namespace plugin::OCMDev_MongoDBWriter;


plugin::Configuration Plugin::Configure() {
    AddComponent(new ::logging::Component("Mongodb", MongoDBWriterBackend::Instantiate));
    plugin::Configuration config;
    config.name = PLUGIN_NAME;
    config.description = "Bro IDS/Mongodb connector";
    config.version.major = PLUGIN_MAJOR;
    config.version.minor = PLUGIN_MINOR;
    return config;
}
