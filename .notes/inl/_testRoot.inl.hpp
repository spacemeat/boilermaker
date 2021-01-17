// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.


template <>
struct hu::val<std::vector<int>>
{
    static inline std::vector<int> extract(hu::Node const & node) noexcept
    {
        std::vector<int> rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % hu::val<int>{}));
        }
        return rv;
    }
};


template <>
struct hu::val<std::array<std::vector<int>, 4>>
{
    static inline std::array<std::vector<int>, 4> extract(hu::Node const & node) noexcept
    {
        return std::array<std::vector<int>, 4> {
            std::move(hu::val<std::vector<int>>::extract(node / 0)),
            std::move(hu::val<std::vector<int>>::extract(node / 1)),
            std::move(hu::val<std::vector<int>>::extract(node / 2)),
            std::move(hu::val<std::vector<int>>::extract(node / 3))
        };
    }
};


template <>
struct hu::val<std::vector<testCompare::user>>
{
    static inline std::vector<testCompare::user> extract(hu::Node const & node) noexcept
    {
        std::vector<testCompare::user> rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % hu::val<testCompare::user>{}));
        }
        return rv;
    }
};


testCompare::testRoot::testRoot(hu::Node node) noexcept
: v_of_ints(node / "v_of_ints" % hu::val<std::vector<int>>{}), 
  a_of_v_of_ints(node / "a_of_v_of_ints" % hu::val<std::array<std::vector<int>, 4>>{}), 
  users(node / "users" % hu::val<std::vector<testCompare::user>>{})
{
    
}


testCompare::testRoot::testRoot(testCompare::testRoot const & rhs) noexcept
: v_of_ints(rhs.v_of_ints), 
  a_of_v_of_ints(rhs.a_of_v_of_ints), 
  users(rhs.users)
{
    
}


testCompare::testRoot & testCompare::testRoot::operator =(testCompare::testRoot rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::testRoot::testRoot(testCompare::testRoot && rhs) noexcept
: v_of_ints(std::move(rhs.v_of_ints)), 
  a_of_v_of_ints(std::move(rhs.a_of_v_of_ints)), 
  users(std::move(rhs.users))
{
    
}


testCompare::testRoot & testCompare::testRoot::operator =(testCompare::testRoot && rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::testRoot::~testRoot()
{
    
}


void testCompare::swap(testCompare::testRoot & lhs, testCompare::testRoot & rhs) noexcept
{
    using std::swap;
    swap(lhs.v_of_ints, rhs.v_of_ints);
    swap(lhs.a_of_v_of_ints, rhs.a_of_v_of_ints);
    swap(lhs.users, rhs.users);
}


std::vector<int> const & testCompare::testRoot::get_v_of_ints() const noexcept
{
    return v_of_ints;
}


std::vector<int> & testCompare::testRoot::get_v_of_ints() noexcept
{
    return v_of_ints;
}


std::array<std::vector<int>, 4> const & testCompare::testRoot::get_a_of_v_of_ints() const noexcept
{
    return a_of_v_of_ints;
}


std::array<std::vector<int>, 4> & testCompare::testRoot::get_a_of_v_of_ints() noexcept
{
    return a_of_v_of_ints;
}


std::vector<testCompare::user> const & testCompare::testRoot::get_users() const noexcept
{
    return users;
}


std::vector<testCompare::user> & testCompare::testRoot::get_users() noexcept
{
    return users;
}


std::ostream & testCompare::operator <<(std::ostream & out, testCompare::testRoot const & obj) noexcept
{
    out << '{';
    out << " v_of_ints: " << obj.v_of_ints;
    out << " a_of_v_of_ints: " << obj.a_of_v_of_ints;
    out << " users: " << obj.users;
    out << '}';
    return out;
}


bool testCompare::operator ==(testCompare::testRoot const & lhs, testCompare::testRoot const & rhs) noexcept
{
    return lhs.v_of_ints == rhs.v_of_ints
        && lhs.a_of_v_of_ints == rhs.a_of_v_of_ints
        && lhs.users == rhs.users;
}


bool testCompare::operator !=(testCompare::testRoot const & lhs, testCompare::testRoot const & rhs) noexcept
{
    return !(lhs == rhs);
}


testCompare::testRoot_diff::testRoot_diff(testCompare::testRoot const & lhs, testCompare::testRoot const & rhs) noexcept
: diffs((lhs.v_of_ints != rhs.v_of_ints) << 0 |
        (lhs.a_of_v_of_ints != rhs.a_of_v_of_ints) << 1 |
        (lhs.users != rhs.users) << 2),
  v_of_ints_diffs(lhs.v_of_ints, rhs.v_of_ints),
  a_of_v_of_ints_diffs(lhs.a_of_v_of_ints, rhs.a_of_v_of_ints),
  users_diffs(lhs.users, rhs.users)
{
}

/*
testCompare::testRoot_diff testCompare::getDiff(testCompare::testRoot const & lhs, testRoot const & rhs) noexcept
{
    return testCompare::testRoot_diff {
        (lhs.v_of_ints != rhs.v_of_ints) << 0 |
        (lhs.a_of_v_of_ints != rhs.a_of_v_of_ints) << 1 |
        (lhs.users != rhs.users) << 2,
        testCompare::vector_diff<int, buildIn_diff<int>> { lhs.v_of_ints, rhs.v_of_ints },
        testCompare::array_diff<std::vector<int>, 4, vector_diff<int, buildIn_diff<int>>> { lhs.a_of_v_of_ints, rhs.a_of_v_of_ints },
        testCompare::vector_diff<testCompare::user, user_diff> { lhs.users, rhs.users }
    };
}
*/
