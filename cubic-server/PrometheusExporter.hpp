#ifndef D5AEBC4C_6028_4506_86F2_DA6261F54832
#define D5AEBC4C_6028_4506_86F2_DA6261F54832

#include <memory>
#include <string>

#include "prometheus/counter.h"
#include "prometheus/exposer.h"
#include "prometheus/registry.h"

class PrometheusExporter {
public:
    PrometheusExporter(const std::string &bind);
    void registerMetrics();
    void incrementPacketRxCounter()
    {
        if (_ready)
            _packet_rx_counter->Increment();
    }
    void incrementPacketTxCounter()
    {
        if (_ready)
            _packet_tx_counter->Increment();
    }

private:
    prometheus::Exposer _exposer;
    std::shared_ptr<prometheus::Registry> _registry;

    prometheus::Counter *_packet_tx_counter;
    prometheus::Counter *_packet_rx_counter;

    bool _ready;
};

#endif /* D5AEBC4C_6028_4506_86F2_DA6261F54832 */
