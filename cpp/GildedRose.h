#include <string>
#include <vector>

class Item
{
public:
    ::std::string name;
    int sellIn;
    int quality;
    Item(::std::string name, int sellIn, int quality) : name(::std::move(name)), sellIn(sellIn), quality(quality)
    {}
};

class GildedRose
{
    void agedBrie(Item &item);
    void different(Item &item);
    void backstage(Item &item);

public:
    ::std::vector<Item> items;
    explicit GildedRose(::std::vector<Item> && items);
    explicit GildedRose(::std::vector<Item> const& items);

    void updateQuality();
};

