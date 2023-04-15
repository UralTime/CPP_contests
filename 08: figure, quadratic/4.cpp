namespace Game
{
    template <typename value_type>
    struct Coord 
    {
        value_type row, col;
        Coord(): row{}, col{} {}
        Coord(value_type r): row{r}, col{} {}
        Coord(value_type r, value_type c): row{r}, col{c} {}
    };

    template <typename T> inline
    T abs(const T &v) { return v > 0 ? v : -v; }

    template <typename T> inline
    T relu(const T &v) { return v > 0 ? v : 0; }
        
    template <typename T> inline
    T min(const T &v, const T &u) { return (v < u) ? v : u; }
    
    template <typename value_type>
    value_type dist (const Coord<value_type> &field, 
            const Coord<value_type> &first, const Coord<value_type> &second)
    {
        value_type x1 = first.col, y1 = first.row, x2 = second.col, y2 = second.row;
        value_type parity_addendum = (((x1 < x2) == (y1 < y2)) ^ (min(x1, x2) & 1));
        value_type y_gain = (abs(x2 - x1) + parity_addendum) >> 1;
        return abs(x2 - x1) + relu(abs(y2 - y1) - y_gain);
    }
};