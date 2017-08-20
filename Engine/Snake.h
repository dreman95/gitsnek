#pragma once
#include "Board.h"
#include <vector>

class Snake
{
private:

	class Segment
	{
	public:
		void initHead(const Location &in_loc);
		void initBody();
		void Follow(const Segment& next);
		void draw(Board& brd) const;
		void moveBy(const Location& delta_loc);
	
	private:
		Location loc;
		Color c;
	};
public:
	Snake(const Location& loc);
	void moveBy(const Location& delta_loc);
	void grow();
	void draw(Board& brd) const;
private:
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
	



};


