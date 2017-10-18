In std::stack the behaviour is undefined if element type is not the same type as Container::value_type.
e.g. std::stack<A, Container<B> >

In the current implementation you can't declare different types, as your template arguments are
  - element type
  - container type
  - other arguments for container
e.g. local::stack<A, Container> or local::stack<A, Container, args...>
