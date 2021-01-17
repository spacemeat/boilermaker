// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.


template <>
struct hu::val<std::vector<testCompare::achievement>>
{
    static inline std::vector<testCompare::achievement> extract(hu::Node const & node) noexcept
    {
        std::vector<testCompare::achievement> rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {
            rv.emplace_back(std::move(node / i % hu::val<testCompare::achievement>{}));
        }
        return rv;
    }
};


testCompare::user::user(hu::Node node) noexcept
: id(node / "id" % hu::val<int>{}), 
  username(node / "username" % hu::val<std::string>{}), 
  lastLoggedIn(node / "lastLoggedIn" % hu::val<long long>{}), 
  lastTitlePlayed(node / "lastTitlePlayed" % hu::val<int>{}), 
  achievements(node / "achievements" % hu::val<std::vector<testCompare::achievement>>{}), 
  metatags(node / "metatags" % hu::val<std::unordered_map<std::string, std::string>>{})
{
    
}


testCompare::user::user(testCompare::user const & rhs) noexcept
: id(rhs.id), 
  username(rhs.username), 
  lastLoggedIn(rhs.lastLoggedIn), 
  lastTitlePlayed(rhs.lastTitlePlayed), 
  achievements(rhs.achievements), 
  metatags(rhs.metatags)
{
    
}


testCompare::user & testCompare::user::operator =(testCompare::user rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::user::user(testCompare::user && rhs) noexcept
: id(std::move(rhs.id)), 
  username(std::move(rhs.username)), 
  lastLoggedIn(std::move(rhs.lastLoggedIn)), 
  lastTitlePlayed(std::move(rhs.lastTitlePlayed)), 
  achievements(std::move(rhs.achievements)), 
  metatags(std::move(rhs.metatags))
{
    
}


testCompare::user & testCompare::user::operator =(testCompare::user && rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::user::~user()
{
    
}


void testCompare::swap(testCompare::user & lhs, testCompare::user & rhs) noexcept
{
    using std::swap;
    swap(lhs.id, rhs.id);
    swap(lhs.username, rhs.username);
    swap(lhs.lastLoggedIn, rhs.lastLoggedIn);
    swap(lhs.lastTitlePlayed, rhs.lastTitlePlayed);
    swap(lhs.achievements, rhs.achievements);
    swap(lhs.metatags, rhs.metatags);
}


int const & testCompare::user::get_id() const noexcept
{
    return id;
}


int & testCompare::user::get_id() noexcept
{
    return id;
}


std::string const & testCompare::user::get_username() const noexcept
{
    return username;
}


std::string & testCompare::user::get_username() noexcept
{
    return username;
}


long long const & testCompare::user::get_lastLoggedIn() const noexcept
{
    return lastLoggedIn;
}


long long & testCompare::user::get_lastLoggedIn() noexcept
{
    return lastLoggedIn;
}


int const & testCompare::user::get_lastTitlePlayed() const noexcept
{
    return lastTitlePlayed;
}


int & testCompare::user::get_lastTitlePlayed() noexcept
{
    return lastTitlePlayed;
}


std::vector<testCompare::achievement> const & testCompare::user::get_achievements() const noexcept
{
    return achievements;
}


std::vector<testCompare::achievement> & testCompare::user::get_achievements() noexcept
{
    return achievements;
}


std::unordered_map<std::string, std::string> const & testCompare::user::get_metatags() const noexcept
{
    return metatags;
}


std::unordered_map<std::string, std::string> & testCompare::user::get_metatags() noexcept
{
    return metatags;
}


std::ostream & testCompare::operator <<(std::ostream & out, testCompare::user const & obj) noexcept
{
    out << '{';
    out << " id: " << obj.id;
    out << " username: " << obj.username;
    out << " lastLoggedIn: " << obj.lastLoggedIn;
    out << " lastTitlePlayed: " << obj.lastTitlePlayed;
    out << " achievements: " << obj.achievements;
    out << " metatags: " << obj.metatags;
    out << '}';
    return out;
}


bool testCompare::operator ==(testCompare::user const & lhs, testCompare::user const & rhs) noexcept
{
    return lhs.id == rhs.id
        && lhs.username == rhs.username
        && lhs.lastLoggedIn == rhs.lastLoggedIn
        && lhs.lastTitlePlayed == rhs.lastTitlePlayed
        && lhs.achievements == rhs.achievements
        && lhs.metatags == rhs.metatags;
}


bool testCompare::operator !=(testCompare::user const & lhs, testCompare::user const & rhs) noexcept
{
    return !(lhs == rhs);
}


testCompare::user_diff::user_diff(testCompare::user const & lhs, testCompare::user const & rhs) noexcept
: diffs((lhs.id != rhs.id) << 0 |
        (lhs.username != rhs.username) << 1 |
        (lhs.lastLoggedIn != rhs.lastLoggedIn) << 2 |
        (lhs.lastTitlePlayed != rhs.lastTitlePlayed) << 3 |
        (lhs.achievements != rhs.achievements) << 4 |
        (lhs.metatags != rhs.metatags) << 5),
  achievements_diffs(lhs.achievements, rhs.achievements),
  metatags_diffs(lhs.metatags, rhs.metatags)            
{
}

/*
testCompare::user_diff testCompare::getDiff(testCompare::user const & lhs, user const & rhs) noexcept
{
    return testCompare::user_diff {
        (lhs.id != rhs.id) << 0 |
        (lhs.username != rhs.username) << 1 |
        (lhs.lastLoggedIn != rhs.lastLoggedIn) << 2 |
        (lhs.lastTitlePlayed != rhs.lastTitlePlayed) << 3 |
        (lhs.achievements != rhs.achievements) << 4 |
        (lhs.metatags != rhs.metatags) << 5,
        testCompare::vector_diff<achievement, achievement_diff> { lhs.achievements, rhs.achievements },
        testCompare::unordered_map_diff<std::string, std::string, buildIn_diff<std::string>> { lhs.metatags, rhs.metatags }
    };
}
*/
