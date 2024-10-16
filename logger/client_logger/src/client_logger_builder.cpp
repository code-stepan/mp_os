#include <not_implemented.h>

#include "../include/client_logger_builder.h"

client_logger_builder::client_logger_builder()
{
}

client_logger_builder::client_logger_builder(
    client_logger_builder const &other)
{
}

client_logger_builder &client_logger_builder::operator=(
    client_logger_builder const &other)
{
}

client_logger_builder::client_logger_builder(
    client_logger_builder &&other) noexcept
{
}

client_logger_builder &client_logger_builder::operator=(
    client_logger_builder &&other) noexcept
{
}

client_logger_builder::~client_logger_builder() noexcept
{
}

logger_builder *client_logger_builder::add_file_stream(
    std::string const &stream_file_path,
    logger::severity severity)
{
    auto file_stream = std::make_shared<std::ofstream>(stream_file_path);
    if (file_stream->is_open()) {
        streams_[file_stream] = severity;
    } else {
        std::cerr << "Error opening file : " << stream_file_path << std::endl;
    }

    return this;
}

logger_builder *client_logger_builder::add_console_stream(
    logger::severity severity)
{
    streams_[std::make_shared<std::ostream>(std::cerr.rdbuf())] = severity;
    return this;
}

logger_builder* client_logger_builder::transform_with_configuration(
    std::string const &configuration_file_path,
    std::string const &configuration_path)
{
    // TODO
    return this;
}

logger_builder *client_logger_builder::clear()
{
    streams_.clear();
    return this;
}

logger *client_logger_builder::build() const
{
    return new client_logger(log_format_, streams_);
}