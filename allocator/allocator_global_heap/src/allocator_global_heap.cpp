#include <not_implemented.h>

#include "../include/allocator_global_heap.h"

allocator_global_heap::allocator_global_heap(
    logger *logger) : _logger(logger) {}

allocator_global_heap::~allocator_global_heap() = default;

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
    size_t total_size = values_count * value_size;
    try {
        void *ptr = ::operator new(total_size);
        return ptr;
    } catch (const std::bad_alloc &) {
        throw std::bad_alloc();
    }
}

void allocator_global_heap::deallocate(
    void *at)
{
    if (at == nullptr) {
        return;
    }

    ::operator delete(at);

}

inline logger *allocator_global_heap::get_logger() const
{
    return _logger;
}

inline std::string allocator_global_heap::get_typename() const noexcept
{
}