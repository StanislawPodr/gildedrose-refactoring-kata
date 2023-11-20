#include "GildedRose.h"

GildedRose::GildedRose(::std::vector<Item> const &items) : items(items)
{
}

GildedRose::GildedRose(::std::vector<Item> &&items) : items(::std::move(items))
{
}
//Aged Brie
//Backstage passes to a TAFKAL80ETC concert
//Sulfuras, Hand of Ragnaros

void GildedRose::updateQuality()
{
    for (auto item : items)
    {
        if(item.name == "Aged Brie")
            agedBrie(item);
        else if(item.name == "Backstage passes to a TAFKAL80ETC concert")
            backstage(item);
        else if(item.name != "Sulfuras, Hand of Ragnaros")
            different(item);
    }
}

void GildedRose::agedBrie(Item &item)
{
    if (item.quality < 50)
        item.quality++;

    if (item.quality > 0)
        item.quality--;

    item.sellIn--;

    if (item.quality < 50 && item.sellIn < 0)
        item.quality++;
}

void GildedRose::different(Item &item)
{
    if (item.quality > 0)
        item.quality--;
    item.sellIn--;
    if (item.sellIn < 0)
        item.quality--;
}

void GildedRose::backstage(Item &item)
{
    if (item.sellIn > 0)
    {
        if (item.quality < 50)
        {
            item.quality++;
            if (item.sellIn < 11)
            {
                if (item.quality < 50)
                {
                    item.quality++;

                    if (item.sellIn < 6)
                    {
                        if (item.quality < 50)
                        {
                            item.quality++;
                        }
                    }
                }
            }
        }

        if (item.quality > 0)
            item.quality--;
        item.sellIn--;
    }
    else
    {
        item.sellIn--;
        item.quality = 0;
    }
}