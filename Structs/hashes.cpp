struct pair_hash final {
    template<class T1, class T2>
    size_t operator()(const std::pair<T1, T2>& p) const noexcept {
        uintmax_t h = std::hash<T1>{}(p.first);
        
        h <<= sizeof(uintmax_t) * 4;
        h ^= std::hash<T2>{}(p.second);
        return std::hash<uintmax_t>{}(h);
    }
};
