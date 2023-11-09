#include <memory>

#include <prometheus/counter.h>
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

    // Just an example of what you can put here
    // To add anything else to the metrics follow the readme of prometheus-cpp:
    // https://github.com/jupp0r/prometheus-cpp/blob/master/README.md
    // clang-format off
    auto &packet_counter = prometheus::BuildCounter()
        .Name("observed_packets_total")
        .Help("Number of observed packets")
        .Register(*_registry);
    // clang-format on

    _packet_rx_counter = &packet_counter.Add({{"direction", "rx"}});
    _packet_tx_counter = &packet_counter.Add({{"direction", "tx"}});

    _exposer.RegisterCollectable(_registry);

    _ready = true;
}
