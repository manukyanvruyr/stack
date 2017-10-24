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

	template <typename ... Arguments>
	explicit stack(Arguments&&... args) : m_container(std::forward<Arguments...>(args...))
	{}

	stack(const stack& other) = default;
	stack(stack&& other) = default;

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
