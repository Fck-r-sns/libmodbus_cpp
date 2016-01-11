#ifndef SLAVE_TCP_H
#define SLAVE_TCP_H

#include <QTcpServer>
#include <QSet>
#include <QTcpSocket>
#include "abstract_slave.h"
#include "slave_tcp_backend.h"

namespace libmodbus_cpp {

class SlaveTcp : public AbstractSlave
{
    Q_OBJECT

public:
    SlaveTcp(SlaveTcpBackend *backend);
    ~SlaveTcp();

protected:
    inline SlaveTcpBackend *getBackend() override {
        return static_cast<SlaveTcpBackend*>(AbstractSlave::getBackend());
    }
};

}

#endif // SLAVE_TCP_H
