// THIS IS A GENERATED FILE. It is a Boilermaker artifact.
// Do not bother modifying this file, as your build process will overwrite
// your changes.


template <>
struct hu::val<std::unordered_map<std::string, std::string>>
{
    static inline std::unordered_map<std::string, std::string> extract(hu::Node const & node) noexcept
    {
        std::unordered_map<std::string, std::string> rv;
        for (hu::size_t i = 0; i < node.numChildren(); ++i)
        {
            hu::Node elemNode = node / i;
            rv.emplace(std::move(hu::val<std::string>::extract(elemNode.key().str())),
                       std::move(elemNode % hu::val<std::string>{}));
        }
        return rv;
    }
};


testCompare::achievement::achievement(hu::Node node) noexcept
: titleId(node / "titleId" % hu::val<int>{}), 
  id(node / "id" % hu::val<int>{}), 
  when(node / "when" % hu::val<long long>{}), 
  timeToEarn(node / "timeToEarn" % hu::val<long long>{}), 
  metatags(node / "metatags" % hu::val<std::unordered_map<std::string, std::string>>{})
{
    
}


testCompare::achievement::achievement(testCompare::achievement const & rhs) noexcept
: titleId(rhs.titleId), 
  id(rhs.id), 
  when(rhs.when), 
  timeToEarn(rhs.timeToEarn), 
  metatags(rhs.metatags)
{
    
}


testCompare::achievement & testCompare::achievement::operator =(testCompare::achievement rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::achievement::achievement(testCompare::achievement && rhs) noexcept
: titleId(std::move(rhs.titleId)), 
  id(std::move(rhs.id)), 
  when(std::move(rhs.when)), 
  timeToEarn(std::move(rhs.timeToEarn)), 
  metatags(std::move(rhs.metatags))
{
    
}


testCompare::achievement & testCompare::achievement::operator =(testCompare::achievement && rhs) noexcept
{
    
    using std::swap;
    swap(*this, rhs);
    return *this;
}


testCompare::achievement::~achievement()
{
    
}


void testCompare::swap(testCompare::achievement & lhs, testCompare::achievement & rhs) noexcept
{
    using std::swap;
    swap(lhs.titleId, rhs.titleId);
    swap(lhs.id, rhs.id);
    swap(lhs.when, rhs.when);
    swap(lhs.timeToEarn, rhs.timeToEarn);
    swap(lhs.metatags, rhs.metatags);
}


int const & testCompare::achievement::get_titleId() const noexcept
{
    return titleId;
}


int & testCompare::achievement::get_titleId() noexcept
{
    return titleId;
}


int const & testCompare::achievement::get_id() const noexcept
{
    return id;
}


int & testCompare::achievement::get_id() noexcept
{
    return id;
}


long long const & testCompare::achievement::get_when() const noexcept
{
    return when;
}


long long & testCompare::achievement::get_when() noexcept
{
    return when;
}


long long const & testCompare::achievement::get_timeToEarn() const noexcept
{
    return timeToEarn;
}


long long & testCompare::achievement::get_timeToEarn() noexcept
{
    return timeToEarn;
}


std::unordered_map<std::string, std::string> const & testCompare::achievement::get_metatags() const noexcept
{
    return metatags;
}


std::unordered_map<std::string, std::string> & testCompare::achievement::get_metatags() noexcept
{
    return metatags;
}


std::ostream & testCompare::operator <<(std::ostream & out, testCompare::achievement const & obj) noexcept
{
    out << '{';
    out << " titleId: " << obj.titleId;
    out << " id: " << obj.id;
    out << " when: " << obj.when;
    out << " timeToEarn: " << obj.timeToEarn;
    out << " metatags: " << obj.metatags;
    out << '}';
    return out;
}


bool testCompare::operator ==(testCompare::achievement const & lhs, testCompare::achievement const & rhs) noexcept
{
    return lhs.titleId == rhs.titleId
        && lhs.id == rhs.id
        && lhs.when == rhs.when
        && lhs.timeToEarn == rhs.timeToEarn
        && lhs.metatags == rhs.metatags;
}


bool testCompare::operator !=(testCompare::achievement const & lhs, testCompare::achievement const & rhs) noexcept
{
    return !(lhs == rhs);
}


testCompare::achievement_diff::achievement_diff(testCompare::achievement const & lhs, testCompare::achievement const & rhs) noexcept
: diffs((lhs.titleId != rhs.titleId) << 0 |
        (lhs.id != rhs.id) << 1 |
        (lhs.when != rhs.when) << 2 |
        (lhs.timeToEarn != rhs.timeToEarn) << 3 |
        (lhs.metatags != rhs.metatags) << 4),
  metatags_diffs(lhs.metatags, rhs.metatags)            
{
}

/*
testCompare::achievement_diff testCompare::getDiff(testCompare::achievement const & lhs, testCompare::achievement const & rhs) noexcept
{
    return testCompare::achievement_diff {
        (lhs.titleId != rhs.titleId) << 0 |
        (lhs.id != rhs.id) << 1 |
        (lhs.when != rhs.when) << 2 |
        (lhs.timeToEarn != rhs.timeToEarn) << 3 |
        (lhs.metatags != rhs.metatags) << 4,
        testCompare::unordered_map_diff<std::string, std::string, buildIn_diff<std::string>> { lhs.metatags, rhs.metatags }
    };
}
*/
