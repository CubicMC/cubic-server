#include <memory>

#include <prometheus/counter.h>
#include <prometheus/registry.h>

#include "PrometheusExporter.hpp"
#include "options.hpp"

PrometheusExporter::PrometheusExporter(const std::string &bind):
    _exposer(bind)
{
}

void PrometheusExporter::registerMetrics()
{
    _registry = std::make_shared<prometheus::Registry>();

    // Just an example of what you can put here
    // To add anything else to the metrics follow the readme of prometheus-cpp:
    // https://github.com/jupp0r/prometheus-cpp/blob/master/README.md
    // clang-format off
    UNUSED auto &packet_counter = prometheus::BuildCounter()
        .Name("observed_packets_total")
        .Help("Number of observed packets")
        .Register(*_registry);
    // clang-format on

    _exposer.RegisterCollectable(_registry);
}
