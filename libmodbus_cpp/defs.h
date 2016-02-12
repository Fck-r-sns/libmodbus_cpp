#ifndef LIBMODBUS_CPP_DEFS_H
#define LIBMODBUS_CPP_DEFS_H

#include <stdexcept>
#include <modbus/modbus.h>
#include <functional>
#include <QByteArray>

namespace libmodbus_cpp {

enum class ByteOrder {
    LittleEndian,
    BigEndian
};

enum class Mode {
    Master,
    Slave
};

enum class Type {
    TCP,
    RTU
};

enum class DataType {
    Coil,
    DiscreteInput,
    HoldingRegister,
    InputRegister
};

struct RawResult {
    uint8_t address;
    uint8_t functionCode;
    QByteArray data;

    bool isError() {
        return (functionCode & 0x80);
    }
};

// hooks ===================================================================
using FunctionCode = uint8_t;
using Address = uint16_t;
using HookFunction = std::function<void(void)>;

// exceptions ==============================================================
using RemoteRWError = std::runtime_error;

class RemoteReadError : public RemoteRWError {
public:
    RemoteReadError(const std::string &msg) : RemoteRWError(msg) {}
};

class RemoteWriteError : public RemoteRWError {
public:
    RemoteWriteError(const std::string &msg) : RemoteRWError(msg) {}
};

using LocalRWError = std::logic_error;

class LocalReadError : public LocalRWError {
public:
    LocalReadError(const std::string &msg) : LocalRWError(msg) {}
};

class LocalWriteError : public LocalRWError {
public:
    LocalWriteError(const std::string &msg) : LocalRWError(msg) {}
};
// =========================================================================

}

#endif // LIBMODBUS_CPP_DEFS_H
