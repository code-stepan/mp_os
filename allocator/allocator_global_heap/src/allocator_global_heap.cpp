#include <not_implemented.h>

#include "../include/allocator_global_heap.h"

allocator_global_heap::allocator_global_heap(
    logger *logger) : _logger(logger) {
    if (_logger) _logger->log("Initializing allocator_global_heap", logger::severity::debug);
}

allocator_global_heap::~allocator_global_heap() {
    if (_logger) _logger->log("Allocator_global_heap destroyed", logger::severity::debug);
}

allocator_global_heap::allocator_global_heap(
    allocator_global_heap &&other) noexcept
    : _logger(other._logger)
{
    other._logger = nullptr;
}

allocator_global_heap &allocator_global_heap::operator=(
    allocator_global_heap &&other) noexcept
{
    if (this != &other) {
        _logger = other._logger;
        other._logger = nullptr;
    }

    return *this;
}

[[nodiscard]] void *allocator_global_heap::allocate(
    size_t value_size,
    size_t values_count)
{
    if (_logger) _logger->log("Memory allocation request", logger::severity::debug);

    size_t total_size = values_count * value_size;
    try {
        void *ptr = ::operator new(total_size);
        if (_logger) _logger->log("Memory allocated", logger::severity::debug);
        return ptr;
    } catch (const std::bad_alloc &) {
        if (_logger) _logger->log("Memory allocation error", logger::severity::error);
        throw std::bad_alloc();
    }
}

void allocator_global_heap::deallocate(
    void *at)
{
    if (_logger) _logger->log("Memory deallocate", logger::severity::debug);

    if (at == nullptr) {
        if (_logger) _logger->log("Attempt to free a null pointer", logger::severity::warning);
        return;
    }

    ::operator delete(at);
    if (_logger) _logger->log("Memory deallocated", logger::severity::debug);
}

inline logger *allocator_global_heap::get_logger() const
{
    if (_logger) _logger->log("Method called get_logger()", logger::severity::debug);
    return _logger;
}

inline std::string allocator_global_heap::get_typename() const noexcept
{
    if (_logger) _logger->log("Method called get_typename()", logger::severity::debug);
    return "allocator_global_heap";
}