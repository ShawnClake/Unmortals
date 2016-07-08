#pragma once

#include "Object.h"
#include <vector>

namespace sth {

	class Colliding {
	public:

		static bool pointInRectangle(const xyfVector & point, const Object * e) {

			//int pointCount = e->model.rect->getPointCount();

			std::vector<xyfVector> vertex;

			xyfVector p1, p2, p3, p4;

			xyzfVector pos;

			pos.x = e->model.rect->getPosition().x;
			pos.y = e->model.rect->getPosition().y;

			// top left
			p1.x = pos.x - (e->dimensions.x / 2);
			p1.y = pos.y - (e->dimensions.y / 2);

			// top right
			p2.x = pos.x + (e->dimensions.x / 2);
			p2.y = pos.y - (e->dimensions.y / 2);

			// bottom right
			p3.x = pos.x + (e->dimensions.x / 2);
			p3.y = pos.y + (e->dimensions.y / 2);

			// bottom left
			p4.x = pos.x - (e->dimensions.x / 2);
			p4.y = pos.y + (e->dimensions.y / 2);

			vertex.push_back(p1);
			vertex.push_back(p2);
			vertex.push_back(p3);
			vertex.push_back(p4);

			return pointInPolygon(point, vertex, 4);


		}

		/*static std::vector<xyzfVector> getPointVector(const Object * e, const int & count) {

			std::vector<xyzfVector> points;

			for (int i = 0; i < count; i++) {




			}


			return points;

		}*/




		// Copyright 2000 softSurfer, 2012 Dan Sunday
		// This code may be freely used and modified for any purpose
		// providing that this copyright notice is included with it.
		// SoftSurfer makes no warranty for this code, and cannot be held
		// liable for any real or imagined damage resulting from its use.
		// Users of this code must verify correctness for their application.
		// {
		static int isLeft(xyfVector P0, xyfVector P1, xyfVector P2) {
			return ((P1.x - P0.x) * (P2.y - P0.y)
				- (P2.x - P0.x) * (P1.y - P0.y));
		}

		static int pointInPolygon( xyfVector point, std::vector<xyfVector> vertex, int n ) {

			int wn = 0;

			for (int i = 0; i < n - 1; i++) {

				if (vertex[i].y <= point.y) {

					if (vertex[i + 1].y > point.y)
						if (isLeft(vertex[i], vertex[i + 1], point) > 0)
							++wn;

				}
				else {

					if (vertex[i + 1].y <= point.y)
						if (isLeft(vertex[i], vertex[i + 1], point) < 0)
							--wn;

				}

			}

			return wn;

		}

		// }



	};


}