#include <iostream>
#include "Entity.h"
#include "patrat.hpp"

Entity::Entity()
{
	this->length = 0;
	this->patrate;
}


void Entity::ADD_PATRAT()
{
	std::cin >> this->patrate[++this->length];
}

void Entity::ADD_PATRAT(Patrat p)
{
	patrate[this->length + 1] = p;
	this->length++;
}

void Entity::SHOW_ALL()
{
	std::cout << "\n";
	for (int i = 1; i <= this->length; i++)
		std::cout << "\033[36m" <<this->patrate[i] << "\033[m" <<std::endl;
}

int Entity::get_lenght()
{
	return this->length;
}

Patrat* Entity::get_patrate()
{
	return this->patrate;
}

Patrat Entity::BIGGEST_ENTITY()
{
	Patrat p;
	for (int i = 1; i <= this->length; i++)
		if (this->patrate[i].getLatura() > p.getLatura())
			p = this->patrate[i];
	return p;

}

Entity Entity::DIAL_ONE()
{
	Entity dial_one;
	for (int i = 1; i <= this->length; i++)
		if (this->patrate[i].getCentru().x > 0 && this->patrate[i].getCentru().y > 0)
			if (this->patrate[i].getLatura() / 2 <= this->patrate[i].getCentru().x)
				if (this->patrate[i].getLatura() / 2 <= this->patrate[i].getCentru().y)
					dial_one.ADD_PATRAT(this->patrate[i]);
	return dial_one;
}

Entity Entity::SEQUENCE()
{
	int start = 1, end = 0;
	Entity sequence;
	for (int i = 1; i < this->length; i++)
	{
		int j = i;
		while (this->get_patrate()[i].getLatura() == this->get_patrate()[j].getLatura())
			j++;
		if (j - i + 1 >= end - start + 1)
			end = j; start = i;
		i = j;
	}
	for (int i = start; i < end; i++)
	{
		sequence.ADD_PATRAT(this->patrate[i]);
	}
	return sequence;
}