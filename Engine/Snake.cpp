#include "Snake.h"

Snake::Snake(const Location & loc)
{
	segments[0].initHead(loc);
}

void Snake::moveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)//decremnt i unitl we reach the head
	{
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].moveBy(delta_loc);
}

void Snake::grow()
{
	if (nSegments < nSegmentsMax)
	{
		++nSegments;
	}
}

void Snake::draw(Board & brd) const
{
	for (int i = 0; i < nSegments; ++i)
	{
		segments[i].draw(brd);
	}
}

void Snake::Segment::initHead(const Location & in_loc)
{
	loc = in_loc;
	c = Snake::HeadColor;
}

void Snake::Segment::initBody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::draw(Board & brd) const
{
}

void Snake::Segment::moveBy(const Location & delta_loc)
{
}

