template< typename T > struct Initializer {
    T t;
    Initializer()
    :t() // ====> default construction, works for classes _and_ built-in
    {}
};