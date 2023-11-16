#ifndef D5AEBC4C_6028_4506_86F2_DA6261F54832
#define D5AEBC4C_6028_4506_86F2_DA6261F54832

#include <memory>
#include <string>

#include "prometheus/counter.h"
#include "prometheus/exposer.h"
#include "prometheus/registry.h"
#include "prometheus/summary.h"

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
    void setPlayerCountGlobal(size_t n)
    {
        if (_ready)
            _player_global_gauge->Set(n);
    }
    void setPlayerCountOverworld(size_t n)
    {
        if (_ready)
            _player_overworld_gauge->Set(n);
    }
    void setPlayerCountNether(size_t n)
    {
        if (_ready)
            _player_nether_gauge->Set(n);
    }
    void setPlayerCountEnd(size_t n)
    {
        if (_ready)
            _player_end_gauge->Set(n);
    }
    void incrementPlayerCountGlobal()
    {
        if (_ready)
            _player_global_gauge->Increment();
    }
    void incrementPlayerCountOverworld()
    {
        if (_ready)
            _player_overworld_gauge->Increment();
    }
    void incrementPlayerCountNether()
    {
        if (_ready)
            _player_nether_gauge->Increment();
    }
    void incrementPlayerCountEnd()
    {
        if (_ready)
            _player_end_gauge->Increment();
    }
    void decrementPlayerCountGlobal()
    {
        if (_ready)
            _player_global_gauge->Decrement();
    }
    void decrementPlayerCountOverworld()
    {
        if (_ready)
            _player_overworld_gauge->Decrement();
    }
    void decrementPlayerCountNether()
    {
        if (_ready)
            _player_nether_gauge->Decrement();
    }
    void decrementPlayerCountEnd()
    {
        if (_ready)
            _player_end_gauge->Decrement();
    }
    void addTpsOverworld(double tps)
    {
        if (_ready)
            _tps_overworld_summary->Observe(tps);
    }
    void addTpsNether(double tps)
    {
        if (_ready)
            _tps_nether_summary->Observe(tps);
    }
    void addTpsEnd(double tps)
    {
        if (_ready)
            _tps_end_summary->Observe(tps);
    }
    void addMsptOverworld(double mspt)
    {
        if (_ready)
            _mspt_overworld_summary->Observe(mspt);
    }
    void addMsptNether(double mspt)
    {
        if (_ready)
            _mspt_nether_summary->Observe(mspt);
    }
    void addMsptEnd(double mspt)
    {
        if (_ready)
            _mspt_end_summary->Observe(mspt);
    }

private:
    prometheus::Exposer _exposer;
    std::shared_ptr<prometheus::Registry> _registry;

    prometheus::Counter *_packet_tx_counter;
    prometheus::Counter *_packet_rx_counter;

    prometheus::Info *_version_info; // This is not dynamic yet, but it can be in the future

    prometheus::Gauge *_player_global_gauge;
    prometheus::Gauge *_player_overworld_gauge;
    prometheus::Gauge *_player_nether_gauge;
    prometheus::Gauge *_player_end_gauge;

    prometheus::Summary *_tps_overworld_summary;
    prometheus::Summary *_tps_nether_summary;
    prometheus::Summary *_tps_end_summary;

    prometheus::Summary *_mspt_overworld_summary;
    prometheus::Summary *_mspt_nether_summary;
    prometheus::Summary *_mspt_end_summary;

    std::atomic<bool> _ready;
};

#endif /* D5AEBC4C_6028_4506_86F2_DA6261F54832 */
