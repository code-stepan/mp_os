#include <not_implemented.h>

#include <utility>

#include "../include/client_logger.h"

client_logger::client_logger(std::string log_format, std::map<std::shared_ptr<std::ostream>, severity> streams)
    : log_format_(std::move(log_format)), streams_(std::move(streams))
{

}

client_logger::client_logger(
    client_logger const &other)
{
}

client_logger &client_logger::operator=(
    client_logger const &other)
{
}

client_logger::client_logger(
    client_logger &&other) noexcept
{
}

client_logger &client_logger::operator=(
    client_logger &&other) noexcept
{
}

client_logger::~client_logger() noexcept
{
}

logger const *client_logger::log(
    const std::string &message,
    logger::severity severity) const noexcept
{
    for (const auto & pair : streams_)
    {
        if (severity >= pair.second)
        {
            (*pair.first) << message << std::endl;
        }
    }

    return this;
}