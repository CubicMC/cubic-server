#ifndef D5AEBC4C_6028_4506_86F2_DA6261F54832
#define D5AEBC4C_6028_4506_86F2_DA6261F54832

#include <memory>
#include <string>

#include "prometheus/exposer.h"
#include "prometheus/registry.h"

class PrometheusExporter {
public:
    PrometheusExporter(const std::string &bind);
    void registerMetrics();

private:
    prometheus::Exposer _exposer;
    std::shared_ptr<prometheus::Registry> _registry;
};

#endif /* D5AEBC4C_6028_4506_86F2_DA6261F54832 */
