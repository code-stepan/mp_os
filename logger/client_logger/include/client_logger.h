#ifndef MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H
#define MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H

#include <logger.h>
#include <map>
#include <fstream>
#include <memory>

#include "client_logger_builder.h"

class client_logger final:
    public logger
{
private:

    std::string log_format_;
    std::map<std::shared_ptr<std::ostream>, severity> streams_;

public:

    client_logger(std::string log_format, std::map<std::shared_ptr<std::ostream>, severity> streams);

    client_logger(
        client_logger const &other);

    client_logger &operator=(
        client_logger const &other);

    client_logger(
        client_logger &&other) noexcept;

    client_logger &operator=(
        client_logger &&other) noexcept;

    ~client_logger() noexcept final;

public:

    [[nodiscard]] logger const *log(
        const std::string &message,
        logger::severity severity) const noexcept override;

};

#endif //MATH_PRACTICE_AND_OPERATING_SYSTEMS_CLIENT_LOGGER_H