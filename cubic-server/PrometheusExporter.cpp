#include <memory>

#include <prometheus/counter.h>
#include <prometheus/gauge.h>
#include <prometheus/info.h>
#include <prometheus/registry.h>

#include "PrometheusExporter.hpp"
#include "options.hpp"

PrometheusExporter::PrometheusExporter(const std::string &bind):
    _exposer(bind),
    _ready(false)
{
}

void PrometheusExporter::registerMetrics()
{
    _registry = std::make_shared<prometheus::Registry>();

    // clang-format off
    auto &packet_counter = prometheus::BuildCounter()
        .Name("observed_packets_total")
        .Help("Number of observed packets")
        .Register(*_registry);
    // clang-format on
    _packet_rx_counter = &packet_counter.Add({{"direction", "rx"}});
    _packet_tx_counter = &packet_counter.Add({{"direction", "tx"}});

    // clang-format off
    auto& version_info = prometheus::BuildInfo()
        .Name("versions")
        .Help("Static info about the server")
        .Register(*_registry);
    // clang-format on
    _version_info = &version_info.Add({{PROGRAM_NAME, PROGRAM_VERSION}});

    // clang-format off
    auto &player_gauge = prometheus::BuildGauge()
        .Name("player_count")
        .Help("Number of players connected")
        .Register(*_registry);
    // clang-format on
    _player_global_gauge = &player_gauge.Add({{"dimension", "global"}});
    _player_overworld_gauge = &player_gauge.Add({{"dimension", "overworld"}});
    _player_nether_gauge = &player_gauge.Add({{"dimension", "nether"}});
    _player_end_gauge = &player_gauge.Add({{"dimension", "end"}});

    // clang-format off
    auto &tps_gauge = prometheus::BuildGauge()
        .Name("one_minute_tps")
        .Help("Server one minute TPS")
        .Register(*_registry);
    // clang-format on
    _tps_global_gauge = &tps_gauge.Add({{"dimension", "global"}});
    _tps_overworld_gauge = &tps_gauge.Add({{"dimension", "overworld"}});
    _tps_nether_gauge = &tps_gauge.Add({{"dimension", "nether"}});
    _tps_end_gauge = &tps_gauge.Add({{"dimension", "end"}});

    // clang-format off
    auto &mspt_gauge = prometheus::BuildGauge()
        .Name("mean_mspt")
        .Help("Server mean MSPT")
        .Register(*_registry);
    // clang-format on
    _mspt_global_gauge = &mspt_gauge.Add({{"dimension", "global"}});
    _mspt_overworld_gauge = &mspt_gauge.Add({{"dimension", "overworld"}});
    _mspt_nether_gauge = &mspt_gauge.Add({{"dimension", "nether"}});
    _mspt_end_gauge = &mspt_gauge.Add({{"dimension", "end"}});

    _exposer.RegisterCollectable(_registry);

    _ready = true;
}
