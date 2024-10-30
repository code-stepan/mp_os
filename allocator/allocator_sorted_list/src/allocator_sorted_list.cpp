#include <not_implemented.h>
#include <mutex>
#include <exception>

#include "../include/allocator_sorted_list.h"

allocator_sorted_list::~allocator_sorted_list()
{
}

allocator_sorted_list::allocator_sorted_list(
    allocator_sorted_list const &other)
{
}

allocator_sorted_list &allocator_sorted_list::operator=(
    allocator_sorted_list const &other)
{
}

allocator_sorted_list::allocator_sorted_list(
    allocator_sorted_list &&other) noexcept
{
}

allocator_sorted_list &allocator_sorted_list::operator=(
    allocator_sorted_list &&other) noexcept
{
}

allocator_sorted_list::allocator_sorted_list(
    size_t space_size,
    allocator *parent_allocator,
    logger *logger,
    allocator_with_fit_mode::fit_mode allocate_fit_mode)
{
}

[[nodiscard]] void *allocator_sorted_list::allocate(
    size_t value_size,
    size_t values_count)
{
}

void allocator_sorted_list::deallocate(
    void *at)
{
}

inline void allocator_sorted_list::set_fit_mode(
    allocator_with_fit_mode::fit_mode mode)
{
}

inline allocator *allocator_sorted_list::get_allocator() const
{
}

std::vector<allocator_test_utils::block_info> allocator_sorted_list::get_blocks_info() const noexcept
{
}

inline logger *allocator_sorted_list::get_logger() const
{
}

inline std::string allocator_sorted_list::get_typename() const noexcept
{
}