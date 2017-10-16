#pragma once

#include <deque>

namespace local
{

template <typename T, template <typename ...> class container = std::deque, typename ... Args>
class stack
{
public:
	using container_type = container<T, Args...>;
	using value_type = typename container_type::value_type;
	using reference = typename container_type::reference;
	using const_reference = typename container_type::const_reference;
	using size_type = typename container_type::size_type;

public:
	explicit stack(const container_type& cont) : m_container(cont)
	{}

	explicit stack(container_type&& cont = container_type()) : m_container(std::move(cont))
	{}

	stack(const stack& other) = default;
	stack(stack&& other) = default;

	template <typename Alloc>
	explicit stack(const Alloc& alloc) : m_container(alloc)
	{}

	template <typename Alloc>
	stack(const container_type& cont, const Alloc& alloc) : m_container(cont, alloc)
	{}

	template <typename Alloc>
	stack(const stack& other, const Alloc& alloc) : m_container(other.m_container, alloc)
	{}

	template <typename Alloc>
	stack(stack&& other, const Alloc& alloc) : m_container(std::move(other.m_container), alloc)
	{}

public:
	reference top()
	{
	    return m_container.back();
	}

	const_reference top() const
	{
	    return m_container.back();
	}

	bool empty() const
	{
	    return m_container.empty();
	}

	size_type size() const
	{
	    return m_container.size();
	}

	void push(const value_type& value)
	{
	    m_container.push_back(value);
	}

	void push(value_type&& value)
	{
	    m_container.push_back(std::move(value));
	}

	template <typename ... Arguments>
	void emplace(Arguments&& ... args)
	{
	    m_container.emplace_back(std::forward<Arguments...>(args...));
	}

	void pop()
	{
	    m_container.pop_back();
	}

	void swap(stack& other) noexcept
	{
	    std::swap(m_container, other);
	}

private:
	container_type m_container;
};

}
