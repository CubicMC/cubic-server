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
    void setTpsGlobal(double tps)
    {
        if (_ready)
            _tps_global_gauge->Set(tps);
    }
    void setTpsOverworld(double tps)
    {
        if (_ready)
            _tps_overworld_gauge->Set(tps);
    }
    void setTpsNether(double tps)
    {
        if (_ready)
            _tps_nether_gauge->Set(tps);
    }
    void setTpsEnd(double tps)
    {
        if (_ready)
            _tps_end_gauge->Set(tps);
    }
    void setMsptGlobal(double mspt)
    {
        if (_ready)
            _mspt_global_gauge->Set(mspt);
    }
    void setMsptOverworld(double mspt)
    {
        if (_ready)
            _mspt_overworld_gauge->Set(mspt);
    }
    void setMsptNether(double mspt)
    {
        if (_ready)
            _mspt_nether_gauge->Set(mspt);
    }
    void setMsptEnd(double mspt)
    {
        if (_ready)
            _mspt_end_gauge->Set(mspt);
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

    prometheus::Gauge *_tps_global_gauge;
    prometheus::Gauge *_tps_overworld_gauge;
    prometheus::Gauge *_tps_nether_gauge;
    prometheus::Gauge *_tps_end_gauge;

    prometheus::Gauge *_mspt_global_gauge;
    prometheus::Gauge *_mspt_overworld_gauge;
    prometheus::Gauge *_mspt_nether_gauge;
    prometheus::Gauge *_mspt_end_gauge;

    std::atomic<bool> _ready;
};

#endif /* D5AEBC4C_6028_4506_86F2_DA6261F54832 */
